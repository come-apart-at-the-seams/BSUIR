from django.db import models


class Topics(models.Model):
    url = models.CharField(
        max_length=250,
        verbose_name="Url",
        primary_key=True,
        )

    name = models.TextField(
        verbose_name="Topic name",
        null=True,
        )

    # added_subs = models.ForeignKey(
    #     'Added_Subs',
    #     verbose_name="added_subs",
    #     on_delete=models.CASCADE,
    #     null=True,
    # )

    # profiles = models.ManyToManyField(profiles, verbose_name="Topic subscriptions profiles", on_delete=models.SET_NULL, null=True)
    # last_news = models.TextField(
    #     verbose_name="last news")
    #
    # last_news_date = models.DateTimeField(
    #     verbose_name="last news date")

    subs = models.ManyToManyField(
        'Profiles',
        verbose_name="Topic subscriptions profiles",
        null=True)

    topic_last_news = models.ManyToManyField(
        'Last_News',
        verbose_name="Topic Last News",
        null=True,
    )

    def __str__(self):
        return str(self.name)


    class Meta:
        ordering = ["name"]
        verbose_name = "Topic"



class Profiles(models.Model):
    tg_id = models.PositiveIntegerField(
        verbose_name="Person chatID",
        help_text="Telegram chat id",
        primary_key=True,
    )

    name = models.TextField(
        verbose_name="Person name",
        help_text="Telegram person name",
        null=True,
    )


    reg_date = models.DateTimeField(
        auto_now_add=True,
        verbose_name="Registration date",
        )

    subscriptions = models.ManyToManyField(
        Topics,
        verbose_name="Topic subscriptions",

    )
    is_admin = models.BooleanField(
        verbose_name='is admin?',
        help_text="is admin?",
        null=True
    )

    def __str__(self):
        s = str(self.name) + ' ' + str(self.reg_date)
        return s

    class Meta:
        ordering = ["-reg_date"]
        verbose_name = "Profile"


class Added_Subs(models.Model):
    profile = models.ForeignKey(
        Profiles,
        verbose_name="Person chatID",
        help_text="Telegram chat id",
        null=True,
        on_delete=models.CASCADE,
    )

    desire_to_subscribe = models.ForeignKey(
        Topics,
        verbose_name="desire_to_subscribe",
        help_text="desire_to_subscribe",
        null=True,
        on_delete=models.CASCADE,
    )

    # pr_topic_subs = models.ManyToManyField(
    #     'Subs_Profile_Topic',
    #     verbose_name="pr_topic_subs",
    #     help_text="pr_topic_subs",
    #     null=True,
    # )

    def __str__(self):
        s = str(self.profile) + ' ' + str(self.desire_to_subscribe)
        return s


    class Meta:
        ordering = ["profile"]
        verbose_name = "Added subtopic"



class Last_News(models.Model):
    url = models.CharField(
        max_length=250,
        verbose_name="Url",
        primary_key=True,
    )
    topic = models.ManyToManyField(
        Topics,
        verbose_name="Topic",
        help_text="Topic. Last news",
    )
    text = models.TextField(
        verbose_name="text",
        help_text="last news text",
        null=True,
    )
    date = models.DateTimeField(
        verbose_name="date",
        null=True,
    )
    is_sent_to_everyone = models.BooleanField(
        verbose_name='is sent to everyone?',
        help_text="Has the news been sent to everyone?",
        null=True
    )

    def __str__(self):
        s = str(self.text)
        return s

    class Meta:
        ordering = ["-date"]
        verbose_name_plural = "Last News"



class Last_Messages(models.Model):
    profile = models.OneToOneField(
        Profiles,
        verbose_name="profile",
        help_text="profile",
        on_delete=models.CASCADE,
        primary_key=True,
    )
    message_text = models.TextField(
        verbose_name="text",
        help_text="last message text",
        null=True,
    )
    date = models.DateTimeField(
        verbose_name="date",
        null=True,
    )

    def __str__(self):
        s = 'profile: ' + str(self.profile) + '\n last message text:\n\t' + str(self.message_text)
        return s

    class Meta:
        ordering = ["-date"]
        verbose_name = "Last Message"

'''Вполне возможно, что вы изменили первичные ключи и/или ссылки на другие модели / таблицы, а некоторые устаревшие зависимости остались в файлах миграции.

Пожалуйста, обратитесь к официальной документации Django для возврата прошлых миграций. Вам не нужно перезапускать проект, чтобы удалить зависимости.

python manage.py makemigrations --empty yourappname

Вот и все. Затем проверьте файл 0001_initial.py в папке миграции в вашем приложении, чтобы убедиться, что все зависимости были удалены. Это должно выглядеть так:

from django.db import migrations

class Migration(migrations.Migration):

dependencies = [
    ('yourappname', '0001_initial'),
]

operations = [
]'''