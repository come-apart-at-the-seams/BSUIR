from django.core.management.base import BaseCommand, CommandError

from polls.models import Profiles, Topics

from polls.MVC.Controller import Controller


topics = Controller.get_topics()


def add_topics_to_bd():
    for topic in topics:
        print(f'u={topic.url}, n={topic.name}')
        topic_str, is_created = Topics.objects.get_or_create(
            url=topic.url,
            defaults={
                'name': topic.name,
                'added_subs': None,
        }
        )
        print(f'p = {topic_str} i = {is_created}')

def get_available_topic_names():
    topic_names = []
    for topic in topics:
        topic_names.append(topic.name)

    return topic_names

