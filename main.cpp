#include "mbed.h"
#include "Serial_print.cpp"
#include "Serial_print.h"

int main()  
{   
    //Ambas velocidades de transmision deben ser las mismas
    //Las velocidades estan en Serial_print.h, toca agregar las demas
    Serialf serialf = Serialf(baud_rate1); //establecer baud_rate creacion de objeto serialf para envio de numeros flotantes
    Seriald seriald = Seriald(baud_rate1); //establecer baud_rate creacion de objeto seraild para envio de enteros
    Serialc serialc = Serialc(baud_rate1);
    string saludo="Hola amigos de youtube :p como estan";
    serialc.printcln(saludo);
    while (true) {
        //para agregar los saltos de linea se incluye "ln" en el nombre de la funcion
        //printcln()   -   printfln()   -   printdln()
        //"c" de caracteres
        //"d" de enteros
        //"f" de flotantes
        serialc.printc("cuantos años tienes\r\n"); //tambien se puede usar \r y \n si es necesario
        serialc.printc("sapa, tengo ");
        seriald.printd(21);
        serialc.printc(" años y tu ");
        serialf.printfln(-99.02);
    }
}

