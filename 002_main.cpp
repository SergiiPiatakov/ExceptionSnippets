#include <cstdlib>


void A (int v)
{
    if (v % 2)          // Validate input parameters.
        throw 1;        // Throw an exception if it doesn't fit.
                        // Imagine that here we do subtask A.
}


void B (int v)
{
    if (v > 42)         // Validate input parameters.
        throw 2;        // Throw an exception if it doesn't fit.
                        // Imagine that here we do subtask B.
}


void C (int v)
{
    A (v);              // Try to do subtask A.
    B (v);              // Try to do subtask B.
}


int main (int argc, char **)
{
    try {
        C (argc);
    }
    catch (...) {       // Handle all exceptions.
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
