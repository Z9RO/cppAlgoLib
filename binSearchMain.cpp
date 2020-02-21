#include <iostream>
#include "binSearch.h"
#include <functional>

bool fun2(int mid);

bool fun2(int mid)
{
    return mid<-6;
}

int main()
{
    std::function<bool(int)> fun = [](int mid){ return mid<-6; };
    std::cout<< binSearch(-10, -1, fun) <<std::endl;
    std::cout<< binSearchP(-10, -1, fun2) <<std::endl;

    return 0;
}
