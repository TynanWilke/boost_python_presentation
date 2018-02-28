#include <iostream>
#include <string>
#include <boost/python.hpp>


struct Foo {
    std::string name;

    Foo(const std::string &aName = "Foo")
        : name(aName) {}

    void rename(const std::string &aName) {
        name = aName;
        std::cout << "My new name is " << name << std::endl;
    }

    void speak() {
        std::cout << "Hi! My name is " << name << std::endl;
    }
};

void meetFriend(const Foo &aFoo, const std::string &aFriend) {
    std::cout << "Im " << aFriend 
              << ". Nice to meet you, " << aFoo.name 
              << '!' << std::endl;
}

BOOST_PYTHON_MODULE(foo) {
    using namespace boost::python;
    class_<Foo>("Foo", init<std::string>())
        .def("speak", &Foo::speak)
        .def("rename", &Foo::rename)
        .def_readonly("name", &Foo::name)
        ;
    def("meet_friend", &meetFriend);
}
