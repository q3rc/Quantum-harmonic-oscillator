#include <iostream>
#include "io.h"
using namespace std;

int main(){
    int num1{readNumber()};
    int num2{readNumber()};
    cout<< "The Sum is "<< writeAnswer(num1, num2);
    cin.get();
    cin.get();
    return 0;
}

