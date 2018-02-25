#ifndef FIGHT_HPP
#define FIGHT_HPP

#include <iostream>
#include "entity.hpp"


void fight(Entity &aE1, Entity &aE2) {
    // Fight entities for a few rounds
    std::cout << "Fighting " << aE1.name << " vs " << aE2.name << std::endl;
    for(int i=0; i < 12 && !aE1.dead() && !aE2.dead(); ++i) {
        // Figure out the attack power of each entity
        const int p1 = aE1.power();
        const int p2 = aE2.power();

        // Reduce HP by difference in attack power
        if(p1 > p2) {
            const int hit = p1 - p2;
            std::cout << aE1.name << " hit for " 
                      << hit << " hp!" << std::endl;
            aE2.hp -= hit;
        }
        else if(p2 > p1) {
            const int hit = p2 - p1;
            std::cout << aE2.name << " hit for " 
                      << hit << " hp!" << std::endl;
            aE1.hp -= hit;
        }
        else {
            std::cout << aE1.name << " and " << aE2.name 
                      << " were an even match!" << std::endl;
        }
    }

    // Determine who won
    if(aE1.dead())
        std::cout << "*** " << aE2.name << " is the winner! ***" << std::endl;
    else if(aE2.dead())
        std::cout << "*** " << aE1.name << " is the winner! ***" << std::endl;
    else 
        std::cout << "*** " << aE1.name << " and " << aE2.name 
                  << " decide to have a beer instead! ***" << std::endl;
}

#endif /* FIGHT_HPP */
