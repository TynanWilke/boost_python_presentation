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

    bool dead() {
        return hp <= 0;
    }

    std::string asStr() const {
        std::ostringstream ss;
        ss << '[' << name << "] " << hp << '/' << maxHp;
        return ss.str();
    }

    virtual ~Entity() {}
    virtual int power() const = 0;
};

#endif /* ENTITY_HPP */
