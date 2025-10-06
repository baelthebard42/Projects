from django.contrib import admin
from .models import User, post, Follow, Likes

# Register your models here.

admin.site.register(User)
admin.site.register(post)
admin.site.register(Follow)
admin.site.register(Likes)
