from django.contrib.auth.models import AbstractUser
from django.db import models
from django.core.validators import MinValueValidator


class User(AbstractUser):
 
 

 def __str__(self):
    return f"{self.username}"


class listings(models.Model):
    title=models.CharField(max_length=64)
    description=models.CharField(max_length=1000)
    stbid=models.IntegerField()
    category=models.CharField(max_length=15)
    imgurl=models.URLField(blank=True)
    date=models.CharField(max_length=10, default="Date not found")
    creator=models.ForeignKey(User, on_delete=models.CASCADE, related_name="user")
    watchlist=models.ManyToManyField(User, blank=True, null=True, related_name="cart")
    activity=models.BooleanField(default=True)
    

class bidding(models.Model):
    player=models.ForeignKey(User, on_delete=models.CASCADE, related_name="juwade")
    bid=models.IntegerField()
    obj=models.ForeignKey(listings, on_delete=models.CASCADE, related_name="saman")
    
class comments(models.Model):
    commentor=models.ForeignKey(User, on_delete=models.CASCADE, related_name="bolne")
    comment=models.CharField(max_length=500)
    onwhat=models.ForeignKey( listings, on_delete=models.CASCADE, related_name="sunne" )
    









