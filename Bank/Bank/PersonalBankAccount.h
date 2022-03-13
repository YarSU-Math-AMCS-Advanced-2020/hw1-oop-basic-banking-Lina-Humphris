#pragma once
#include <string>
#include "BankAccount.h"
#include "Date.h"
#include "DataBase.h"

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
    PersonalBankAccount();

    void set_surname(string surname) { _surname = surname; };
    void set_name(string name) { _name = name; };
    void set_patronymic(string patronymic) { _patronymic = patronymic; };
    void set_birth_date(Date birth_date) { _birth_date = birth_date; };
    void set_sex(int sex) { _sex = sex; };
    void set_passport(string passport) { _passport = passport; };


    friend std::istream& operator>>(istream& in, PersonalBankAccount& t);
};

