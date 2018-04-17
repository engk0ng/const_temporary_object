//
//  main.cpp
//  const_temporary_object
//
//  Created by Abu Muhammad on 16/04/18.
//  Copyright © 2018 Abu Muhammad. All rights reserved.
//

#include <iostream>

int return_int_ref()
{
    int a {123};
    return a;
}

class Base
{
public:
    ~Base()
    {
        std::cout << "Base dtor " << std::endl;
    }
};

class Foo: public Base
{
public:
    ~Foo()
    {
        std::cout << "Foo dtor" << std::endl;
    }
};

Base return_base()
{
    return {};
}

Foo return_foo()
{
    return {};
}

int main(int argc, const char * argv[]) {
    // insert code here...
    const int &int_ref {return_int_ref()};
    std::cout << "Some stack overwriting intermediate print" << std::endl;
    std::cout << int_ref << std::endl;
    Base &&b  = return_foo();
    return 0;
}
