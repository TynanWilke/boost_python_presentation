#include <iostream>
#include <string>
#include <boost/python.hpp>

boost::python::object import_module(const std::string& module, const std::string& path, boost::python::object& globals) {
    boost::python::dict locals;
    locals["module_name"] = module;
    locals["path"]        = path;

    boost::python::exec("import imp\n"
                        "new_module = imp.load_module(module_name, open(path), path, ('py', 'U', imp.PY_SOURCE))\n",
                        globals,
                        locals);
    return locals["new_module"];
}

int main() {
    using namespace boost::python;

    // Initialize interpreter
    Py_Initialize();

    object main_module = import("__main__");
    object main_namespace = main_module.attr("__dict__");
    object bar_module = import_module("bar", "bar.py", main_namespace);
    object b = bar_module.attr("Bar")("Joe");
    std::string name = extract<std::string>(b.attr("name"));
    std::cout << "Python Bar.name is " << name << std::endl;
    b.attr("speak")();

    b.attr("rename")("Nancy");
    name = extract<std::string>(b.attr("name"));
    std::cout << "Python Bar.name is " << name << std::endl;
    b.attr("speak")();
    return 0;
}
