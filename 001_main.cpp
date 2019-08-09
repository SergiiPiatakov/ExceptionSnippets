#include <cstdlib>


int A (int v)
{
    if (v % 2)
        return 1;

    return 0;
}


int B (int v)
{
    if (v > 42)
        return 2;

    return 0;
}


int C (int v)
{
    int ret = A (v);
    if (ret == 0) {
        ret  = B (v);
    }

    return ret;
}


int main (int argc, char **)
{
    if (C (argc) ) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
