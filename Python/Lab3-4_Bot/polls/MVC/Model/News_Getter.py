from bs4 import BeautifulSoup
import requests
import datetime

class News_getter:
    max_character_size = 800
    def get_headline(self, news):
        headline = news.h3.find(class_="qa-heading-link").span.string
        # headline = news.h3.span.string
        # headline = news.h3.find(class_="qa-heading-link lx-stream-post__header-link").span.string
        return headline

    def get_article_url(self, news, home_page):
        url = home_page + news.h3.a['href']
        return url

    def get_opening(self, news):
        paragraphs = self.get_article(news=news)
        opening_text = ''
        length = 0
        if len(paragraphs) >= 5:
            for i in range(5):
                length += len(paragraphs[i])
                opening_text += paragraphs[i] + '\n\n'
                if self.max_character_size < length:
                    break
            opening_text += '...' + '\n'
        else:
            for i in range(len(paragraphs)):
                opening_text += paragraphs[i] + '\n\n'

        return opening_text

    def get_article(self, news):
        url = self.get_article_url(news=news, home_page="https://www.bbc.com")
        # print(url)
        request = requests.get(url)
        soup = BeautifulSoup(request.text, "html.parser")
        article = soup.article
        paragraphs = []
        if article:
            for text_block in article.find_all(attrs={"data-component": "text-block"}):
                if text_block.string:
                    paragraphs.append(text_block.string)
                else:
                    for i in text_block.contents:
                        for f in i.contents:
                            text = ''
                            for ff in f.contents:
                                if ff.string:
                                    text += ff.string
                            paragraphs.append(text)
        return paragraphs

    def get_date(self, news):
        date = news.time.find(class_="qa-post-auto-meta").string
        # print('date in get_date - ' + str(date))
        if len(date) < 6:
            date += ' ' + str(datetime.datetime.utcnow().day) +\
                    ' ' + str(datetime.datetime.utcnow().month)
            date += ' ' + str(datetime.datetime.utcnow().year) + ' ' + '+0000'
            date = datetime.datetime.strptime(date, "%H:%M %d %m %Y %z")
        else:
            if len(date.split(' ')) == 3:
                date += ' ' + str(datetime.datetime.utcnow().year)
            date += ' ' + '+0000'
            date = datetime.datetime.strptime(date, "%H:%M %d %b %Y %z")
        # print(type(date))
        return date

    def get_ready_to_print_news(self, news):
        headLine = self.get_headline(news=news)
        url = self.get_article_url(news=news, home_page="https://www.bbc.com")
        date = self.get_date(news=news)
        opening = self.get_opening(news=news)
        text = headLine + '\n\n' + opening + '\n' + url
        return text

    def find_all_news(self, topic):
        url = topic.url
        request = requests.get(url)
        soup = BeautifulSoup(request.text, "html.parser")
        all_news_on_page = soup.find_all(class_="lx-stream__post-container")
        return all_news_on_page


    def get_all_news_from_topic(self, topic):
        all_news_on_page = self.find_all_news(topic=topic)
        all_texts = []
        for news in all_news_on_page:
            if news.h3.find(class_="qa-heading-link"):
                text = self.get_ready_to_print_news(news=news)
                all_texts.append(text)
        return all_texts

    def get_last_news_from_topic(self, topic):
        all_news_on_page = self.find_all_news(topic=topic)
        for news in all_news_on_page:
            if news.h3.find(class_="qa-heading-link"):
                text = self.get_ready_to_print_news(news=news)
                return text, news

    def get_latest_news_from_topic(self, topic, last_news_update_date):
        all_news_on_page = self.find_all_news(topic=topic)
        all_latest_news = []
        # print('last_news_update_date' + str(last_news_update_date))
        for news in all_news_on_page:
            if news.h3.find(class_="qa-heading-link"):
                news_date = self.get_date(news)
                # print('news_date' + str(news_date))
                # print(type(last_news_update_date))
                # print(type(news_date))
                if last_news_update_date < news_date:
                    all_latest_news.append(news)
                    # print('add to last news')
                # text = self.get_ready_to_print_news(news=news)
                # all_latest_news.append(text)
        return all_latest_news