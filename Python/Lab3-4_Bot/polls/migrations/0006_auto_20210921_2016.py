# Generated by Django 3.2.7 on 2021-09-21 17:16

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('polls', '0005_auto_20210921_1628'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='added_subs',
            name='pr_topic_subs',
        ),
        migrations.AddField(
            model_name='added_subs',
            name='desire_to_subscribe',
            field=models.ForeignKey(help_text='desire_to_subscribe', null=True, on_delete=django.db.models.deletion.CASCADE, to='polls.topics', verbose_name='desire_to_subscribe'),
        ),
        migrations.AlterField(
            model_name='added_subs',
            name='profile',
            field=models.ForeignKey(help_text='Telegram chat id', null=True, on_delete=django.db.models.deletion.CASCADE, to='polls.profiles', verbose_name='Person chatID'),
        ),
        migrations.DeleteModel(
            name='Subs_Profile_Topic',
        ),
    ]