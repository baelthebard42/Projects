from django.contrib.auth import authenticate, login, logout
from django.db import IntegrityError
from django.http import HttpResponse, HttpResponseRedirect
from django.shortcuts import render
from django.urls import reverse
from .models import User, listings, bidding, comments
from datetime import date


def index(request):
    return render(request, "auctions/index.html",{
        "lists":listings.objects.filter(activity=True)
    })



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
            return render(request, "auctions/login.html", {
                "message": "Invalid username and/or password."
            })
    else:
        return render(request, "auctions/login.html")


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
            return render(request, "auctions/register.html", {
                "message": "Passwords must match."
            })

        # Attempt to create new user
        try:
            user = User.objects.create_user(username, email, password)
            user.save()
        except IntegrityError:
            return render(request, "auctions/register.html", {
                "message": "Username already taken."
            })
        login(request, user)
        return HttpResponseRedirect(reverse("index"))
    else:
        return render(request, "auctions/register.html")


def createlist(request):
    user=request.user
    if request.method=="POST":
      title=request.POST["title"]
      description=request.POST["description"]
      startingbid=request.POST["stbid"]
      category=request.POST["category"]
      url=request.POST["url"]
      created_listing=listings(title=title,description=description,stbid=startingbid,category=category,imgurl=url,date=date.today(),creator=user)
      created_listing.save()
      return render(request,"auctions/createlisting.html",{
        "message":"Auction added sucessfully !!"
        })

    else:
       return render(request,"auctions/createlisting.html")

def displayList(request, count):
   i=listings.objects.get(id=count)
   ListComments=comments.objects.filter(onwhat=i)
   every=bidding.objects.filter(obj=i)
   if every is not None:
    winningBid=every.last()
   else:
    winner="Nobody bought this"
   islistinginwatchlist=request.user in i.watchlist.all()
   return render(request, "auctions/displayList.html",{
            "list": i,
            "bidlist":every,
            "comments":ListComments,
            "islistinginwatchlist":islistinginwatchlist,
            "winner":winningBid
          })

def category(request):
    return render(request,"auctions/category.html")

def categories(request,typeC):
    if typeC=="All":
        return render(request,"auctions/index.html",{
            "lists":listings.objects.filter(activity=True)
        })
    else:
         return render(request,"auctions/categories.html",{
        "list":listings.objects.filter(category=typeC, activity=True),
         })

def addWatchlist(request):
     user=request.user
     if request.method=="POST":
        iid=request.POST["id"]
        maal=listings.objects.get(id=iid)
        maal.watchlist.add(user)
        return HttpResponseRedirect(reverse('dislist', args=[iid]))

def displayWatch(request):
    user=request.user
    return render(request, "auctions/displayWatch.html",{
        "list":user.cart.all()
    })

def addBid(request):
    user=request.user
    if request.method=="POST":
        iid=request.POST["id"]
        bidvalue=request.POST["bidvalue"]
        listed=listings.objects.get(id=iid)
        every=bidding.objects.filter(obj=listed) #getting the bidding objects who only have the selected object
        if every is not None:
         for i in every:
           if int(bidvalue)<=i.bid:
             return render(request, "auctions/displayList.html",{
                "list":listed,
                "message": "Please enter a bid higher than the current bid",
                "bidlist": every,
                "comments":comments.objects.filter(onwhat=listed)
            })
        new_bid=bidding(player=user, bid=bidvalue, obj=listed)
        new_bid.save()
        return HttpResponseRedirect(reverse("dislist",args=[iid]))

def closeBid(request):
    user=request.user
    if request.method=="POST":
        CloseName=request.POST["closeTitle"]
        ActualClosing=listings.objects.get(title=CloseName)
        bidWinner=bidding.objects.filter(obj=ActualClosing).last()
        ActualClosing.activity=False
        ActualClosing.save()
        return render(request, "auctions/forClosed.html",{
            "remover":user,
            "MessageUser": f"Listing {CloseName} removed sucessfully !!",
            "lists":listings.objects.all()
        })

def addComment(request):
    if request.method=="POST":
        commenter=request.POST["commenter"]
        comment=request.POST["content"]
        commenter_object=User.objects.get(username=commenter)
        listId=int(request.POST["saman"])
        listObj=listings.objects.get(id=listId)
        new_comment=comments(commentor=commenter_object, comment=comment, onwhat=listObj )
        new_comment.save()
        return HttpResponseRedirect(reverse("dislist",args=[listId]))

def remWatchlists(request):
     user=request.user
     if request.method=="POST":
        iid=request.POST["iid"]
        maal=listings.objects.get(id=iid)
        maal.watchlist.remove(user)
        return HttpResponseRedirect(reverse('dislist', args=[iid]))
        
        
        


      