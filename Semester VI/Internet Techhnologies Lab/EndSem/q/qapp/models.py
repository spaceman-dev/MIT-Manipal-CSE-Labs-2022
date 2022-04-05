from django.db import models

# Create your models here.
class Student(models.Model):
    Name = models.CharField(max_length=100)
    RegNo = models.IntegerField(max_length=20)
    CGPA = models.FloatField()
    def _str_(self):
        return self.student+" "+self.CGPA