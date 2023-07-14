#include "mbed.h"
#include <math.h>
static BufferedSerial pc(USBTX,USBRX);

class Serial{
    private:
        float flotante=0;
        int parte_Entera=0;
        int parte_Decimal=0;
        int cantidad_de_caracteres=0;

        int count_int=0;
        int count_dec=0;
        int aux_entero=0;
        int aux_decimal=0;
        int aux_flotante=0;
        
        
    public:
        //constructor que recibe el numero flotante y cantidad de caracteres maxima del flotante
        Serial(float f) : flotante (f){
        float_to_int();
        count_digitos();
        send_to_portSerial(); 
        }
    
    private:
        void float_to_int(){
            aux_flotante=abs(flotante);
            parte_Entera=int(aux_flotante);
            if(flotante>=0){
            parte_Decimal=int((flotante-parte_Entera)*1000);
            }else{
            parte_Decimal=int(abs((flotante+parte_Entera)*1000));    
            }
        }

        void count_digitos(){

            aux_entero=parte_Entera;
            aux_decimal=parte_Decimal;

            if (aux_entero == 0) {
                count_int = 1;
            } else {
                while (aux_entero > 0) {
                    aux_entero /= 10;
                    count_int++;
                }
            }

            if (aux_decimal == 0) {
                count_dec = 1;
            } else {
                while (aux_decimal > 0) {
                    aux_decimal /= 10;
                    count_dec++;
                }
            }
            cantidad_de_caracteres=count_int+count_dec+4;

        }

        void send_to_portSerial(){
            if(flotante>=0){    
                if (parte_Decimal>=100){
                    char mensaje[(cantidad_de_caracteres)];
                    sprintf(mensaje,"%d.%d\n\r", parte_Entera,parte_Decimal);
                    pc.write(mensaje,sizeof(mensaje));
                }else if(parte_Decimal<100 && parte_Decimal>=10){
                    char mensaje[(cantidad_de_caracteres+1)];
                    sprintf(mensaje,"%d.0%d\n\r", parte_Entera,parte_Decimal);
                    pc.write(mensaje,sizeof(mensaje));
                }else{
                    char mensaje[(cantidad_de_caracteres+2)];
                    sprintf(mensaje,"%d.00%d\n\r", parte_Entera,parte_Decimal);
                    pc.write(mensaje,sizeof(mensaje));
                }
            }else{
                if (parte_Decimal>=100){
                    char mensaje[(cantidad_de_caracteres+1)];
                    sprintf(mensaje,"-%d.%d\n\r", parte_Entera,parte_Decimal);
                    pc.write(mensaje,sizeof(mensaje));
                }else if(parte_Decimal<100 && parte_Decimal>=10){
                    char mensaje[(cantidad_de_caracteres+2)];
                    sprintf(mensaje,"-%d.0%d\n\r", parte_Entera,parte_Decimal);
                    pc.write(mensaje,sizeof(mensaje));
                }else{
                    char mensaje[(cantidad_de_caracteres+3)];
                    sprintf(mensaje,"-%d.00%d\n\r", parte_Entera,parte_Decimal);
                    pc.write(mensaje,sizeof(mensaje));
                }
            }
        }
};