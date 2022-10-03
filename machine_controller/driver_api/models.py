from django.db import models


class Param(models.Model):
    id = models.AutoField(primary_key=True)
    param_id = models.IntegerField(unique=True) 
    index = models.IntegerField(default=1)
    label = models.CharField(max_length=300)
    value = models.IntegerField(default=0)
    timestamp = models.DateTimeField(auto_now_add=True)
