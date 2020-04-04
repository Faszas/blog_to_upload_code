from django.urls import path
from . import views

app_name = 'blog'

urlpatterns = [
    path('', views.IndexView.as_view(), name='index'),
    path('upload/', views.UploadView.as_view(), name='upload'),
    path('post/', views.UploadView.as_view(), name='post'),
    path('login/', views.LoginView.as_view(), name = 'login'),
    path('about/', views.AboutView, name='about'),
    path('services/', views.AboutView, name='services'),
    path('contact/', views.AboutView, name='contact'),
    path('detail/<uuid:pk>/', views.DetailView.as_view(), name='detail'),
    path('<str:name>/list/', views.ListView.as_view(), name='list'),
    path("gallery/", views.GalleryView.as_view(), name='gallery')
]
