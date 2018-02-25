#include <boost/python.hpp>
#include "entity.hpp"
#include "fight.hpp"


struct EntityWrap : Entity, boost::python::wrapper<Entity> {
    EntityWrap(const std::string &aName, const int aHp)
        : Entity(aName, aHp) {}

    /*virtual*/ int power() const {
        return this->get_override("power")();
    }
};

BOOST_PYTHON_MODULE(game) {
    using namespace boost::python;
    class_<EntityWrap, boost::noncopyable>("Entity", init<std::string, int>())
        .def_readonly("name", &EntityWrap::name)
        .def_readonly("hp", &EntityWrap::hp)
        .def_readonly("max_hp", &EntityWrap::maxHp)
        .def(self += int())
        .def("__str__", &EntityWrap::asStr)
        ;
    def("fight", &fight);
}
