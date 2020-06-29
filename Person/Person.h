#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <ctime>



struct Name
{
    std::string first;
    std::string middle;
    std::string last;
};



struct Date : std::tm
{
    Date (int year, int month, int day)
        : tm {0, 0, 0, day, month - 1, year - 1900, 0, 0, 0, 0, 0}
    {
    }
};



enum class Sex
{
    Male
  , Female
  , HasntDecidedYet 
};



struct Person
{
    std::string ptn;    // Personal tax number.
    Name        name;   // Full name.
    Date        bdate;  // Birth date.
    Sex         sex;    // Gender.
};



class Validator
{
    public:
        static bool ValidatePerson (const Person &);

    protected:
        static bool ValidateBDate  (const Person &);
        static bool ValidateSex    (const Person &);
        static int  ParseBDate     (const Person &);
        static Sex  ParseSex       (const Person &);
};

#endif//PERSON_H
