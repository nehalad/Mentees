/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>
#include "U8glib.h"
int sniperShots=0;
int RECV_PIN = 3;
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);  // Display which does not send AC

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if(results.value==0xF20A40BF)//Sniper Shots
    {
      sniperShots=sniperShots+1;
    }
    if(results.value==0xF20AE817)//Pistol Shots
    {
      sniperShots=sniperShots+1;
    }
    
    Serial.println(sniperShots);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
   u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
}

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_courB24);
  //u8g.setFont(u8g_font_osb21);
  char buf[9];
  sprintf (buf, "%d", sniperShots);
  u8g.drawStr( 0, 32, buf);
}
