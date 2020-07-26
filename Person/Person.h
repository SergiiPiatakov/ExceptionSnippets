#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <ctime>
#include <stdexcept>

namespace PersonExceptions
{
    class Exception : public std::exception
    {
        public:
            virtual const char* what() const noexcept override;
    };

    class InvalidSexIpnIdx: public Exception
    {
        public:
            InvalidSexIpnIdx(const size_t idx);
            virtual const char* what() const noexcept override;
            virtual size_t which() const; // Method returns the index, invoked the exception

        private:
            const size_t SexIdx; // The index, invoked the exception
    };

    class InitializationException: public Exception
    {
        public:
            InitializationException(const std::string  pmtr);
            virtual const char* what() const noexcept override;
            virtual std::string which() const; // The first parameter, invoked the exception

        private:
            std::string parameter; // The first parameter, invoked the exception
    };
}


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
        if(year < 1900)
        {
            throw PersonExceptions::InitializationException("year");
        }
        else if(month < 0 || month > 11)
        {
            throw PersonExceptions::InitializationException("month");
        }
        else if(day < 1 || day > 31)
        {
            throw PersonExceptions::InitializationException("day");
        }
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
