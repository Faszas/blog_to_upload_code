# Generated by Django 3.0.5 on 2020-04-04 07:55

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('blog', '0003_auto_20200404_1453'),
    ]

    operations = [
        migrations.RenameField(
            model_name='code',
            old_name='id',
            new_name='post_id',
        ),
    ]
