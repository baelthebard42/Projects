from django.contrib.auth.models import AbstractUser
from django.db import models


class User(AbstractUser, models.Model):
 pass

class post(models.Model):
    op=models.ForeignKey(User, on_delete=models.CASCADE, related_name='poster')
    content=models.CharField(max_length=500 )
    date=models.CharField(max_length=10)
    likesCount=models.IntegerField( null=True, default=0)

    def serialize(self):
           return {
            "id": self.id,
            "op": self.op.username,
            "date":self.date,
            "content":self.content,
            "likesCount":self.likesCount
                  }

class Follow(models.Model):
    follower=models.ForeignKey(User,on_delete=models.CASCADE, null=True, blank=True, related_name='whoIsFollowing')
    user=models.ForeignKey(User, on_delete=models.CASCADE, null=True, blank=True, related_name='beingFollowed')
    
class Likes(models.Model):
    id = models.AutoField(primary_key=True)
    liker=models.ForeignKey(User, on_delete=models.CASCADE, related_name='reacter')
    likedPost=models.ForeignKey(post, on_delete=models.CASCADE, related_name='gudpost')
    
