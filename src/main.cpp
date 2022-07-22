#include <iostream>
#include <boost/bind.hpp>
#include "os_interface.hpp"


void func1() {
    std::cout << "func1 running" << std::endl;    
}

void func2() {
    std::cout << "func2 running" << std::endl;    
}

int main() {
    OsInterfacePtr os = OsInterface::Create();
    os->SetTask(boost::bind(&func1), 0);
    os->SetTask(boost::bind(&func2), 0);

    while(true) {} 

    return 0;
}
