/* Test of the Person library */

#include "Person.h"
#include <iostream>

int main(int argc, char** argv)
{
    int result = EXIT_FAILURE;
    try
    {
        Person testPerson {"3553207076", {"John", "Dou", "Jamecovych"}, {1997, 4, 13}, Sex::Male};
        result = !Validator::ValidatePerson(testPerson);
    }

    catch(PersonExceptions::InitializationException& e)
    {
        std::cout << e.what() << e.which() << std::endl;
    }

    catch(PersonExceptions::Exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    catch(...)
    {
        std::cout << "Unknown exception. Needs more investigation" << std::endl;
    }

    return result;
}