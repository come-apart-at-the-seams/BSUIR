from django.core.management.base import BaseCommand, CommandError
from aiogram import Bot, types
from aiogram.dispatcher import Dispatcher
from aiogram.utils import executor
from aiogram.dispatcher import FSMContext
from aiogram.dispatcher.filters.state import State, StatesGroup
from aiogram.utils.exceptions import BotBlocked
from aiogram.dispatcher.filters import Text, IDFilter
from os import getenv
from asgiref.sync import sync_to_async
from aiogram.contrib.fsm_storage.memory import MemoryStorage
import threading
import time
import asyncio
import datetime
import logging


from polls.Bot.TopicsAdder import add_topics_to_bd

from polls.models import Profiles

from polls.Bot import Bot as Bob
# from polls.Bot.Bot2 import Bot22
from polls.Bot.WorKWithDB import add_last_news, send_latest_news
from polls.Bot.conff import TOKEN


class Command(BaseCommand):
    help = 'TelegramBotStarter'
    logger = logging.getLogger(__name__)

    def handle(self, *args, **options):

        bot_token = TOKEN
        if not bot_token:
            self.logger.error("Error: no token provided")
            exit("Error: no token provided")
        bot = Bot(token=bot_token)
        dp = Dispatcher(bot, storage=MemoryStorage())

        add_topics_to_bd()




        def thread_function():
            while True:
                add_last_news()

                #  send_latest_news()

                loop = asyncio.new_event_loop()
                task = [loop.create_task(send_latest_news())]
                wait_task = asyncio.wait(task)
                loop.run_until_complete(wait_task)
                # loop.close()
                # asyncio.run(send_latest_news())
                self.logger.debug(datetime.datetime.utcnow())
                self.logger.debug('thread sleep.....')
                time.sleep(2)
                self.logger.debug(datetime.datetime.utcnow())
                self.logger.debug('WakeUP!!!!!')
        thread = threading.Thread(target=thread_function, args=(), daemon=True)
        thread.start()


        @sync_to_async()
        def add_profile_to_bd(msg):
            profile_str, is_created = Profiles.objects.get_or_create(
                tg_id=msg.from_user.id,
                defaults={
                    "name": msg.from_user.full_name,
                    "is_admin": False
                }
            )
            self.logger.debug(f'profile = {profile_str}, is created = {is_created}')

        dp.register_message_handler(Bob.start_command, commands="start")
        dp.register_message_handler(Bob.my_sub_command, commands="mysubs")
        dp.register_message_handler(Bob.cmd_admin_get_10_last_msg, commands="admin")
        dp.register_message_handler(Bob.cmd_help, commands="help")



        dp.register_message_handler(Bob.cmd_save, commands="save", state=Bob.Subscribe.waiting_for_topic_name)

        dp.register_message_handler(Bob.cmd_cancel, commands="cancel",
                                    state=Bob.Subscribe.waiting_for_topic_name)
        dp.register_message_handler(Bob.cmd_cancel, Text(equals="cancel", ignore_case=True), state="*")

        dp.register_message_handler(Bob.subscribe_to_topics, commands="subscribe", state="*")
        dp.register_message_handler(Bob.cmd_unsubscribe_from_all_topics, commands="unsubscribe", state="*")
        dp.register_message_handler(Bob.subscrides_chosen, state=Bob.Subscribe.waiting_for_topic_name)

        dp.register_message_handler(Bob.echo)


        executor.start_polling(dp)


