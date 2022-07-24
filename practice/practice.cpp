// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class Tax
{
protected:
    int tax;

public:
    Tax()
    {
        this->tax = 1000;
    }
public: 
    void display(){
        cout<<this->tax <<endl;
    }
    friend class Relation ;
};

class Relation
{

public:
    void tax_set(int tt, Tax *t)
    {
        t->tax = tt;
        cout << t->tax << endl;
    }
};

int main()
{
    // Write C++ code here
    Tax *tax = new Tax();
    Relation *relation = new Relation;

    relation->tax_set(100, tax);
    tax->display();
    return 0;
};