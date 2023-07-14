# MBED-library-for-Serial-print-float-string--int
Una opcion mas facil para imprimir en puerto serial para STM32:

La libreria se diseño a partir de la API de BufferdSerial
Asi entonces las funciones de la API tambien pueden ser utilizadas con normalidad teniendo en cuenta que BuefferdSerial ya se esta usando y esta declarado
ASI: "static BufferedSerial pc(USBTX,USBRX);"
Entonces si se requiere utilizar una funcion de la API BufferdSerial tiene que hacerse sabiendo que está referenciada con el objeto "pc"

Las funciones a las que tiene acceso el usuario son las siguientes:
 void printf(float f) -->> Para imprimir un valor flotante con tres decimales
 void printfln(float f) -->> Para imprimir un valor flotante con tres decimales y hacer un salto de linea al final
 void printd(int d) -->> Para imprimir un valor entero
 void printdln(int d) -->> Para imprimir un valor entero y hacer un salto de linea al final
 void printc(string c) -->> Para imprimir una cadena de texto
 void printcln(string c) -->> Para imprimir una cadena de texto y hacer un salto de linea

 El codigo de ejemplo se encuentra en main.cpp
 
