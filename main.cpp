#include "mbed.h"
#include "envio_de_flotante.cpp"
// main() runs in its own thread in the OS
int main()  
{   
    
    while (true) {
        float float_to_send=76.912;
        Serial (float_to_send*1);
        /*
        for (float i = 0.0; i < 360.0; i += 1){
                 Serial((0.5 * (sinf(i * 3.14159265 / 180.0) + 1))*1000);
        }
        */
        
    }
}

