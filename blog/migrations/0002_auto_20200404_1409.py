# Generated by Django 3.0.5 on 2020-04-04 07:09

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('blog', '0001_initial'),
    ]

    operations = [
        migrations.AlterField(
            model_name='code',
            name='title',
            field=models.CharField(max_length=255),
        ),
    ]
