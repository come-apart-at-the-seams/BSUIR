# Create your tests here.
import asynctest

from unittest.mock import AsyncMock

from asyncio import BaseEventLoop

import pytest

from aiogram import Bot, types
from . import FakeTelegram, TOKEN

pytestmark = pytest.mark.asyncio


# class OrderModelTest(TestCase):
#
#
#     ln = Last_News.objects.create(
#         url='url',
#         text='text',
#         topic=None,
#         is_sent_to_everyone=False,
#         date=datetime.datetime.now(),
#     )
#
#     def test_user_blank(self):
#         order = Last_News.objects.get(pk=1)
#         field_prop = order._meta.get_field('user').blank
#         self.assertEquals(field_prop, True)


@pytest.fixture(name='bot')
async def bot_fixture():
    """ Bot fixture """
    _bot = Bot(TOKEN, parse_mode=types.ParseMode.HTML)
    yield _bot
    await _bot.close()


@pytest.fixture()
async def message(bot):
    """
    Message fixture
    :param bot: Telegram bot fixture
    :type bot: Bot
    :param event_loop: asyncio event loop
    :type event_loop: BaseEventLoop
    """
    from polls.tests.dataset import MESSAGE
    msg = types.Message(**MESSAGE)

    async with FakeTelegram(message_data=MESSAGE):
        _message = await bot.send_message(chat_id=msg.chat.id, text=msg.text)

    yield _message

# async def test_echo(message):
#     # bot = bot_fixture
#     # msg = message
#     await echo(message, [])

from polls.Bot.WorKWithDB import make_subscribe

class TestMyFunctions(asynctest.TestCase):
    @pytest.mark.asyncio
    async def test_echo_handler(self):
        text_mock = "test123"
        message_mock = AsyncMock(text=text_mock, full_name='a')
        print(message_mock)
        print(type(message_mock))
        make_subscribe(message_mock)
        # await echo(message_mock, [])
        t = 'Dear ' + str(message_mock.full_name) + \
            '!\nThere is no command like you are using. Use command /help to get help '
        # message_mock.answer.assert_called_with(text_mock)

