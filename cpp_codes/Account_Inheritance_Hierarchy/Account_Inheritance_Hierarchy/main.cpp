#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"

using namespace std;

int main()
{
    cout << "Welcome to the Account Inheritance Hierarchy!\n";

    Account obj(2.50);
    obj.getBalance();

    cout << fixed << setprecision(2);
    cout << "New balance: $" << obj.credit(2.50) << endl;
    obj.getBalance();

    obj.debit(5);
    obj.getBalance();

    obj.setBalance(10.50);
    obj.getBalance();

    SavingsAccount obj2(10.50, 2);

    return 0;
}
