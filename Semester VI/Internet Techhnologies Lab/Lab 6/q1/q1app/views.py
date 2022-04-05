from django.shortcuts import render
from django.http import HttpResponse
from .forms import ManuFactForm
# Create your views here.
def submit(request):
    form = ManuFactForm(request.POST or None)
    ManuName=''
    Model=''
    if request.method == 'POST':
        FinalForm= ManuFactForm(request.POST)
        if FinalForm.is_valid():
            ManuName=FinalForm.cleaned_data['Manufacturer']
            Model=FinalForm.cleaned_data['ModelName']
    context = {'ManuName':ManuName, 'Model':Model, 'form':form}
    return render(request,'result.html', context)
def index(request):
    form = ManuFactForm(request.POST or None)
    context = {'form':form}
    return render(request,'index.html', context)
def result(request):
    return render(request,'result.html')