from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.
def home(request):
    return render(request, 'home.html', {})

def metadata(request):
    return render(request, 'metadata.html', {})

def reviews(request):
    return render(request, 'reviews.html', {})

def publisherinfo(request):
    return render(request, 'publisherinfo.html', {})