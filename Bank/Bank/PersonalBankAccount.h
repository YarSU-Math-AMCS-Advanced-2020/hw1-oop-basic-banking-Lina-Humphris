#pragma once
#include "BankAccount.h"
#include <string>
#include "Date.h"

using namespace std;

class PersonalBankAccount :
    public BankAccount
{
private:
    string _surname;
    string _name;
    string _patronymic;
    Date _birth_date;
    int _sex;
    string _passport;
public:
    PersonalBankAccount(string surname, string name, string patronymic, Date birth_date, int sex, string passport);

    void set_surname(string surname);
    void set_name(string name);
    void set_patronymic(string patronymic);
    void set_birth_date(Date birth_date);
    void set_sex(int sex);
    void set_passport(string passport);
};

