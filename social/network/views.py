from django.contrib.auth import authenticate, login, logout
from django.db import IntegrityError
from django.http import HttpResponse, HttpResponseRedirect
from django.shortcuts import render
from django.urls import reverse
from .models import User, post, Follow, Likes
from datetime import datetime
from django.contrib.auth.decorators import login_required
from django.http import JsonResponse
import json
from django.views.decorators.csrf import csrf_exempt
from django.core.exceptions import ObjectDoesNotExist
from django.core.paginator import Paginator

def index(request):
    return render(request, "network/index.html")


def login_view(request):
    if request.method == "POST":

        # Attempt to sign user in
        username = request.POST["username"]
        password = request.POST["password"]
        user = authenticate(request, username=username, password=password)

        # Check if authentication successful
        if user is not None:
            login(request, user)
            return HttpResponseRedirect(reverse("index"))
        else:
            return render(request, "network/login.html", {
                "message": "Invalid username and/or password."
            })
    else:
        return render(request, "network/login.html")


def logout_view(request):
    logout(request)
    return HttpResponseRedirect(reverse("index"))


def register(request):
    if request.method == "POST":
        username = request.POST["username"]
        email = request.POST["email"]

        # Ensure password matches confirmation
        password = request.POST["password"]
        confirmation = request.POST["confirmation"]
        if password != confirmation:
            return render(request, "network/register.html", {
                "message": "Passwords must match."
            })

        # Attempt to create new user
        try:
            user = User.objects.create_user(username, email, password)
            user.save()
        except IntegrityError:
            return render(request, "network/register.html", {
                "message": "Username already taken."
            })
        login(request, user)
        return HttpResponseRedirect(reverse("index"))
    else:
        return render(request, "network/register.html")

@login_required
def newPost(request):
    if request.method=='POST':
        user=request.user
        content=request.POST['content']
        newPost=post(op=user, content=content, date=datetime.now())
        newPost.save()
        return HttpResponseRedirect(reverse("profile", kwargs={'id':request.user.id}))

def allPosts(request, typee):
    if (typee=='all'):
     ultoPosts=post.objects.all()
    

    
    elif(typee=='following'):
     followed=Follow.objects.filter(follower=request.user)
     posts=post.objects.all()
     ultoPosts=[]
     for one in posts:
        for person in followed:
            if one.op==person.user:
                ultoPosts.append(one)
      
    

    else:
        return HttpResponse("Error! Page doesn't exist ")

    TotalLikes=Likes.objects.all()
    likedPosts=[]
    for like in TotalLikes:
        if like.liker==request.user:
            likedPosts.append(like.likedPost.id)

    posts=list(reversed(ultoPosts))
    paginator=Paginator(posts, 10)
    page_number=request.GET.get('page')
    page_obj=paginator.get_page(page_number)
    return render (request, "network/index.html",{
        "posts":posts,
        "page_obj":page_obj,
        "likedPosts":likedPosts
        
    })

@csrf_exempt
@login_required
def editPost(request, id):
   if (request.method=='PUT'):
    data=json.loads(request.body)
    content=data.get('content')
    
    newPost=post.objects.get(id=id)

    if (request.user!=newPost.op):
        return HttpResponse('Error! You are not authorized to edit')

    newPost.content=content
    newPost.save()
    return JsonResponse({"message":"Data sent sucessfully"}, status=201)






def showPost(request, id):
   try:
    tdPost=post.objects.filter(id=id)
   except tdPost.DoesNotExist:
    return JsonResponse({"error": "Post not found."}, status=404)
   
   if(request.method=='GET'):
    return JsonResponse(tdPost.serialize())

   else:
     return JsonResponse({'error': 'POST method required'}, status=201)

@login_required
def profile(request, id):
    user=User.objects.get(id=id)
    ultoPosts=post.objects.filter(op=user)
    followers=(Follow.objects.filter(user=user))
    following=(Follow.objects.filter(follower=user))
    
    TotalLikes=Likes.objects.all()
    likedPosts=[]
    for like in TotalLikes:
        if like.liker==request.user:
            likedPosts.append(like.likedPost.id)
    
    checkFollow=Follow.objects.filter(user=user, follower=request.user)

    if len(checkFollow) !=0 :
      follows=False

    else:
        follows=True
     
    posts=list(reversed(ultoPosts))
    paginator=Paginator(posts, 10)
    page_number=request.GET.get('page')
    page_obj=paginator.get_page(page_number)
    return render (request, "network/profile.html",{
        "posts":page_obj,
        "account": user,
        "followers": len(followers),
        "following": len(following),
        "follows": follows,
        "likedPosts":likedPosts
        })

@csrf_exempt
def follow(request, followOrNot):
 if request.method=='POST':
    follower_id=request.user.id
    following_id=request.POST['following_id']
    followOrNot=followOrNot
    
    try:
     followed=User.objects.get(id=following_id)
     follower=User.objects.get(id=follower_id)
    except User.DoesNotExist:
     return HttpResponse('User does not exist')
    
    if (followOrNot=='yes'):
     obj=Follow(follower=follower, user=followed)
     obj.save()
     return HttpResponseRedirect(reverse('profile', args=(following_id)))
    else:
     obj=Follow.objects.filter(follower=follower, user=followed)
     obj.delete()
     return HttpResponseRedirect(reverse('profile', args=(following_id)))

@csrf_exempt
def like(request):
    user=request.user
    data=json.loads(request.body)
    postId=data.get('postId')
    likedPost=post.objects.get(id=postId)

    obj=Likes(liker=user, likedPost=likedPost)
    obj.save()

    if likedPost.likesCount is None:
     likedPost.likesCount=0
     likedPost.likesCount+=1
     likedPost.save()

    else:
     likedPost.likesCount+=1
     likedPost.save()


    return JsonResponse({'message': likedPost.serialize() }, status=200)

@csrf_exempt
def unlike(request):
    user=request.user
    data=json.loads(request.body)
    postId=data.get('postId')
    likedPost=post.objects.get(id=postId)

    obj=Likes.objects.filter(liker=user, likedPost=likedPost)
    obj.delete()

    likedPost.likesCount-=1
    likedPost.save()


    return JsonResponse({'message': likedPost.serialize() }, status=200)
    
       