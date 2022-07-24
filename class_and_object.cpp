// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std ;

class Student {
    public: 
        char name[100] ;
        int roll ;
        int id ;
};

int main() {
    // Write C++ code here
    Student rakib ;
    strcpy(rakib.name ,"Rakib hasan");
    rakib.roll = 12 ;
    rakib.id = 121243542;
    cout <<rakib.name <<" "<<rakib.roll;

    return 0;
}