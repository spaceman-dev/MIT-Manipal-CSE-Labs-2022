from django.urls import path
from . import views
urlpatterns = [
    path('',views.index,name="index"),
    path('portal',views.portal,name="portal"),
    path('search',views.search,name="search")
]