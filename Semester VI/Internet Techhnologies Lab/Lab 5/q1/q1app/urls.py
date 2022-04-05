from django.urls import path
from q1app import views

urlpatterns = [
    path('', views.q1_view, name='q1_view'),
]