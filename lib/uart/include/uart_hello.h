#pragma once

#ifdef TESTING_ENV
struct device {};

int test_uart_out(char c);
int test_uart_in(char *c);

#else
#include <drivers/uart.h>

#endif

void echo_uppercase(const struct device *dev);

