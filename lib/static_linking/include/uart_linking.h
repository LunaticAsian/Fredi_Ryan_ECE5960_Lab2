#pragma once

#ifndef TESTING_ENV
#include <drivers/uart.h>
#else

struct device {};
#endif

void echo_uppercase_linking(const struct device *dev);