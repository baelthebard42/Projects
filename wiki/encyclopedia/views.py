from django.shortcuts import render
from markdown2 import Markdown
from . import util
from django import forms
from django.http import HttpResponseRedirect, HttpResponse
from django.urls import reverse
import random

markdowner = Markdown()


class NewPageForm(forms.Form):
    Title=forms.CharField(widget=forms.TextInput(attrs={'placeholder':'Enter title here'}))
    Content=forms.CharField(widget=forms.Textarea)

class AskTitle(forms.Form):
    Title=forms.CharField(widget=forms.TextInput(attrs={'placeholder':'Enter title of page you want to edit','style':'width:8cm'}))
 


def index(request):
    return render(request, "encyclopedia/index.html", {
        "entries": util.list_entries()
    })

def showCont(request,title): #displays contents
    page=util.get_entry(title) #accessing the page of the asked title
    if page!=None:
        NP=markdowner.convert(page) #converting the markdown version to HTML
        return render(request, "encyclopedia/contents.html",{
        "contents": NP,
        "title":title
    })
    else:
         return render(request, "encyclopedia/contents.html",{
        "contents": "We are so sorry. The content you searched for is not available",
        "title":"Entry not found"})

def newPage(request):
    return render(request, "encyclopedia/newPage.html",{
        "form":NewPageForm()
    })

def saving(request):
    if request.method=="POST":
        data=NewPageForm(request.POST)
        if data.is_valid():
            for names in util.list_entries(): #to check if there's already a name of that title
                if data.cleaned_data["Title"].capitalize()==names.capitalize():
                    return render (request, "encyclopedia/newPage.html",{
                        "message":"We are so sorry the title '"+data.cleaned_data["Title"]+"' is already taken. Please choose another title",
                        "form":NewPageForm(data.cleaned_data)
                    })
                    break

            util.save_entry(data.cleaned_data["Title"],data.cleaned_data["Content"])
            return render(request, "encyclopedia/newPage.html",{
            "form":NewPageForm()
            })

        else:
            return render (request, "encyclopedia/newPage.html",{
            "form":NewPageForm(data)
            })

    else:
        return render(request, "encyclopedia/newPage.html",{
        "form":NewPageForm()})



def SaveE(request):
    if request.method=="POST":
        save=request.POST
        util.save_entry(save["title"], save["content"])
        new=markdowner.convert(save["content"])
        return render(request, "encyclopedia/contents.html",{
            "contents":new,
            "title": save["title"] 
        })


def randomPage(request):
    count=1
    Entries=util.list_entries()
    Numb=len(Entries)
    rand=random.randint(1,Numb)
    for names in Entries:
        if count==rand:
             page=util.get_entry(names) 
             NP=markdowner.convert(page) 
             return render(request, "encyclopedia/contents.html",{
                "contents": NP,
                "title":names})
        count=count+1    




def search(request):
    asked=request.POST["q"]
    if request.method=="POST":
        page=util.get_entry(asked) 
        if page != None:
            NP=markdowner.convert(page) #converting the markdown version to HTML
            return render(request, "encyclopedia/contents.html",{
               "contents": NP,
               "title":asked})

        else:
             Entries=util.list_entries()
             Recommendations=[]
             for entry in Entries:
                if asked.capitalize() in entry.capitalize():
                     Recommendations.append(entry)
             return render(request, "encyclopedia/searchresults.html",{
             "title":asked,
             "results":Recommendations
              })
                

def edit(request):
    if request.method=="POST":
        title=request.POST["entry_title"]
        content=util.get_entry(title)
        return render(request, "encyclopedia/editPage.html",{
            "title":title,
            "content":content
        })


    
  
   



   

