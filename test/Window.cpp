#include "TestBase.h"

/**
 * @brief Main function.  Creates a game class and executes.
 * @param argc Number of arguments being passed to program.
 * @param argv[] List of arguments passed to program.
 * @return Status of whether run was successful or not.
 */
int main(int argc, const char *argv[])
{
    TestBase windowTest;

    return windowTest.execute();
}
