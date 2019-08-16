#include "Person.h"



bool Validator::ValidatePerson (const Person & person)
{
    return ValidateSex   (person)
        && ValidateBDate (person);
}



bool Validator::ValidateBDate (const Person & person)
{
    Date a {1970, 1, 1};
    Date b = person.bdate;
    const std::time_t c = std::mktime (& a);
    const std::time_t d = std::mktime (& b);
    const int days = (std::difftime (d, c) ) / (60 * 60 * 24) + 25568;

    return ParseBDate (person) == days;
}



bool Validator::ValidateSex (const Person & person)
{
    return ParseSex (person) == person.sex;
}



int Validator::ParseBDate (const Person & person)
{
    if (person.ptn.size () < 5) {
        ValidatorExceptionBDate e ("Parse date error. String too short.");
        throw e;
    }

    return std::stoi (person.ptn.substr (0, 5), nullptr);
}



Sex Validator::ParseSex (const Person & person)
{
    if (person.ptn.size () < 9) {
        ValidatorExceptionSex e ("Parse sex error. String too short.");
        throw e;
    }

    const int x = person.ptn [8] - '0';
    return (x & 1) ? Sex::Male
                   : Sex::Female;
}

