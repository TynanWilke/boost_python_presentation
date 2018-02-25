import foo

f = foo.Foo("Joe")
print "C++ Foo.name is %s" % (f.name)
f.speak()

f.rename("Nancy")
print "C++ Foo.name is %s" % (f.name)
f.speak()

foo.meet_friend(f, "Ted")
