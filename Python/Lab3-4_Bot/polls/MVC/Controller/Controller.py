import polls.MVC.Model.Model as Model
# import polls.MVC.Model.News_Getter as News_Getter
import polls.MVC.Controller.ignore_list
t = Model.Topic_Creater()

t.get_all_topics()
# t.print_all_topics_info()


# news_getter = News_Getter.News_getter()

ignore_list = polls.MVC.Controller.ignore_list.ignore_list


def is_ignore(url):
    for ignore in ignore_list:
        if ignore == url:
            return True
    return False

# for topic in t.topics:
#     if is_ignore(url=topic.url):
#         print("ignore")
#         continue
#     print('\n\n\n\tNEWS:')
#     print(topic.name + '  '+topic.url)
#     # news = news_getter.get_last_news_from_topic(topic=topic)
#     # print(news)

def get_topics():
    topics = []
    for topic in t.topics:
        if is_ignore(url=topic.url):
            continue
        print(f"add new topic: {topic.name}")
        topics.append(topic)
    # print("It is topics for buttons")
    # print(topics)
    return topics


