from bs4 import BeautifulSoup
import requests
from polls.MVC.Model.Topic import Topic


class Topic_Creater:
    topics = []

    url = "https://www.bbc.com/news"
    request = requests.get(url)
    soup = BeautifulSoup(request.text, "html.parser")


    def is_unique_hrefs(self, href):
        for topic in self.topics:
            if topic.url == self.get_thematic_page(home_page="https://www.bbc.com", topic_href=href):
                return False
        return True

    def is_unique_urls(self, url):
        for topic in self.topics:
            if topic.url == url:
                return False
        return True

    def find_topic_by_url(self, url):
        for topic in self.topics:
            if topic.url == url:
                return topic
        return False

    def get_class_with_one_str(self, class_name, beautifulSoup):
        tmp = []
        for i in beautifulSoup.find_all(class_=class_name):
            if len(i["class"]) == 1:
                tmp.append(i)
        return set(tmp)

    def get_href(self, str):
        return str['href']

    def get_span(self, str):
        return str.span.string

    def get_array_of_hrefs(self, class_name, beautifulSoup):
        arr = []
        for str in self.get_class_with_one_str(class_name, beautifulSoup):
            arr.append(self.get_href(str))
        set_ = set(arr)
        arr = list(set_)
        return arr

    def get_array_of_topic_names(self, class_name, beautifulSoup):
        arr = []
        for str in self.get_class_with_one_str(class_name, beautifulSoup):
            arr.append(self.get_span(str))
        set_ = set(arr)
        arr = list(set_)
        return arr

    def get_dictionary_span_href(self, class_name, beautifulSoup):
        dict = {}
        for str in self.get_class_with_one_str(class_name,
                                               beautifulSoup):  # непонятно должен возращаиться сет но возращяеться не сет
            dict[self.get_span(str)] = self.get_href(str)
        return dict

    def get_thematic_page(self, home_page, topic_href):
        return home_page + topic_href

    def get_subthematic_page(self, page_url):
        request = requests.get(page_url)
        soup = BeautifulSoup(request.text, "html.parser")
        hrefs = self.get_array_of_hrefs(class_name="nw-o-link", beautifulSoup=soup)
        return hrefs

    def get_subtopic(self, home_page, href_topic):
        list_of_pages = self.get_subthematic_page(page_url=home_page + href_topic)
        subtopics = []
        for page in list_of_pages:
            if href_topic in page and page != href_topic:
                subtopics.append(page)
        return subtopics

    def is_it_sub(self, parent, topic):
        if parent.url in topic.url and topic.url != parent.url:
            return True
        return False

    def get_all_subtopics(self, parent):
        url = parent.url
        request = requests.get(url)
        soup = BeautifulSoup(request.text, "html.parser")

        span_href = self.get_dictionary_span_href("nw-o-link", beautifulSoup=soup)
        new_topics = []
        for span in span_href:
            if self.is_unique_hrefs(span_href[span]):
                topic = Topic(name=span,
                              url=self.get_thematic_page(home_page="https://www.bbc.com", topic_href=span_href[span]),
                              subs=[], parents=None)
                if self.is_it_sub(parent=parent, topic=topic):
                    topic.add_parents(parents=parent)
                    parent.add_subs(subs=[topic])
                self.topics.append(topic)
                new_topics.append(topic)
            else:
                topic = self.find_topic_by_url(
                    url=self.get_thematic_page(home_page="https://www.bbc.com", topic_href=span_href[span]))
                if self.is_it_sub(parent=parent, topic=topic):
                    topic.add_parents(parents=parent)
                    parent.add_subs(subs=[topic])
        # todo this works. its on when db was ready
        # for topic in new_topics:
        #     subs = self.get_all_subtopics(topic)
        #     topic.add_subs(subs)

    def get_all_topics(self):
        url = "https://www.bbc.com/news"
        request = requests.get(url)
        soup = BeautifulSoup(request.text, "html.parser")

        topic =Topic(name="News!!!!!!!!!!!!", url="https://www.bbc.com/news", subs=[], parents=None)
        self.topics = [topic]

        # subs = self.create_all_topics(beautifulSoup=soup, subs=[],  parents=None)
        subs = self.get_all_subtopics(parent=topic)
        topic.add_subs(subs)
        return self.topics

    def print_all_topics_info(self):
        for topic in self.topics:
            print(topic)


