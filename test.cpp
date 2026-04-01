#include "constants.h"
#include <iostream>
using namespace std;

int accumulate(int num){
    static int a{0};
    a = a+num;
    return a;
}

int main()
{
    std::cout << accumulate(4) << '\n'; // prints 4
    std::cout << accumulate(3) << '\n'; // prints 7
    std::cout << accumulate(2) << '\n'; // prints 9
    std::cout << accumulate(1) << '\n'; // prints 10
    
    cin.get();
    cin.get();
    return 0;
}