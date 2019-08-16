#include <cstdlib>
#include <iostream>
#include "Person.h"

int main (int, char **)
{
    try {
        //Person person {"2930000022", {}, {1980, 3, 21}, Sex::Female};
        Person person {"", {}, {1800, 3, 21}, Sex::Female};
        Validator::ValidatePerson (person);
    }
    catch (ValidatorExceptionSex & e) {
        std::cout << "Sex validation exception: " << e.what () << "." << std::endl;
        return EXIT_FAILURE;
    }
    catch (ValidatorExceptionBDate & e) {
        std::cout << "Date validation exception: " << e.what () << "." << std::endl;
        return EXIT_FAILURE;
    }
    catch (ValidatorException & e) {
        std::cout << "General validation exception: " << e.what () << "." << std::endl;
        return EXIT_FAILURE;
    }
    catch (std::exception & e) {
        std::cout << "General standart exception: " << e.what () << "." << std::endl;
        return EXIT_FAILURE;
    }
    catch (...) {
        // Error handling (loging etc).
        std::cout << "Unknown exception." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
