from django.urls import path

from . import views

urlpatterns = [
    path("", views.index, name="index"),
    path("login", views.login_view, name="login"),
    path("logout", views.logout_view, name="logout"),
    path("register", views.register, name="register"),
    path("create_listings", views.createlist, name="create"),
    path("listings/<int:count>",views.displayList, name="dislist"),
    path("category",views.category, name="category"),
    path("category/<str:typeC>", views.categories, name="categories"),
    path("watchlists",views.addWatchlist, name="watchlists"),
    path("remWatchlists",views.remWatchlists, name="rWatch"),
    path("displayWatch",views.displayWatch,name="diswatch"),
    path("addBid",views.addBid, name="addBid"),
    path("closeBid",views.closeBid, name="closeBid"),
    path("addComment",views.addComment, name="comment")

]
