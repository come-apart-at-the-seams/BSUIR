# Generated by Django 3.2.7 on 2021-09-24 12:42

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('polls', '0009_auto_20210922_1224'),
    ]

    operations = [
        migrations.AlterModelOptions(
            name='last_messages',
            options={'ordering': ['-date'], 'verbose_name': 'Last Message'},
        ),
        migrations.AlterModelOptions(
            name='last_news',
            options={'ordering': ['-date'], 'verbose_name_plural': 'Last News'},
        ),
        migrations.AlterField(
            model_name='last_messages',
            name='profile',
            field=models.OneToOneField(help_text='profile', on_delete=django.db.models.deletion.CASCADE, primary_key=True, serialize=False, to='polls.profiles', verbose_name='profile'),
        ),
    ]