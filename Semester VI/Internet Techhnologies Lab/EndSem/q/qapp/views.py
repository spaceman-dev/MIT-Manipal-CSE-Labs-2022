from django.http import request
from django.shortcuts import render
from .forms import SearchForm
from .models import Student
# Create your views here.

def about(request):
    form = SearchForm()
    form1 = SearchForm(request.POST)
    if form1.is_valid():
        RegNo = form1.cleaned_data["RegNo"]
        student = Student.objects.get(RegNo = RegNo)
        return render(request, "about.html", {"student": student, "form": form1})
    else:
        return render(request, "about.html", {"form": form})
def allstudents(request):
    form = SearchForm()
    form1 = SearchForm(request.POST)
    if form1.is_valid():
        RegNo = form1.cleaned_data["RegNo"]
        student = Student.objects.get(RegNo = RegNo)
        return render(request, "about.html", {"student": student, "form": form1})
    students = Student.objects.all()
    return render(request, "allstudents.html", {"Students": students, "form": form})