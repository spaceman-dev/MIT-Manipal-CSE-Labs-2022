from django import forms

class ProductForm(forms.Form):
    Title = forms.CharField(max_length=100)
    Price = forms.IntegerField()
    Description = forms.CharField(widget=forms.Textarea(),label="Description")