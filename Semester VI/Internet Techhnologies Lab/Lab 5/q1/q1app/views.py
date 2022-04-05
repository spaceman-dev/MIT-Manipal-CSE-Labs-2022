from django.shortcuts import render

def q1_view(request):
    return render(request, 'base.html', {})