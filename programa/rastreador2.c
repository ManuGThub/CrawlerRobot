//programa siguelineas principal con cambio de polaridad de motores en el caso de
//que se salga el microrobot del todo
//alimentacion con pila de 5.8 voltios

# include <16F877.h>
# use delay (clock=4000000)
# fuses XT, NOWDT, NOPUT, NOPROTECT
#include <LCD.c>
#byte puerto_a=5
#byte puerto_b=6
#byte puerto_e=9

#byte tris_a=0x85
#byte tris_b=0x86
#byte tris_e=0x89

#bit sensorizq = puerto_a.2
#bit sensorder = puerto_a.1
#bit motor_der = puerto_b.3
#bit motor_izq = puerto_b.4
#bit habilitacion_izq = puerto_b.2
#bit habilitacion_der = puerto_b.1
#bit marcader = puerto_e.2
//#bit marcader2 = puerto_a.3
//#bit marcaizq2 = puerto_e.1
#bit marcaizq = puerto_e.0

void linea_2()
{
   if(sensorder==0&&sensorizq==0)
   {
          printf(lcd_putc,"\f");
          lcd_gotoxy(7,1); //posicionar el caracter en la primera columna y la 1� fila
          printf(lcd_putc,"\LINEA");
         while(sensorder==0&&sensorizq==0)
         {
            motor_der=1;
            motor_izq=1;
            habilitacion_izq=1;
            habilitacion_der=1;
         }
   }
   if(sensorder==1&&sensorizq==0)
      {
         printf(lcd_putc,"\f");
         lcd_gotoxy(10,1); //posicionar el caracter en la primera columna y la 1� fila         
         printf(lcd_putc,"\DERECHA");
         while(sensorder==1&&sensorizq==0)
         {
            motor_izq=1;
            motor_der=1;
            habilitacion_izq=1;
            delay_us(300);
            habilitacion_izq=0;
            delay_us(700);
            habilitacion_der=1;       
         }
      
          if(sensorder==1&&sensorizq==1)
          {
             printf(lcd_putc,"\f");
             lcd_gotoxy(9,1); //posicionar el caracter en la primera columna y la 1� fila           
             printf(lcd_putc,"\DERECHA+");
             while(sensorder==1&&sensorizq==1)
             {
                motor_izq=0;
                motor_der=1;
                
                habilitacion_der=1;
                
                habilitacion_izq=1;
                delay_us(300);
                habilitacion_izq=0;
                delay_us(700);
                
             }
          }
      }
      if(sensorder==0&&sensorizq==1)
      {
         printf(lcd_putc,"\f");
         lcd_gotoxy(1,1); //posicionar el caracter en la primera columna y la 1� fila
         printf(lcd_putc,"\IZQUIERDA");
         while(sensorder==0&&sensorizq==1)
         {
            motor_izq=1;
            motor_der=1;
            habilitacion_der=1;
            delay_us(300);
            habilitacion_der=0;
            delay_us(700);
            habilitacion_izq=1;
         }
      
         if(sensorder==1&&sensorizq==1)
         {
            printf(lcd_putc,"\f");
            lcd_gotoxy(1,1); //posicionar el caracter en la primera columna y la 1� fila
            printf(lcd_putc,"\IZQUIERDA+");
            while(sensorder==1&&sensorizq==1)
            {
               motor_izq=1;
               motor_der=0;
              
               habilitacion_izq=1;
               habilitacion_der=1;
               delay_us(300);
               habilitacion_der=0;
               delay_us(700);
               
            }
            
         }
      }
}


