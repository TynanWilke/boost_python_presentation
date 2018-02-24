class Bar:
    def __init__(self, name):
        self.name = name

    def rename(self, name):
        self.name = name
        print "My new name is %s" % (self.name)

    def speak(self):
        print "Hi! My name is %s" % (self.name)
