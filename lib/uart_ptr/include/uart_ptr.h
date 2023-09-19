#pragma once

#ifdef TESTING_ENV
struct device {};
int test_uart_ptr_in(const struct device * some_dev, char *uart_register);
void test_uart_ptr_out(const struct device * some_dev, const char uart_register);
#else
#include <drivers/uart.h>

#endif

void echo_uppercase_ptr(const struct device *dev,
                        int (*uart_ptr_in)(const struct device *, unsigned char *),
                        void (*uart_ptr_out)(const struct device *, unsigned char *));

                        