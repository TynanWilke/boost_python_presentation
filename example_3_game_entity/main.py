import game
from random import randint

class Wizard(game.Entity):
    """ Low HP, high power. """
    def __init__(self):
        super(Wizard, self).__init__("Wizard", 20)
        self.min_power = 0
        self.max_power = 40

    def power(self):
        return int(randint(self.min_power, self.max_power))

class Dragon(game.Entity):
    """ High HP, lower power which decreases with lower HP. """
    def __init__(self):
        super(Dragon, self).__init__("Dragon", 200)
        self.min_power = 0
        self.max_power = 20

    def power(self):
        return int(randint(self.min_power, self.max_power)*(float(self.hp)/self.max_hp))

class Peasant(game.Entity):
    """ Medium HP, pitiful power. """
    def __init__(self):
        super(Peasant, self).__init__("Peasant", 100)

    def power(self):
        return 1

if __name__ == "__main__":
    # Fair fight
    e1 = Wizard()
    e2 = Dragon()

    # Terrible fight
    #e1 = Wizard()
    #e2 = Peasant()

    # Reasonable fight
    #e1 = Peasant()
    #e2 = Peasant()

    game.fight(e1, e2)
    print e1
    print e2

    # Heal the entities
    e1 += 100
    e2 += 20
    print e1
    print e2
