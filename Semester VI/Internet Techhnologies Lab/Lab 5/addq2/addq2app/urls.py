from django.urls import path

from . import views

urlpatterns = [
    path('', views.home, name='home'),
    path('metadata', views.metadata, name='metadata'),
    path('reviews', views.reviews, name='reviews'),
    path('publisherinfo', views.publisherinfo, name='publisherinfo')
]