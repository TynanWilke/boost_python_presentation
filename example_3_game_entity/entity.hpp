#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <sstream>
#include <boost/noncopyable.hpp>

struct Entity {
    std::string name;
    int hp;
    int maxHp;

    Entity(const std::string &aName, const int aHp) 
        : name(aName), hp(aHp), maxHp(aHp) {}
    virtual ~Entity() {}

    // Returns the power of an attack
    virtual int power() const = 0;

    // Returns true if the entity is dead
    bool dead() {
        return hp <= 0;
    }

    // Heal operator overloading
    Entity& operator+=(const int aHp) {
        hp += aHp;
    }

    std::string asStr() const {
        std::ostringstream ss;
        ss << '[' << name << "] " << hp << '/' << maxHp;
        return ss.str();
    }
};

#endif /* ENTITY_HPP */
