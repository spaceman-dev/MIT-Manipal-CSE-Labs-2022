from django import forms
from django.core.management.color import Style

CHOICES=[('BMW', 'BMW'), ('Toyata', 'Toyata'), ('Fiat', 'Fiat'), ('Audi', 'Audi'), ('Ferrari', 'Ferrari'), ('Mercedes', 'Mercedes')]

class ManuFactForm(forms.Form):
    Manufacturer = forms.ChoiceField(choices=CHOICES)
    ModelName = forms.CharField()