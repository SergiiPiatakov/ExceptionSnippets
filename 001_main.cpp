#include <cstdlib>


int A (int v)
{
    if (v % 2)          // Validate input parameters.
        return 1;       // Return an error if it doesn't fit.
                        // Imagine that here we do subtask A.
    return 0;           // Notify success.
}


int B (int v)
{
    if (v > 42)         // Validate input parameters.
        return 2;       // Return an error if it doesn't fit.
                        // Imagine that here we do subtask B.
    return 0;           // Notify success.
}


int C (int v)
{
    int ret = A (v);    // Try to do subtask A.
    if (ret == 0)       // Ensure that there is no error.
        ret  = B (v);   // Try to do subtask B.

    return ret;         // Return a common result.
}


int main (int argc, char **)
{
    if (C (argc) )      // Check a common result.
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
