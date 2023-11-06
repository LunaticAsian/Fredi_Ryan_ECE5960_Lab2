#pragma once

#ifndef TESTING_ENV
#include <drivers/uart.h>
#else
int test_uart_in(char * c);
void test_uart_out(char c);
struct device {};
#endif

void echo_uppercase_conditional(const struct device *dev);