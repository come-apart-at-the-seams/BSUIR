class Topic:
    def __init__(self, name, url, subs, parents):
        self.url = url
        self.name = name
        if subs:
            self.have_subs = True
            self.subtopics = subs
        else:
            self.have_subs = False
            self.subtopics = []
        if parents:
            self.have_parents = True
            self.parents = parents
        else:
            self.have_parents = False
            self.parents = None

    def add_subs(self, subs):
        if subs:
            self.have_subs = True
            self.subtopics += list(subs) # like list.extend()

    def add_parents(self, parents):
        if parents:
            self.parents = parents
            self.have_parents = True

    def get_names_from_array(self, arr):
        s = " "

        for a in arr:
            s += str(a.name) + ", "
        return s

    def get_parents_info(self):
        if self.parents:
            return self.parents.name
        return None

    def __str__(self):
       return "Name: " + str(self.name) + \
              "\n Url: " + str(self.url) + \
              "\n Have subs:" + str(self.have_subs) + ", Subs:" + str(self.get_names_from_array(self.subtopics)) + \
              "\n Have Parents:" + str(self.have_parents) + ", Parents:" + str(self.get_parents_info())

