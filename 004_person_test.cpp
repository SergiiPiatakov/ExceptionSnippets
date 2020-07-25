/* Test of the Person library */

#include "Person.h"
#include <iostream>

int main(int argc, char** argv)
{
    Person testPerson {"35541070456", {"John", "Dou", "Jamecovych"}, {1997, 4, 13}, Sex::Male};

    int result = !Validator::ValidatePerson(testPerson);

    return result;
}