#pragma once
#include "uart_ptr.h"

void echo_uppercase_ptr(const struct device *dev,
                        int (*uart_ptr_in)(const struct device *, unsigned char *),
                        void (*uart_ptr_out)(const struct device *, unsigned char *))
{
    char byte, up;

    do
    {
        if( uart_ptr_in(dev, &byte) !=0 )
            continue;

        if (byte <= 'z' && byte >= 'a')
            up = byte - 'a' + 'A';
        else
            up = byte;

        (*uart_ptr_out)(dev,up);
    }
    while(byte != '\n');
}