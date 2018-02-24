from game import Entity

class Wizard(Entity):
    def __init__(self):
        super(self, Entity).__init__("Wizard")
        self.min_power = 0
        self.max_power = 10

    def attack_power(self):
        return randint(self.min_power, self.max_power)

class Dragon(Entity):
    def __init__(self):
        super(self, Entity).__init__("Dragon")
        self.min_power = 0
        self.max_power = 20

    def attack_power(self):
        # Gets weaker the closer health gets to 0
        return randint(self.min_power, self.max_power)*(float(self.hp)/self.max_hp)

class Peasant(Entity):
    def __init__(self):
        super(self, Entity).__init__("Peasant")

    def attack_power(self):
        return 1

def create_entity(name):
    if name == "wizard":
        return Wizard()
    elif name == "dragon":
        return Dragon()
    else:
        return Peasant()
