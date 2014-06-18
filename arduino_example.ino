/*
  AD5204 - Arduino Example
  www.danielandrade.net - daniel spillere andrade
  https://github.com/dansku/ad5204
  June 2014  
*/

#include "SPI.h"    // SPI Library
  
const int CS = 10;    // Chip Select For the AD5204

//----[Setup]------------------------

void setup()
{

  SPI.begin(); // start SPI bus. 
  SPI.setBitOrder(MSBFIRST); 

}

//----[Loop]--------------------------

void loop()
{

  //Set resistance from 0% to 100% in all output
  for(int i=0;i<4;i++){
    for(int j=0;j<255;j++){
      setPot(i,j);
      delay(100);
    }
  }

}

//----[Functions]--------------------

// POT value: 0 -> 3
// LEVEL valeu: 0 -> 254 (8 bits)

void setPot(int POT, int LEVEL){ 
  digitalWrite(CS, LOW);
  SPI.transfer(POT);
  SPI.transfer(LEVEL);
  digitalWrite(CS, HIGH);
}
