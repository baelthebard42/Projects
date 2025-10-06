
from django.urls import path

from . import views

urlpatterns = [
    path("", views.index, name="index"),
    path("login", views.login_view, name="login"),
    path("logout", views.logout_view, name="logout"),
    path("register", views.register, name="register"),
    path('newPost', views.newPost, name='newPost'),
    path('allPosts/<str:typee>', views.allPosts, name='allPosts'),
    path('editPost/<int:id>', views.editPost, name='editPost'),
    path('showPost/<int:id>', views.showPost, name='showPost'),
    path('profile/<int:id>', views.profile, name='profile'),
    path('follow/<str:followOrNot>', views.follow, name='follow'),
    path('like', views.like, name='like'),
    path('unlike', views.unlike, name='unlike')
   
]
