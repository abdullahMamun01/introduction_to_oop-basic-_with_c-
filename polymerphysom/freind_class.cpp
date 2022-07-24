// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std ;
class Parent {
    private :
        int tk ;
        int password ;
    public :
        Parent(int amount,int ps){
            tk = amount ;
            password = ps ;
        }
friend class Friend ; // its call freind class
};

class Friend {
    
    public :
        void tellSecret(Parent * pt){
            cout<< pt->tk <<" "<<pt ->password<<endl;
        }
};

int main() {
    // Write C++ code here
    Parent pt(100,12345);
    Friend fr ;
    fr.tellSecret(&pt) ;

    return 0;
}