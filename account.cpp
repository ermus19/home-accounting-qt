#include "account.h"

account::account()
{
    this->name = "default";
    this->description = "None";
    this->balance = 0;
}

account::account(string name, string description, double balance)
{
    this->name = name;
    this->description = description;
    this->balance = balance;
}

bool account::save()
{
    return true;
}
