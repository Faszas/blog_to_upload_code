from django.shortcuts import render
from django.views import View
from django.http import HttpResponse
from .models import CODE, Python, Cplusplus
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.mixins import LoginRequiredMixin
import os

dic = {'python': Python, 'c++': Cplusplus}

# Create your views here.

class IndexView(View):
    def get(self, request):
        if request.GET.get('search') is not None:
            obj = CODE.objects.all().filter(title__contains = request.GET.get('search'))
            return render(request, 'index.html', {'obj': obj})
        return render(request, 'index.html')

class ListView(View):
    def get(self, request, name):
        try:
            obj = dic[name].objects.all()
            return render(request, 'listview.html', {"obj": obj})
        except:
            return HttpResponse("not valid")


class DetailView(View):
    def get(self, request, pk):
        obj = CODE.objects.get(post_id = pk)
        code = ""
        try:
            with open("media/" + str(obj.file), 'r') as f:
                code = f.read()
        except:
            pass
        return render(request, 'detail.html', {'obj': obj, 'code': code})


class PostView(LoginRequiredMixin, View):
    login_url = "/login/"

    def get(self, request):
        return render(request, 'post.html')

class UploadView(LoginRequiredMixin, View):

    login_url = "/login/"
    def get(self, request):
        return render(request, 'upload.html')

    def post(self, request):
        global dic
        try:
            title = request.POST.get('title')
            author = request.POST.get('author')
            description = request.POST.get('description')
            file = request.FILES['file']
            type = request.POST.get('select')

            dic[type].objects.create(title = title, file = file, author = author, description = description).save()
            return HttpResponse("success")
        except:
            return HttpResponse("not valid")



class LoginView(View):

    def get(self, request):
        logout(request)
        return render(request, 'login.html')

    def post(self, request):
        if request.method == "POST":
            username = request.POST.get('username')
            password = request.POST.get('password')
            user = authenticate(username=username, password=password)
            if user is None:
                return HttpResponse("Not valid")
            login(request, user)
            return HttpResponse("You have sign in successfully")

class GalleryView(View):

    def get(self, request):

        temp = [str(x) for x in range(1, 17)]

        return render(request, 'gallery.html', {'obj': temp})


def AboutView(request):
    return render(request, 'about.html')

def ServicesView(request):
    return render(request, 'services.html')

def ContactView(request):
    return render(request, 'contact.html')