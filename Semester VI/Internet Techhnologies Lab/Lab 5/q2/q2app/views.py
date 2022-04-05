from django.shortcuts import render
from django.http import HttpResponse
# Create your views here.
def index(request):
    return render(request,'base.html')
def eligible(request):
    date = request.GET['doj']
    n = int(date[:4])
    if (2021-n > 5):
        return render(request, 'eligible.html', {'eligible': "Yes"})
    else:
        return render(request,'eligible.html',{"eligible": "nope, you are behind! Try again next year lol!"})