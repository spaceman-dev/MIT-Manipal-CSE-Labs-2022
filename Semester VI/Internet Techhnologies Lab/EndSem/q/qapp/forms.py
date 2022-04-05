from django import forms

class SearchForm(forms.Form):
    RegNo = forms.IntegerField(widget=forms.TextInput(),label="Registration Number")