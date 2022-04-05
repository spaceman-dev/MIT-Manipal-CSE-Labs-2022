from django.shortcuts import render
from .forms import ProductForm
from .models import Product
# Create your views here.

def index(request):
    return render(request,'index.html')

def entry(request):
    form1 = ProductForm(request.POST)
    form = ProductForm()
    if form1.is_valid():
        Title = form1.cleaned_data['Title']
        Price = form1.cleaned_data['Price']
        Description = form1.cleaned_data['Description']
        Product.objects.create(Title = Title,Price = Price,Description = Description)
    return render(request,'entry.html',{"form":form})

def view(request):
    products = Product.objects.all()
    return render(request,'view.html',{"products":products})