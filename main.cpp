#include "mbed.h"
#include "envio_de_flotante.cpp"
// main() runs in its own thread in the OS
int main()  
{   
    pc.set_baud(115200);
    while (true) {
        float flotan=86.912;
        int enter=86;
        Serialf arur(flotan); //envio de numero flotante
        Seriald artur(enter); //envio de numero entero
        
        /*for (float i = 0.0; i < 360.0; i += 1){
                float senoo=0.5 * (sinf(i * 3.14159265 / 180.0))*1000000;
                 Seriald asi(senoo);
        }*/
    }
}

