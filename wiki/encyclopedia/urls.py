from django.urls import path

from . import views

urlpatterns = [
    path("", views.index, name="index"),
    path("/<str:title>", views.showCont, name="show"),
    path("/menu/newPage",views.newPage, name="newP"),
    path("/action/save",views.saving, name="save"),
    path("/menu/random",views.randomPage,name="random"),
    path("/action/search",views.search,name="search"),
    path("/action/saveEdit",views.SaveE,name="saveE"),
    path("/action/edit",views.edit,name="edit")
]
