#include <iostream>



void WhyNotWorld(std::string*& pa)
{
    std::string World = "";
    World = "World" + *pa;
}

int main()
{
    std::string pa = "";
    pa = "Hello";

    std::string* p = &pa;

    WhyNotWorld(p);
    std::cout << pa << std::endl;
}

