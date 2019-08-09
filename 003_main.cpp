#include <cstdlib>


void A (int v) throw ()
{
    if (v % 2)
        throw 1;
}


void B (int v) throw (int)
{
    if (v > 42)
        throw 2;
}


void C (int v) throw (int)
{
    A (v);
    B (v);
}


int main (int argc, char **)
{
    try {
        C (argc);
    }
    catch (...) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
