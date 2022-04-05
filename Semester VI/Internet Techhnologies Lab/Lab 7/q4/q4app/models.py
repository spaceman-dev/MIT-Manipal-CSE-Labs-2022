from django.db import models

# Create your models here.
class Product(models.Model):
    Title = models.CharField(max_length=200)
    Price = models.IntegerField()
    Description = models.TextField()