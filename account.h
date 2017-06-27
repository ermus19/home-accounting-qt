#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

class account
{

public:
    account();
    account(string name, string description, double balance);
    bool save();

private:
    string name;
    string description;
    double balance;

};

#endif // ACCOUNT_H
