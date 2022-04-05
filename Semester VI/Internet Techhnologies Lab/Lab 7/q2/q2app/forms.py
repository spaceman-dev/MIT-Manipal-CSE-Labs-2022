from django import forms

class Employee(forms.Form):
    Name = forms.CharField(max_length=100)
    Company = forms.CharField(max_length=200)
    Salary = forms.IntegerField()
    Street = forms.CharField(max_length=500)
    City = forms.CharField(max_length=100)

class Company(forms.Form):
    company = forms.CharField(max_length=200)