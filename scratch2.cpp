#include <cstdint> // for std::uint16_t
#include <iostream>
#include <string>
using namespace std;

string Person(){
    string name{};
    getline (cin>> ws, name);
    return name;
   
}

int Age(){
    int age{};
    cin>> age;
    return age;
    
}
int main()
{
    cout<<"Enter the name of person #1: ";
    string n1{Person()};

    cout<<"Enter the age of "<<n1<<":";
    int a1{Age()};

    cout<<"Enter the name of person #2: ";
    string n2{Person()};

    cout<<"Enter the age of "<<n2<<":";
    int a2{Age()};

    if (a2>a1)
    cout<< n2<<"(age "<<a2<<") is older than "<< n1 <<"(age "<< a1<<").";
    else{
        cout<< n1<<"(age "<<a1<<") is older than "<< n2 <<"(age "<< a2<<").";
    }
    cin.get();
    cin.get();
    cin.get();
    cin.get();
    return 0;

}