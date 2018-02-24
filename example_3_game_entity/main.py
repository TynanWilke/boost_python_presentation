import game
from random import randint

class Wizard(game.Entity):
    def __init__(self):
        super(Wizard, self).__init__("Wizard", 20)
        self.min_power = 0
        self.max_power = 40

    def power(self):
        return int(randint(self.min_power, self.max_power))

class Dragon(game.Entity):
    def __init__(self):
        super(Dragon, self).__init__("Dragon", 200)
        self.min_power = 0
        self.max_power = 20

    def power(self):
        return int(randint(self.min_power, self.max_power)*(float(self.hp)/self.max_hp))

class Peasant(game.Entity):
    def __init__(self):
        super(Peasant, self).__init__("Peasant", 100)

    def power(self):
        return 1

if __name__ == "__main__":
    e1 = Wizard()
    e2 = Dragon()

    #e1 = Wizard()
    #e2 = Peasant()

    #e1 = Peasant()
    #e2 = Peasant()

    game.fight(e1, e2)
    print e1
    print e2
