#include "map.h"


int add5(int x)
{
    return x + 5;
}

void example(void)
{
    int input[5] = {0, 1, 2, 3};
    int output[5];
    map(&input, &output, 4, add5);
}

char *test_data= "Hello World\n";
char *current_in;
char *expected;
//Echos back Uppercase char until new line
int test_uart_in(char *c)
{
    if(*current_in == '\n')
    {
        current_in = test_data;
    }
    else
        current_in++;

    *c = *current_in;
}

char *expected_data ="HELLO WORLD\n";
char *expected_in;
//Test input to the Uppercase transform
int test_uart_out(const char c)
{
    TEST_ASSERT_EQUAL_CHAR(*expected_in++, c);
}