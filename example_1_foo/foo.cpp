#include <iostream>
#include <string>
#include <boost/python.hpp>


struct Foo {
    std::string name;

    Foo(const std::string &aName = "Foo")
        : name(aName) {}

    void rename(const std::string &aName) {
        std::cout << "My new name is " << aName << std::endl;
        name = aName;
    }

    void speak() {
        std::cout << "Hi! My name is " << name << std::endl;
    }
};

BOOST_PYTHON_MODULE(foo) {
    using namespace boost::python;
    class_<Foo>("Foo", init<std::string>())
        .def("speak", &Foo::speak)
        .def("rename", &Foo::rename)
        .def_readonly("name", &Foo::name)
        ;
}
