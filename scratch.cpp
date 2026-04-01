
#include <iomanip>
#include <iostream>
using namespace std;


int main(){
    int smaller{};
    cout<<"Enter an integer: ";
    cin>> smaller;


    int larger{};
    cout<<"Enter a larger integer: ";
    cin>> larger;

    if (larger<smaller){
        cout<<"Swapping the values\n";

        int temp{larger};
        larger=smaller;
        smaller=temp;

    }

 
    cout<<"The smaller value is "<<smaller<<"\n";
    cout<<"The larger value is "<< larger<<"\n";
    
   cin.get();
   cin.get();
   return 0; 
   
}