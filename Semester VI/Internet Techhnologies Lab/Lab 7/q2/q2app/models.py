from django.db import models
from django.db.models.fields.related import ForeignKey

class Works(models.Model):
    Name = models.CharField(max_length=100)
    Company = models.CharField(max_length=200)
    Salary = models.IntegerField()

class Lives(models.Model):
    Name = models.CharField(max_length=100)
    Street = models.CharField(max_length=500)
    City = models.CharField(max_length=100)