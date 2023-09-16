#include <unity.h>
#include "test_uart_ptr.h"


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



int main (void)
{
    UNITY_BEGIN();
    //call tests
    return UNITY_END();
}