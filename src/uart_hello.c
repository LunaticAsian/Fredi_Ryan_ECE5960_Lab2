#include "uart_hello.h"

void echo_uppercase(const struct device *dev)
{
    char byte, up;

    do {
        #ifdef TESTING_ENV
            
            if (test_uart_in() != 0) {
            continue;
        }
#else
        if (uart_poll_in(dev, &byte) != 0)
        {
            continue;
        }
        #endif
        
        if (byte <= 'z' && byte >= 'a')
            up = byte - 'a' + 'A';

        else
            up = byte;
            
        #ifdef TESTING_ENV
            test_uart_out();
        #else
            uart_poll_out(dev, up);

        #endif
    } while(byte != '\n');
}
