// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class BankAcount
{
public:
    string name;
    string address;
    int account_num;
    int age;

private:
    string password;

protected:
    int balance;

public:
    BankAcount(string name, string address, string password, int age)
    {
        this->name = name;
        this->address = address;
        this->password = password;
        this->age = age;
        this->account_num = rand() % 10000000000;
        this->balance = 0;

        cout << "Your account number id : " << this->account_num << endl;
    }

public:
    void showBal(string password)
    {
        if ((this->password) == password)
        {
            cout << "Your account balance is: " << this->balance << endl;
        }
        else
        {
            cout << "Password doesnt metter" << endl;
        }
    }

public:
    void addMoney(string password, int amount)
    {
        
        if (this->password == password)
        {
            this->balance += amount;
            cout << "Deposit successfull" << endl;
            cout << "Your account balance is: " << this->balance << endl;
        }
        else
        {
            cout << "Password doesnt metter" << endl;
        }
    }

public:
    void withdrawMoney(string password, int amount)
    {
        cout<<"withdraw your balance:  "<<endl;
        if (this->password == password)
        {
            this->balance -= amount;
            cout << "Withdraw successfull" << endl;
            cout << "Your account balance is: " << this->balance << endl;
        }
        else
        {
            cout << "Password doesnt metter" << endl;
        }
    }
    friend class Mycash;
};

BankAcount *createAccount()
{
    cout<<"Create an account: "<<endl;
    string name, address, password;
    int age;
    cin >> name >> address >> password >> age;

    BankAcount *ac = new BankAcount(name, address, password, age);
    cout << "Account create succesfully" << endl;

    // cout <<account
    return ac;
}
void add_money(BankAcount *ac)
{
    cout<<"enter pass and amount of deposit "<<endl ;
    cout << "add to money: " << endl;
    string pass;
    int amount;
    cin >> pass >> amount;

    ac->addMoney(pass, amount);
}
void withdraw_money(BankAcount *ac)
{
    cout << "withdraw money: " << endl;
    cout<<"enter pass and amount of withdraw "<<endl ;
    string pass;
    int amount;
    cin >> pass >> amount;

    ac->withdrawMoney(pass, amount);
}

class Mycash
{
protected:
    int balance;

public:
    Mycash()
    {
        this->balance = 0;
    }

public:
    void add_money_from_bank(string password, int amount, BankAcount *ac)
    {

        if (ac->password == password)
        {
            this->balance += amount;
            ac->balance -= amount;
            cout << "bank balance is : " << ac->balance << endl;
            cout << "My cash balance is : " << this->balance;
        }
        else
        {
            cout << "in valid password" << endl;
        }
    }

public:
    void showBal(string password)
    {

        cout << "Your account balance is: " << this->balance << endl;
    }

} ;

void add_money_from_bank(Mycash *mc ,BankAcount * ac){
    cout<<"add money my_cash app: "<<endl;
    cout<<"enter pass and amount of deposit "<<endl ;
    string password ;
    int amount ;
    cin>> password >>amount ;

    mc ->add_money_from_bank(password ,amount ,ac) ;

}

int main()
{
    BankAcount *acc = createAccount();
    Mycash *mycash = new Mycash() ;
 
    add_money(acc);
    withdraw_money(acc);
    add_money_from_bank(mycash,acc);
    // cout<<"enter pass : "<<endl ;
    // string pass ;
    // // int amount ;
    // cin >>pass ;
    // // acc->addMoney(amount ,pass) ;
    // acc -> showBal(pass);

    return 0;
}