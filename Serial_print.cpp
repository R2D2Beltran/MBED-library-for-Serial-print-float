#include "mbed.h"
#include <math.h>
static BufferedSerial pc(USBTX,USBRX);

class Serial{
    protected:
        float flotante=0;
        int parte_Entera=0;
        int parte_Decimal=0;
        int cantidad_de_caracteres=0;

        int count_int=0;
        int count_dec=0;
        int aux_entero=0;
        int aux_decimal=0;
        int aux_flotante=0;

        int baudrate=0;
        
        
    public:
        //constructor que recibe el numero flotante y cantidad de caracteres maxima del flotante
        Serial(int baud) : baudrate (baud){
        pc.set_baud(baudrate);
        }
    
    protected:

        virtual void float_to_int()=0;
        virtual void count_digitos()=0;
        virtual void send_to_portSerial()=0;
        virtual void reset()=0;

};

class Serialf : public Serial{
    public: 
        Serialf (int baud) : Serial(baud){}    
        void printf(float f){
            this->flotante=f;
            float_to_int();
            count_digitos();
            send_to_portSerial();
            reset();
        }
    protected:
        void count_digitos() override{

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
        void float_to_int()override{
        
            aux_flotante=abs(flotante);
            parte_Entera=int(aux_flotante);
            if(flotante>=0){
            parte_Decimal=int((flotante-parte_Entera)*1000);
            }else{
            parte_Decimal=int(abs((flotante+parte_Entera)*1000));    
            }
        } 
        void send_to_portSerial()override{
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
        void reset()override{
            flotante=0;
            parte_Entera=0;
            parte_Decimal=0;
            cantidad_de_caracteres=0;

            count_int=0;
            count_dec=0;
            aux_entero=0;
            aux_decimal=0;
            aux_flotante=0;

        }     
};

class Seriald : public Serial{
    private:
    int entero_in=0;
    public:
        Seriald (int baud) : Serial (baud){}

        void printd(int d){
            this->entero_in=d;
            float_to_int();
            count_digitos();
            send_to_portSerial();
            reset();
        }
    protected:
        void float_to_int()override{
            //parte_Entera=int(flotante);
            aux_entero=abs(entero_in);
        }
        void count_digitos()override{   
            if (aux_entero == 0) {
                    count_int = 1;
            } else {
                while (aux_entero > 0) {
                    aux_entero /= 10;
                    count_int++;
                }
            }
            cantidad_de_caracteres=count_int+2;
        }
        void send_to_portSerial()override{
            if(entero_in>=0){
                char mensaje[cantidad_de_caracteres];
                sprintf(mensaje,"%d\n\r",entero_in);
                pc.write(mensaje,sizeof(mensaje));
            }else{
                char mensaje[cantidad_de_caracteres+1];
                sprintf(mensaje,"%d\n\r",entero_in);
                pc.write(mensaje,sizeof(mensaje));
            }
        }
        void reset()override{
            flotante=0;
            parte_Entera=0;
            parte_Decimal=0;
            cantidad_de_caracteres=0;

            count_int=0;
            count_dec=0;
            aux_entero=0;
            aux_decimal=0;
            aux_flotante=0;
        }
};