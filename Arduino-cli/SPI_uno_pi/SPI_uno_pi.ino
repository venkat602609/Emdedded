#include <SPI.h>

String s = "FROM SPI SLAVE \n Hello Venkata!!";
byte marker = 0;


void setup() {
  // have to send on master in, *slave out*
  pinMode(MISO, OUTPUT);
  


  // turn on SPI in slave mode
  SPCR |= _BV(SPE);

}

void loop (void)
{
  sendSPIData(s);
  
}

void sendSPIData(String s){

  int n = s.length();
  unsigned char char_arr[ n + 1 ];
  strcpy(char_arr,s.c_str());

  if((SPSR & (1 << SPIF)) != 0)
  {
    SPDR = char_arr[marker];
    marker++;
   
    if(marker > sizeof(char_arr))
    {
      marker = 0;
    }  
  }
}