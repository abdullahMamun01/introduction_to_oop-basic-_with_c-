// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std ;
class Student{
    public:
        string name ;
        int roll ;
        int id ;
        void callMe(){
            cout<< name<<" "<<roll <<" "<<id <<endl;
        }
        
};

class Pt : public Student{
    public :
        int income ;
        void callMe2(){
            cout<<income <<" " ;
            callMe();
        }
    
    
} ;

int main() {
    // Write C++ code here
    Pt obj1;
    obj1.name = "rakib";
    obj1.roll = 12 ;
    obj1.id = 12456;
    obj1.income = 256;
    obj1.callMe2() ;

    return 0;
}