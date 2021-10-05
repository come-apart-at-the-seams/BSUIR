from aiogram.types import ReplyKeyboardRemove, \
    ReplyKeyboardMarkup, KeyboardButton, \
    InlineKeyboardMarkup, InlineKeyboardButton
from polls.MVC.Controller import Controller
from polls.Bot.conff import BOT_CMD
# button_hi = KeyboardButton('Привет! 👋')
cancel = KeyboardButton('/cancel')
save = KeyboardButton('/save')
topics = Controller.get_topics()

# greet_kb = ReplyKeyboardMarkup(
#     resize_keyboard=True,
#     one_time_keyboard=True,
#
# )
#
# buttons = []
# for topic in topics:
#     buttons.append(KeyboardButton(topic.name))
# for button in buttons:
#     greet_kb.insert(button)
# greet_kb.add(button_hi)
#
#
# # kb for waiting_for_topic_name
# kb_for_waiting_for_topic_name = ReplyKeyboardMarkup(
#     resize_keyboard=True,
#     one_time_keyboard=False,
#
# )
# buttons = []
# for topic in topics:
#     buttons.append(KeyboardButton(topic.name))
#
# kb_for_waiting_for_topic_name.add(cancel)
# for button in buttons:
#     kb_for_waiting_for_topic_name.insert(button)


# kb for waiting_for_press_save
# kb_for_waiting_for_press_save = ReplyKeyboardMarkup(
#     resize_keyboard=True,
#     one_time_keyboard=False,
#
# )
# buttons = []
# for topic in topics:
#     buttons.append(KeyboardButton(topic.name))
#
# kb_for_waiting_for_press_save.row(cancel, save)
# for button in buttons:
#     kb_for_waiting_for_press_save.insert(button)
#

def create_buttons_without_subs(subs_names):
    kb_for_waiting_for_press_save = ReplyKeyboardMarkup(
        resize_keyboard=True,
        one_time_keyboard=False,
    )
    buttons = []
    for topic in topics:
        if topic.name not in subs_names:
            buttons.append(KeyboardButton(topic.name))

    kb_for_waiting_for_press_save.row(cancel, save)
    kb_for_waiting_for_press_save.add(buttons[0])
    for i in range(len(buttons)):
        if i == 0:
            continue
        kb_for_waiting_for_press_save.insert(buttons[i])



    kb_for_waiting_for_topic_name = ReplyKeyboardMarkup(
        resize_keyboard=True,
        one_time_keyboard=False,
    )
    buttons = []
    for topic in topics:
        if topic.name not in subs_names:
            buttons.append(KeyboardButton(topic.name))

    kb_for_waiting_for_topic_name.row(cancel)
    kb_for_waiting_for_topic_name.add(buttons[0])
    for i in range(len(buttons)):
        if i == 0:
            continue
        kb_for_waiting_for_topic_name.insert(buttons[i])
    return kb_for_waiting_for_topic_name, kb_for_waiting_for_press_save


def create_cmd_buttons():
    cmd_buttons = ReplyKeyboardMarkup(
        resize_keyboard=True,
        one_time_keyboard=False,
    )
    for cmd in BOT_CMD:
        button = KeyboardButton(cmd)
        cmd_buttons.add(button)

    return cmd_buttons