class Article:
    def __init__(self, id, headline, url, opening, date, time, photo_url, video_url):
        self.id = id
        self.heasdline = headline
        self.url = url
        self.opening = None
        if opening:
            self.opening = opening
        self.date = None
        if date:
            self.date = date
        self.time = None
        if time:
            self.time = time
        self.photo_url = None
        if photo_url:
            self.photo_url = photo_url
        self.video_url = None
        if video_url:
            self.video_url = video_url
