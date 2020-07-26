#include "Person.h"

namespace PersonExceptions
{
    const char *Exception::what() const noexcept
    {
        return "There are some problems with Person library";
    }

    InvalidSexIpnIdx::InvalidSexIpnIdx(const size_t idx) : SexIdx(idx) {}

    const char *InvalidSexIpnIdx::what() const noexcept
    {
        return "Ipn has no index for field 'sex'. Requested index: ";
    }

    size_t InvalidSexIpnIdx::which() const
    {
        return SexIdx;
    }

    InitializationException::InitializationException(const std::string pmtr) : parameter(pmtr) {}

    const char *InitializationException::what() const noexcept
    {
        return "The person's date was initialized incorrectly It may cause some errors in future. The error was found in: ";
    }

    std::string InitializationException::which() const
    {
        return parameter;
    }

} // namespace PersonExceptions

bool Validator::ValidatePerson(const Person &person)
{
    return ValidateSex(person) && ValidateBDate(person);
}

bool Validator::ValidateBDate(const Person &person)
{
    const int secToDays = 60 * 60 * 24; // The number of seconds in one day.
    const int daysOffset = 25567;       // The number of days between 1900 and 1970.
    const int daysOboe = 1;             // Off-by-one error correction.

    Date a{1970, 1, 1};
    Date b = person.bdate;
    const std::time_t c = std::mktime(&a);
    const std::time_t d = std::mktime(&b);
    int days = (std::difftime(d, c)) / secToDays + daysOffset + daysOboe;

    return ParseBDate (person) == days;
}

bool Validator::ValidateSex(const Person &person)
{
    bool result = false;
    try
    {
        result = ParseSex (person) == person.sex;
    }

    catch (PersonExceptions::InvalidSexIpnIdx &e)
    {
        std::cout << e.what() << e.which() << std::endl;
    }

    return result;
}

int Validator::ParseBDate(const Person &person)
{
    int result = 0;

    try
    {
        result = std::stoi(person.ptn.substr(0, 5), nullptr);
    }

    catch (const std::out_of_range &e)
    {
        std::cout << e.what() << std::endl;
    }

    catch (const std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
    }

    return result;
}

Sex Validator::ParseSex(const Person &person)
{
    const size_t SexIdx = 8; // Index where is Person's sex defined

    if (person.ptn.size() < SexIdx + 1)
    {
        throw PersonExceptions::InvalidSexIpnIdx(SexIdx);
    }

    const int x = person.ptn[SexIdx] - '0';
    return (x & 1) ? Sex::Male
                   : Sex::Female;
}
