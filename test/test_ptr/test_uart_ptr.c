#include <unity.h>
#include "uart_ptr.h"

char *test_sequence = "ECE 6960 Lab 02!\n";
char *current_test_byte;

int test_uart_ptr_in(const struct device * some_dev, char *uart_register)
{
    /*Make byte available to the echo_uppercase_conditional() function*/
    *uart_register = *current_test_byte;

    /*If pointer reachs end of sequence, wrap around.*/
    if (*current_test_byte == '\n')
    {
        current_test_byte = test_sequence;
    }
    else
        /*Increment pointer for next iteration*/
        current_test_byte++;
    return 1;
}

char *expected_sequence = "ECE 6960 LAB 02!\n";
char *current_expected_byte;

void test_uart_ptr_out(const struct device * some_dev, const char uart_register)
{
    /*Compare the byte processed by echo_uppercase() against the expected sequence.*/
    TEST_ASSERT_EQUAL_CHAR(*current_expected_byte++, uart_register);
}

void setUp(void)
{
    /*Initialize byte pointers to the first bytes in the sequences*/
    current_test_byte = test_sequence;
    current_expected_byte = expected_sequence;
}

void tearDown()
{
}

void test_echo_upper(void)
{
    echo_uppercase_ptr((struct device *)0, (*test_uart_ptr_in), (*test_uart_ptr_out));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_echo_upper);
    return UNITY_END();
}
