from django.shortcuts import render
from .forms import CategoryForm,PageForm
from .models import Category,Page
# Create your views here.
def index(request):
    return render(request,'index.html')

def category(request):
    form1 = CategoryForm()
    form = CategoryForm(request.POST)
    if form.is_valid():
        name = form.cleaned_data["Name"]
        nov = form.cleaned_data["Number_Of_Visits"]
        nol = form.cleaned_data["Number_Of_Likes"]
        Category.objects.create(name = name, numberOfVisits = nov,numberOfLikes = nol)
    return render(request,'category.html',{"form":form1})

def page(request):
    form1 = PageForm()
    form = PageForm(request.POST)
    if form.is_valid():
        category = form.cleaned_data['Category']
        title = form.cleaned_data['Title']
        url = form.cleaned_data['Url']
        view = form.cleaned_data['View']
        Page.objects.create(category = category,title = title,url = url,view = view)
    return render(request,'page.html',{"form":form1})

def display(request):
    pages = Page.objects.all()
    categories = Category.objects.all()
    return render(request,'display.html',{"pages":pages,"categories":categories})