#include<SoftwareSerial.h>
// setup RX=7, TX=8
static const int TX=7, RX=8;
SoftwareSerial p (RX, TX);
void setup()
{
  Serial.begin(9600);
  p.begin (9600);
  Serial.println ("khoi tao...");
  delay(1000);
  p.println ("AT"); // connect with sim
  updateSerial();
  //make call
  p.println("ATD+84328483766;");
  updateSerial();
  delay(10000);
  p.println ("ATH");//hang up
  updateSerial();
 //send mess
  p.println ("AT+CMGF=1"); //mess under text
  updateSerial();
  p.println ("AT+CMGS=\+84328483766\""); // 84 la dau so cua tung nuoc
  updateSerial();
  p.print ("hay goi cho toi");
  
  
}


void loop()
{
  updateSerial();
}
void updateSerial()
{
  delay(500);
  while (Serial.available())
  {
    p.write(Serial.read());//forward what serial received to Sofware Serial port
    
  }
  while (p.available())
  {
    p.write (Serial.read());// forward what software serial received to serial port
    
  }
}


