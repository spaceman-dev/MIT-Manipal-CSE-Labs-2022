from django.forms.widgets import EmailInput
from django.shortcuts import render
from django.http import HttpResponse
from .forms import Login
# Create your views here.
def submit(request):
    form = Login(request.POST or None)
    if request.method =='POST':
        res = Login(request.POST)
        if res.is_valid():
            Username=res.cleaned_data['Username']
            Email=res.cleaned_data['Email']
            ContactNumber=res.cleaned_data['ContactNumber']
    else:
        res=Login()
    context={"Username":Username,"Email":Email,"ContactNumber":ContactNumber}
    return render(request,'success.html',context)
def index(request):
    form = Login(request.POST or None)
    context={'form':form}
    return render(request,'index.html',context)
def success(request):
    return render(request,'success.html')
