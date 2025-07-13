#ifndef _H_TESTER
#define _H_TESTER

#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_COLOR_GREY    "\x1b[90m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define ANSI_BOLD "\e[1m"

#define ERROR_COLOR ANSI_COLOR_RED ANSI_BOLD
#define PASS_COLOR  ANSI_COLOR_GREEN

#define ERROR_MESSAGE ERROR_COLOR "\n === Test failed ===\n" ANSI_COLOR_RESET "\tTest: %s\n\tFile: %s:%d\n\n"
#define PASS_MESSAGE PASS_COLOR "\n === Every tests passed ===\n" ANSI_COLOR_RESET "\tTime: %f seconds!\n\n"

#define TEST_FAILED(test, file, line) printf(ERROR_MESSAGE, test, file, line)
#define TESTS_PASSED(time) printf(PASS_MESSAGE, time)

#define ASSERT(expr) \
    do { \
        if (!(expr)) { \
            TEST_FAILED(#expr, __FILE__, __LINE__); \
            exit(EXIT_FAILURE); \
        } \
    } while (0)

#endif
