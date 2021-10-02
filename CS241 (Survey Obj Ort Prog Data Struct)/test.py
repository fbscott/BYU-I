class Foo          (object):
    # ^class name  #^ inherits from object

    bar = "Bar" #Class attribute.

    def __init__(self):
        #        #^ The first variable is the class instance in methods.  
        #        #  This is called "self" by convention, but could be any name you want.
        #^ double underscore (dunder) methods are usually special.  This one 
        #  gets called immediately after a new instance is created.

        self.variable = "Foo" #instance attribute.
        print (self.variable, self.bar)  #<---self.bar references class attribute
        self.bar = " Bar is now Baz"   #<---self.bar is now an instance attribute
        print (self.variable, self.bar)  

    def method(self, arg1, arg2):
        #This method has arguments.  You would call it like this:  instance.method(1, 2)
        print ("in method (args):", arg1, arg2)
        print ("in method (attributes):", self.variable, self.bar)


a = Foo() # this calls __init__ (indirectly), output:
                 # Foo bar
                 # Foo  Bar is now Baz
print (a.variable) # Foo
a.variable = "bar"
a.method(1, 2) # output:
               # in method (args): 1 2
               # in method (attributes): bar  Bar is now Baz
Foo.method(a, 1, 2) #<--- Same as a.method(1, 2).  This makes it a little more explicit what the argument "self" actually is.

class Bar(object):
    def __init__(self, arg):
        self.arg = arg
        self.Foo = Foo()

b = Bar(a)
b.arg.variable = "something"
print (a.variable) # something
print (b.Foo.variable) # Foo