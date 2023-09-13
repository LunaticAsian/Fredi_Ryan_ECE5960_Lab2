#pragma once

#ifdef TESTING_ENV
struct device {};

*uart_ptr_in();
*uart_ptr_out();

#else
#include <drivers/uart.h>

#endif

void echo_uppercase_ptr(const struct device *dev);