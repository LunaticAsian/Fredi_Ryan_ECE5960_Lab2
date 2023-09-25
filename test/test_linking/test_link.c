#include <unity.h>
#include "uart_linking.h"

unsigned char *test_sequence = "ECE 6960 Lab 02!\n";
unsigned char *current_test_byte;

int uart_poll_in(const struct device *dev, unsigned char *p_char)
{
    /*Make byte available to the echo_uppercase_conditional() function*/
    *p_char = *current_test_byte;

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

void uart_poll_out(const struct device *dev, unsigned char out_char)
{
    /*Compare the byte processed by echo_uppercase() against the expected sequence.*/
    TEST_ASSERT_EQUAL_CHAR(*current_expected_byte++, out_char);
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

void test_echo_uppercase(void)
{
    echo_uppercase_linking((struct device *)0);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_echo_uppercase);
    return UNITY_END();
}
