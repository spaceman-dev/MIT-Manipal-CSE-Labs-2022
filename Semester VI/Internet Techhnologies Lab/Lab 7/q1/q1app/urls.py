from django.urls import path
from . import views

urlpatterns = [
    path('',views.index,name="index"),
    path('category',views.category,name="category"),
    path('page',views.page,name = "page"),
    path('display',views.display,name="display")
]