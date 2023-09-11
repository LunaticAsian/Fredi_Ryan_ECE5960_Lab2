#include "uart_hello.h"


//need to fix file path for uart hello include header file
void echo_uppercase(const struct device *dev)
{
    char byte, up;

    do {
        #ifdef TESTING_ENV
            test_uart_in();
        {

        }
        #else
        if (uart_poll_in(dev, &byte) != 0) {
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
