#include <iostream>
#pragma once
using namespace std;

int readNumber(){
    int x{};
    cin >> x;
    return x;
}

int writeAnswer(int x, int y){
    return x +y;
}