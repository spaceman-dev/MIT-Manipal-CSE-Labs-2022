from django.shortcuts import render
from .models import Works,Lives
from .forms import Employee,Company

def index(request):
    return render(request,'index.html')

def portal(request):
    form = Employee()
    form1 = Employee(request.POST)
    if form1.is_valid():
        Name = form1.cleaned_data['Name']
        Company = form1.cleaned_data['Company']
        Salary = form1.cleaned_data['Salary']
        Street = form1.cleaned_data['Street']
        City = form1.cleaned_data['City']
        Works.objects.create(Name=Name,Company=Company,Salary=Salary)
        Lives.objects.create(Name=Name,Street=Street,City=City)
    return render(request,'portal.html',{"form":form})

def search(request):
    form = Company()
    form1 = Company(request.POST)
    if form1.is_valid():
        company = form1.cleaned_data["company"]
        employall = Works.objects.all().filter(Company = company)
        employees = []
        for e in employall:
            employees.append(Lives.objects.get(Name = e.Name))
        return render(request,"search.html",{"form":form1,"employees":employees})
    return render(request,"search.html",{"form":form})