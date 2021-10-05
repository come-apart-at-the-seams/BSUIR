from asgiref.sync import sync_to_async
from datetime import datetime
from django.utils import timezone

from aiogram import Bot
from aiogram.dispatcher import Dispatcher

from polls.models import Profiles, Topics, Added_Subs, Last_Messages, Last_News
from polls.Bot.conff import TOKEN

from polls.MVC.Controller import Controller
from polls.MVC.Model.News_Getter import News_getter

topics = Controller.get_topics()
import logging
logger = logging.getLogger(__name__)

def find_url_by_name(name):
    for topic in topics:
        if topic.name == name:
            return topic.url
    return False


def add_subs():
    for topic in topics:
        print(f'u={topic.url}, n={topic.name}')
        topic_str, is_created = Topics.objects.get_or_create(
            url=topic.url,
            name=topic.name,
            added_subs=None,

        )
        print(f'p = {topic_str} i = {is_created}')


@sync_to_async()
def make_subscribe(msg):
    profile = Profiles.objects.filter(tg_id=msg.from_user.id)[0]
    url = find_url_by_name(msg.text)

    print(url)
    topic = Topics.objects.filter(url=url)[0]
    print(topic)


    b = Added_Subs(profile=profile, desire_to_subscribe=topic)
    b.save()

@sync_to_async()
def make_cancel(msg):
    print('cancel')
    profile = Profiles.objects.filter(tg_id=msg.from_user.id)[0]
    Added_Subs.objects.filter(profile=profile).delete()

@sync_to_async()
def make_save(msg):
    print('start saving')
    profile = Profiles.objects.filter(tg_id=msg.from_user.id)[0]
    topics_queue = Added_Subs.objects.filter(profile=profile)
    print(topics_queue)
    print()
    print(Added_Subs.objects.all())
    for i in topics_queue:
        print(i.desire_to_subscribe)
        print(i.desire_to_subscribe.url)
        topic = i.desire_to_subscribe
        profile.subscriptions.add(topic)
        topic.subs.add(profile)

# @sync_to_async()
def add_last_news():
    for topic in topics:
        topic_db = Topics.objects.filter(url=topic.url)[0]
        last_news_in_db = Last_News.objects.filter(topic=topic_db).order_by('-date')
        # print(last_news_in_db)
        if last_news_in_db:
            last_news_update_date = last_news_in_db[0].date

            all_latest_news = News_getter().get_latest_news_from_topic(topic, last_news_update_date=last_news_update_date)
            for news in all_latest_news:
                text = News_getter().get_ready_to_print_news(news=news)
                date = News_getter().get_date(news)
                url = News_getter().get_article_url(news=news, home_page="https://www.bbc.com")
                db_topic = Topics.objects.filter(url=topic.url)[0]
                logger.debug('WorkWithBD.add_last_news() ' + str(url))
                last_news_str, is_created = Last_News.objects.get_or_create(
                    url=url,
                    defaults={
                        'text': text,
                        'date': date,
                        'is_sent_to_everyone': False,
                    },
                )
                last_news_str.topic.add(db_topic)
                # print(last_news_str)
                db_topic.topic_last_news.add(last_news_str)
        else:
            text, news = News_getter().get_last_news_from_topic(topic)
            date = News_getter().get_date(news)
            url = News_getter().get_article_url(news=news, home_page="https://www.bbc.com")
            db_topic = Topics.objects.filter(url=topic.url)[0]
            # print(db_topic.topic_last_news)
            logger.debug('\nWorkWithBD.add_last_news() ' + str(url))
            last_news_str, is_created = Last_News.objects.get_or_create(
                url=url,
                defaults={
                    'text': text,
                    'date': date,
                    'is_sent_to_everyone': False,
                },
            )
            last_news_str.topic.add(db_topic)
            # print(last_news_str)
            db_topic.topic_last_news.add(last_news_str)

@sync_to_async()
def save_message(msg):
    profile = Profiles.objects.filter(tg_id=msg.from_user.id)[0]
    date = datetime.now(tz=timezone.utc)
    mess, is_created = Last_Messages.objects.get_or_create(
        profile=profile,
        defaults={
            'message_text': msg.text,
            'date': date,
        },
    )
    # mess.objects.update(message_text=msg.text)
    mess.message_text = msg.text
    mess.date = date
    mess.save()
    # profile = models.OneToOneField(
    #
    # message_text = models.TextField(
    #
    # date = models.DateTimeField(



async def send_latest_news():
    print('working?')
    bot_token = TOKEN
    bot = Bot(token=bot_token)
    dp = Dispatcher(bot)
    not_sended_news = Last_News.objects.filter(is_sent_to_everyone=False)
    logging.debug("send latest news")
    # print(not_sended_news)
    for news in not_sended_news:
        news_topics = news.topic.all()
        subs_id = []
        for topic in news_topics:
            profiles = topic.subs.all()
            text = news.text
            for profile in profiles:
                tg_id = profile.tg_id
                subs_id.append(tg_id)
                # print("2")
                # print(tg_id)
                # print(text)
                # print()
                # await bot.send_message(tg_id, text)
                # asyncio.sleep(1)
        subs_id = set(subs_id)
        print("3")
        for id in subs_id:
            logging.debug("bot.send_message(id, text)")
            await bot.send_message(id, text)

        news.is_sent_to_everyone = True
        news.save()



@sync_to_async()
def get_subscriptions_name(msg):
    profile = Profiles.objects.filter(tg_id=msg.from_user.id)[0]
    subs = profile.subscriptions.all()
    subs_names = []
    for s in subs:
        subs_names.append(s.name)
        print(subs_names)
    return subs_names


@sync_to_async()
def unsubscribe_from_all_topics(msg):
    profile = Profiles.objects.filter(tg_id=msg.from_user.id)[0]
    subs = profile.subscriptions.all()
    for s in subs:
        s.subs.remove(profile)
        profile.subscriptions.remove(s)
    print('unsubscribe_from_all_topics')


@sync_to_async()
def admin_get_10_last_msg():
    msgs = Last_Messages.objects.all()[:10]
    text = '------------------\n\n'
    for msg in msgs:
        text += str(msg) + '\n\n------------------\n\n'
    return text


@sync_to_async()
def is_admin(msg):
    admin = Profiles.objects.filter(tg_id=msg.from_user.id)[0].is_admin
    if admin:
        return True
    return False


@sync_to_async()
def add_profile_to_bd(msg):
    profile_str, is_created = Profiles.objects.get_or_create(
        tg_id=msg.from_user.id,
        defaults={
            "name": msg.from_user.full_name,
            "is_admin": False
        }
    )
    print(f'p = {profile_str} i = {is_created}')




