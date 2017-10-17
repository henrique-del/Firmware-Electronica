#include <16F883.h>
#use delay(int=4000000)
#define LARGO_FN 79                                //Longitud de Frase de Navidad
int const FelizNavidad[LARGO_FN+16]={              //Vector de Frase de Navidad
0,0,0,0,0,0,0,0,                                   //    8 espacios           
0x7F, 0x09, 0x09, 0x01, 0x01, 0x00,                // F
0x38, 0x54, 0x54, 0x54, 0x18, 0x00,                // e
0x00, 0x41, 0x7F, 0x40, 0x00, 0x00,                // l
0x00, 0x44, 0x7D, 0x40, 0x00, 0x00,                // i
0x44, 0x64, 0x54, 0x4C, 0x44, 0x00,                // z
0x00, 0x00, 0x00,                                  //    3 espacios 
0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00,                // N
0x20, 0x54, 0x54, 0x54, 0x78, 0x00,                // a
0x1C, 0x20, 0x40, 0x20, 0x1C, 0x00,                // v
0x00, 0x44, 0x7D, 0x40, 0x00, 0x00,                // i
0x38, 0x44, 0x44, 0x48, 0x7F, 0x00,                // d
0x20, 0x54, 0x54, 0x54, 0x78, 0x00,                // a
0x38, 0x44, 0x44, 0x48, 0x7F, 0x00,                // d
0x00, 0x5F, 0x00, 0x00,                            // !
0,0,0,0,0,0,0,0,                                   //    8 espacios  
};
int const ArbolNavidad[8]={                        //Vector del dibujo Arbol
0x20, 0x30, 0x3C, 0xFF, 0xFF, 0x3C, 0x30, 0x20
};
int const EstNavidad1[25][8]={                     //Vector animado 1
{0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81},
{0x02, 0xc2, 0x24, 0x18, 0x18, 0x24, 0x43, 0x40},
{0x04, 0x42, 0xa4, 0x18, 0x18, 0x25, 0x42, 0x20},
{0x08, 0x04, 0x64, 0x98, 0x19, 0x26, 0x20, 0x10},
{0x30, 0x08, 0x25, 0x59, 0x9a, 0xa4, 0x10, 0x0c},
{0xe1, 0x11, 0x09, 0x3a, 0x5c, 0x90, 0x88, 0x87},
{0x06, 0xf2, 0x8a, 0x3a, 0x5c, 0x51, 0x4f, 0x60},
{0x08, 0x34, 0x4a, 0xba, 0x5d, 0x52, 0x2c, 0x10},
{0x00, 0x18, 0x3c, 0x7e, 0x7e, 0x3c, 0x18, 0x00},
{0x00, 0x3c, 0x34, 0x3c, 0x3c, 0x34, 0x3c, 0x00},
{0x78, 0x3c, 0xf7, 0x3c, 0x3c, 0xf7, 0x3c, 0x78},
{0x1e, 0xbc, 0x77, 0x3c, 0x3c, 0x77, 0xbc, 0x1e},
{0x78, 0x3c, 0xf7, 0x3c, 0x3c, 0xf7, 0x3c, 0x78},
{0x1e, 0xbc, 0x77, 0x3c, 0x3c, 0x77, 0xbc, 0x1e},
{0x78, 0x3c, 0xf7, 0x3c, 0x3c, 0xf7, 0x3c, 0x78},
{0x1e, 0xbc, 0x77, 0x3c, 0x3c, 0x77, 0xbc, 0x1e},
{0x00, 0x16, 0x26, 0x20, 0x20, 0x26, 0x16, 0x00},
{0x00, 0x16, 0x26, 0x40, 0x40, 0x26, 0x16, 0x00},
{0x00, 0x16, 0x26, 0xc0, 0xc0, 0x26, 0x16, 0x00},
{0x00, 0x16, 0x26, 0x40, 0x40, 0x26, 0x16, 0x00},
{0x00, 0x16, 0x26, 0x20, 0x20, 0x26, 0x16, 0x00},
{0x00, 0x16, 0x26, 0x40, 0x40, 0x26, 0x16, 0x00},
{0x00, 0x16, 0x26, 0xc0, 0xc0, 0x26, 0x16, 0x00},
{0x00, 0x16, 0x26, 0x40, 0x40, 0x26, 0x16, 0x00},
{0x00, 0x16, 0x26, 0x20, 0x20, 0x26, 0x16, 0x00}
};
int const EstNavidad2[11][8]={                     //Vector animado 2
{0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x10, 0x1c, 0x38, 0x08, 0x00, 0x00},
{0x00, 0x10, 0x18, 0x3e, 0x7c, 0x18, 0x08, 0x00},
{0x00, 0x14, 0x58, 0x3e, 0x7c, 0x1a, 0x28, 0x00},
{0x10, 0x56, 0x58, 0x3f, 0xfc, 0x1a, 0x6a, 0x08},
{0x91, 0x56, 0x58, 0x3f, 0xfc, 0x1a, 0x6a, 0x89},
{0x10, 0x56, 0x58, 0x3f, 0xfc, 0x1a, 0x6a, 0x08},
{0x00, 0x14, 0x58, 0x3e, 0x7c, 0x1a, 0x28, 0x00},
{0x00, 0x10, 0x18, 0x3e, 0x7c, 0x18, 0x08, 0x00},
{0x00, 0x00, 0x10, 0x1c, 0x38, 0x08, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00}
};
int const EstNavidad3[7][8]={                     //Vector animado 3
{0x99, 0x5a, 0x3c, 0xff, 0xff, 0x3c, 0x5a, 0x99},
{0x18, 0x5a, 0x3c, 0xff, 0xff, 0x3c, 0x5a, 0x18},
{0x18, 0x18, 0x3c, 0xff, 0xff, 0x3c, 0x18, 0x18},
{0x18, 0x18, 0x18, 0xff, 0xff, 0x18, 0x18, 0x18},
{0x18, 0x18, 0x3c, 0xff, 0xff, 0x3c, 0x18, 0x18},
{0x18, 0x5a, 0x3c, 0xff, 0xff, 0x3c, 0x5a, 0x18},
{0x99, 0x5a, 0x3c, 0xff, 0xff, 0x3c, 0x5a, 0x99}
};
byte const bitMask[8]={1,2,4,8,16,32,64,128};      //Mascara
int i,j,k,x;                                       //Variables contadores
void fraseNavidad(int1 Neg){
   for(i=0;i<LARGO_FN+8;i++){                      //Recorrido de tabla
      for(k=0;k<20;k++){                           //Refresco de matriz
         for(j=0;j<8;j++){                         //Barrido de columnas
            output_a(~bitMask[j]);                 //Columnas ponderadas
            if(Neg)                                //Negativo
               output_c(~FelizNavidad[j+i]);       //Desplazamiento de tabla
            else                                   //Directo
               output_c(FelizNavidad[j+i]);        //Desplazamiento de tabla
            delay_us(350);                         //Demora de multiplexado
         }   
      }
   }
}
void animNavidad1(){
   for(i=0;i<25;i++){                              //Cambia de subVector
      for(k=0;k<30;k++){                           //Persistencia
         for(j=0;j<8;j++){                         //Barrido de columnas
            output_a(~bitMask[j]);                 //Columnas ponderadas
            output_c(EstNavidad1[i][j]);           //Desplazamiento de tabla
            delay_us(600);                         //Demora de multiplexado
         }   
      }
   }
}   
void animNavidad2(){
   for(i=0;i<11;i++){                              //Cambia de subVector
      for(k=0;k<30;k++){                           //Persistencia
         for(j=0;j<8;j++){                         //Barrido de columnas
            output_a(~bitMask[j]);                 //Columnas ponderadas
            output_c(EstNavidad2[i][j]);           //Desplazamiento de tabla
            delay_us(600);                         //Demora de multiplexado
         }   
      }
   }
}   
void animNavidad3(){
   for(i=0;i<7;i++){                               //Cambia de subVector
      for(k=0;k<30;k++){                           //Persistencia
         for(j=0;j<8;j++){                         //Barrido de columnas
            output_a(~bitMask[j]);                 //Columnas ponderadas
            output_c(EstNavidad3[i][j]);           //Desplazamiento de tabla
            delay_us(600);                         //Demora de multiplexado
         }   
      }
   }
}   
void dibujoArbol(int1 Neg){
   for(k=0;k<50;k++){                              //Persistencia
      for(j=0;j<8;j++){                            //Barrido de filas y columnas
         output_a(~bitMask[j]);                    //Columnas ponderadas
         if(Neg)                                   //Negativo
            output_c(~ArbolNavidad[j]);            //Desplazamiento de tabla
         else                                      //Directo
            output_c(ArbolNavidad[j]);             //Desplazamiento de tabla
         delay_us(700);                            //Demora de multiplexado
      }  
   }   
}
void main(){    
   while(TRUE){                                    //Funcion Principal Repetitiva
      for(x=0;x<6;x++){                            //Animacion de Navidad 3 veces
         animNavidad2();                           //Animacion de Navidad 
      } 
      for(x=0;x<10;x++){                           //Animacion de Navidad 3 veces
         animNavidad3();                           //Animacion de Navidad 
      }       
      for(x=0;x<3;x++){                            //Arbol de Navidad 3 veces
         dibujoArbol(FALSE);                       //Arbol de Navidad 
         dibujoArbol(TRUE);                        //Arbol de Navidad Invertido 
      }
      fraseNavidad(FALSE);                         //Frase de Navidad 
      for(x=0;x<3;x++){                            //Arbol de Navidad 3 veces
         dibujoArbol(FALSE);                       //Arbol de Navidad 
         dibujoArbol(TRUE);                        //Arbol de Navidad Invertido 
      } 
      for(x=0;x<3;x++){                            //Animacion de Navidad 3 veces
         animNavidad1();                           //Animacion de Navidad 
      }      
      fraseNavidad(TRUE);                          //Frase de Navidad Invertida
   }
}