void main()
{
   lcd_init();
   tris_a=0b00011110; 
   tris_b=0b00000000;//designamos todo el puerto b como salida menos RB0
   tris_e=0b00000111;
   
   motor_der=1;
   motor_izq=1;

   while(TRUE)
   {

      if(sensorder==0&&sensorizq==0&&marcader==1&&marcaizq==1)
      {
          printf(lcd_putc,"\f");
          lcd_gotoxy(7,1); //posicionar el caracter en la primera columna y la 1� fila
          printf(lcd_putc,"\LINEA");
         while(sensorder==0&&sensorizq==0&&marcader==1&&marcaizq==1)
         {
            motor_der=1;
            motor_izq=1;
            habilitacion_izq=1;
            habilitacion_der=1;
         }
      }
      if(sensorder==1&&sensorizq==0&&marcader==1&&marcaizq==1)
      {
         printf(lcd_putc,"\f");
         lcd_gotoxy(10,1); //posicionar el caracter en la primera columna y la 1� fila         
         printf(lcd_putc,"\DERECHA");
         while(sensorder==1&&sensorizq==0&&marcader==1&&marcaizq==1)
         {
            motor_izq=1;
            motor_der=1;
            habilitacion_izq=1;
            delay_us(300);
            habilitacion_izq=0;
            delay_us(700);
            habilitacion_der=1;       
         }
      
          if(sensorder==1&&sensorizq==1&&marcader==1&&marcaizq==1)
          {
             printf(lcd_putc,"\f");
             lcd_gotoxy(9,1); //posicionar el caracter en la primera columna y la 1� fila           
             printf(lcd_putc,"\DERECHA+");
             while(sensorder==1&&sensorizq==1&&marcader==1&&marcaizq==1)
             {
                  motor_izq=0;
                  motor_der=1;
                  habilitacion_izq=1;
                  delay_us(300);
                  habilitacion_izq=0;
                  delay_us(700);
                  habilitacion_der=1;
 
                
             }
          }
      }
      if(sensorder==0&&sensorizq==1&&marcader==1&&marcaizq==1)
      {
         printf(lcd_putc,"\f");
         lcd_gotoxy(1,1); //posicionar el caracter en la primera columna y la 1� fila
         printf(lcd_putc,"\IZQUIERDA");
         while(sensorder==0&&sensorizq==1&&marcader==1&&marcaizq==1)
         {
            motor_izq=1;
            motor_der=1;
            habilitacion_der=1;
            delay_us(300);
            habilitacion_der=0;
            delay_us(700);
            habilitacion_izq=1;
         }
      
         if(sensorder==1&&sensorizq==1&&marcader==1&&marcaizq==1)
         {
            printf(lcd_putc,"\f");
            lcd_gotoxy(1,1); //posicionar el caracter en la primera columna y la 1� fila
            printf(lcd_putc,"\IZQUIERDA+");
            while(sensorder==1&&sensorizq==1&&marcader==1&&marcaizq==1)
            {
                  motor_izq=1;
                  motor_der=0;
                  habilitacion_der=1;
                  delay_us(300);
                  habilitacion_der=0;
                  delay_us(700);
                  habilitacion_izq=1;
               
            }
            
         }
      }
         if(marcaizq==0)
         {
            printf(lcd_putc,"\f");
            lcd_gotoxy(1,1); //posicionar el caracter en la primera columna y la 1� fila           
            printf(lcd_putc,"\SALIDA IZQUIERDA");
            while(marcader==1)
            {

                if(sensorder==0&&sensorizq==1)
                {
                   motor_izq=1;
                   motor_der=1;
                   habilitacion_der=1;
                   habilitacion_izq=1;
                }
                if(sensorder==1&&sensorizq==1)
                {
                   motor_izq=1;
                   motor_der=0;
                   habilitacion_der=1;
                   delay_us(200);
                   habilitacion_der=0;
                   delay_us(800);
                   habilitacion_izq=1;
                }
                if(sensorder==0&&sensorizq==0)
                {
                   motor_izq=0;
                   motor_der=1;
                   habilitacion_der=1;
                   habilitacion_izq=1;
                   delay_us(450);
                   habilitacion_izq=0;
                   delay_us(550);
                }
            }
            while(marcader==0)
            {
               linea_2();
            }
          }
          if(marcader==0)
         {
            printf(lcd_putc,"\f");
            lcd_gotoxy(2,1); //posicionar el caracter en la primera columna y la 1� fila           
            printf(lcd_putc,"\SALIDA DERECHA");
            while(marcaizq==1)
            {

                if(sensorder==1&&sensorizq==0)
                {
                   motor_izq=1;
                   motor_der=1;
                   habilitacion_der=1;
                   habilitacion_izq=1;
                }
                if(sensorder==1&&sensorizq==1)
                {
                   motor_izq=0;
                   motor_der=1;
                   habilitacion_der=1;
                   habilitacion_izq=1;
                   delay_us(200);
                   habilitacion_izq=0;
                   delay_us(800);
                }
                if(sensorder==0&&sensorizq==0)
                {
                   motor_izq=1;
                   motor_der=0;
                   habilitacion_der=1;
                   delay_us(450);
                   habilitacion_der=0;
                   delay_us(550);
                   habilitacion_izq=1;
                }
            }
            while(marcaizq==0)
            {
               linea_2();
            }
          }
         
     }
     
}
