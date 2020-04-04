from django.contrib import admin

# Register your models here.
from .models import CODE, Python, Cplusplus

admin.site.register(CODE)
admin.site.register(Python)
admin.site.register(Cplusplus)
