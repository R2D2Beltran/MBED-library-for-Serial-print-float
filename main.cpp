#include "mbed.h"
#include "Serial_print.cpp"
#include "Serial_print.h"
#include <cstdint>

// main() runs in its own thread in the OS
int main()  
{   
    //Ambas velocidades de transmision deben ser las mismas
    Serialf serialf=Serialf(baud_rate1); //establecer baud_rate creacion de objeto serialf para envio de numeros flotantes
    Seriald seriald=Seriald(baud_rate1); //establecer baud_rate creacion de objeto seraild para envio de enteros
    while (true) {
        
        float flotan=8100.912;
        int i=56;
        serialf.printf(-164.092); //imprime flotante con tres decimales y hace salto de linea
        serialf.printf(flotan); 
        seriald.printd(-i);       //imprime entero y hace salto de linea
        seriald.printd(-89.092);    //trunca imprime y hace salto de linea
        
        /*
        for (float i = 0.0; i < 360.0; i += 1){
                int senoo=0.5 * (sinf(i * 3.14159265 / 180.0))*999999999;//1000000000  999999999
                 seriald.printd(senoo);
        }
        */
        //ThisThread::sleep_for(500ms);
    }
}

