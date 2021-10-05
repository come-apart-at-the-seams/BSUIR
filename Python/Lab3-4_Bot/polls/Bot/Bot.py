from aiogram import Bot, types
from aiogram.dispatcher import Dispatcher
from aiogram.utils import executor
from aiogram.utils.exceptions import BotBlocked
from aiogram.dispatcher import FSMContext
from aiogram.dispatcher.filters.state import State, StatesGroup


import os
os.environ["DJANGO_ALLOW_ASYNC_UNSAFE"] = "true"
import logging
logger = logging.getLogger(__name__)

from polls.Bot.TopicsAdder import get_available_topic_names
from polls.Bot.Buttons import create_buttons_without_subs, create_cmd_buttons

from polls.Bot.WorKWithDB import make_subscribe, make_save, make_cancel,\
    save_message, get_subscriptions_name, unsubscribe_from_all_topics,\
    admin_get_10_last_msg, is_admin, add_profile_to_bd



from polls.Bot.conff import TOKEN, HELP_MESSAGE




bot_token = TOKEN
if not bot_token:
    exit("Error: no token provided")
bot = Bot(token=bot_token)
dp = Dispatcher(bot)






available_topic_names = get_available_topic_names()
cmd_buttons = create_cmd_buttons()


def save_mess_decor(func):
    async def wrapped(*args, **kwargs):
        logger.debug('bot have new message')
        await save_message(args[0])
        await func(*args, kwargs['state'])
    return wrapped


def reg_profile(func):
    async def wrapped(*args, **kwargs):
        logger.info('new profile create')
        await add_profile_to_bd(args[0])
        await func(*args, **kwargs)
    return wrapped




@dp.errors_handler(exception=BotBlocked)
async def error_bot_blocked(update: types.Update, exception: BotBlocked):
    # Update: объект события от Telegram. Exception: объект исключения
    # Здесь можно как-то обработать блокировку, например, удалить пользователя из БД

    logger.warning(f"Меня заблокировал пользователь!\nСообщение: {update}\nОшибка: {exception}")

    # Такой хэндлер должен всегда возвращать True,
    # если дальнейшая обработка не требуется.
    return True


@reg_profile
@save_mess_decor
async def start_command(message: types.Message, state: FSMContext):
    await message.reply("Hello👋\nIt's a BBC-news bot.", reply_markup=cmd_buttons)


@reg_profile
@save_mess_decor
async def cmd_help(message: types.Message, state: FSMContext):
    logger.debug('help cmd')
    await bot.send_message(message.from_user.id, HELP_MESSAGE, reply_markup=cmd_buttons)


@reg_profile
@save_mess_decor
async def echo(message: types.Message, state: FSMContext):
    t = 'Dear ' + str(message.from_user.full_name) + \
        '!\nThere is no command like you are using. Use command /help to get help '

    await bot.send_message(message.from_user.id, t, reply_markup=cmd_buttons)


@reg_profile
@save_mess_decor
async def my_sub_command(message: types.Message, state: FSMContext):
    s = await get_subscriptions_name(msg=message)
    text = ''
    for sub in s:
        if str(sub) in available_topic_names:
            text += str(sub) + '\n'
    await message.reply(f"Your subs is:\n--------------\n{text}--------------", reply_markup=cmd_buttons)


@reg_profile
@save_mess_decor
async def subscribe_to_topics(message: types.Message, state: FSMContext):
    subs = await get_subscriptions_name(msg=message)
    kb_topic_name, kb_for_press_save = create_buttons_without_subs(subs_names=subs)

    await message.answer("Select the topics that interest you.\n"
                         "Click the save button to finish.\n"
                         "Press the cancel button to cancel the selection.", reply_markup=kb_topic_name)
    await Subscribe.waiting_for_topic_name.set()


@reg_profile
@save_mess_decor
async def subscrides_chosen(message: types.Message, state: FSMContext):
    subs = await get_subscriptions_name(msg=message)
    kb_topic_name, kb_for_press_save = create_buttons_without_subs(subs_names=subs)
    if message.text not in available_topic_names:
        await message.answer("Please select a topic using the keyboard below.", reply_markup=kb_for_press_save)
        return
    await make_subscribe(msg=message)
    await save_message(msg=message)
    # await state(chosen_topic=message.text.lower())
    # Для последовательных шагов можно не указывать название состояния, обходясь next()
    # await Subscribe.next()
    # user_data = await state.get_data()

    # await message.answer("Select another one or press save. "
    #                      f"You chose {user_data}", reply_markup=kb_for_waiting_for_press_save)
    await message.answer("Select another one or press save.", reply_markup=kb_for_press_save)


@reg_profile
@save_mess_decor
async def cmd_cancel(message: types.Message, state: FSMContext):
    await state.finish()
    await make_cancel(message)
    await message.answer("Signing was cancelled❌", reply_markup=types.ReplyKeyboardRemove())


@reg_profile
@save_mess_decor
async def cmd_save(message: types.Message, state: FSMContext):
    await state.finish()
    await make_save(message)
    await make_cancel(message)
    await message.answer("Everything you selected has been saved💾", reply_markup=types.ReplyKeyboardRemove())


@reg_profile
@save_mess_decor
async def cmd_unsubscribe_from_all_topics(message: types.Message, state: FSMContext):
    await unsubscribe_from_all_topics(message)
    await message.answer("Unsubscribe from all topics⛔📨", reply_markup=types.ReplyKeyboardRemove())


if __name__ == '__main__':
    executor.start_polling(dp)




class Subscribe(StatesGroup):
    waiting_for_topic_name = State()
    waiting_for_press_save = State()


@reg_profile
@save_mess_decor
async def cmd_admin_get_10_last_msg(message: types.Message, state: FSMContext):
    if await is_admin(message):
        t = await admin_get_10_last_msg()
        await bot.send_message(message.from_user.id, t)