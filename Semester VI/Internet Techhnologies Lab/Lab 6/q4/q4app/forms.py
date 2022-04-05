from django import forms
from django.core.management.color import Style

companies =[('HP','HP'), ('Nokia','Nokia'), ('Samsung','Samsung'), ('Motorola','Motorola'), ('Apple','Apple')]
class Bill(forms.Form):
    CompanyName= forms.ChoiceField(widget=forms.RadioSelect,choices=companies)
    Mobile= forms.CharField(widget=forms.CheckboxInput)
    Laptop= forms.CharField(widget=forms.CheckboxInput)
    Quantity=forms.IntegerField()