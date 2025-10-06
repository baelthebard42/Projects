from django.contrib import admin
from .models import User, listings, bidding, comments

# Register your models here.
admin.site.register(User)
admin.site.register(listings)
admin.site.register(bidding)
admin.site.register(comments)

