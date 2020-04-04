from django.db import models
import uuid

# Create your models here.

class CODE(models.Model):
    post_id = models.UUIDField(primary_key = True, default = uuid.uuid4, editable = False)
    title = models.CharField(max_length = 255, blank = False, null = False)
    author = models.CharField(max_length = 50, blank = False, null = False, default = "Xuan Hung")
    description = models.TextField(blank = True, null = True)
    file = models.FileField(upload_to = 'code/', blank = False, null = False)
    uploaded_at = models.DateTimeField(auto_now_add = True)

    def __str__(self):
        return str(self.post_id)

    def get_absoulute(self):
        return "/media/code/"

class Python(CODE):
    def __str__(self):
        return str(self.post_id)

class Cplusplus(CODE):
    def __str__(self):
        return str(self.post_id)
