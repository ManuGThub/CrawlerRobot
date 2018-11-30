# include <16F877.h>
# use delay (clock=4000000)
# fuses XT, NOWDT, NOPUT, NOPROTECT
#byte puerto_b=6
#byte puerto_e=9
#byte tris_b=0x86
#byte tris_e=0x89
#bit sensorder = puerto_e.0 
#bit sensorizq = puerto_e.1

void main()
{
   tris_e=0b00000011; 
   tris_b=0b00000000;//designamos todo el puerto b como salida menos RB0

   while(TRUE)
   {
      while(sensorder==0&&sensorizq==0)
      {
         output_b(0b00011110);
      }
      while(sensorder==1&&sensorizq==0)
      {
         output_b(0b00011100);
      }
      while(sensorder==1&&sensorizq==1)
      {
         output_b(0b00011100);
      }
      while(sensorder==0&&sensorizq==1)
      {
         output_b(0b00010100);
      }
      while(sensorder==1&&sensorizq==1)
      {
         output_b(0b00010100);
      }
            
   }
     
}
