#include<SoftwareSerial.h>
#include<TinyGPS++.h>
static const int TX=7, RX=8;
static const uint32_t GPSBaud=9600;
SoftwareSerial p ( TX, RX);
TinyGPSPlus gps ;
void setup()
{
  Serial.begin (9600);
  p.begin (GPSBaud);
}
void loop ()
{
  while (p.available ()>0)
  
    gps.encode (p.read());
    
    if (gps.location.isUpdated())
    {
   Serial.print ("Latitude= ");
   Serial.print (gps.location.lat(),6);//lau ket qua sau dau phay den sau chu so
   Serial.print ("Longtitude= ");
   Serial.print (gps.location.lng(),6);
   Serial.print ("date= ");
   Serial.print (gps.date.value());
   Serial.print ("Year= ");
   Serial.print (gps.date.year());
   Serial.print ("Month= ");
   Serial.print (gps.date.month());
   Serial.print ("Day= ");
   Serial.print (gps.date.day());
   Serial.print (gps.time.value());
   // hour (0-23)
   Serial.print ("Hour= ");
   Serial.print (gps.time.hour());
   //minute (0-59)
   Serial.print ("Minute= ");
   Serial.print (gps.time.minute());
   // Second (0-59)
   Serial.print ("Second= ");
   Serial.print (gps.time.second());
   Serial.print ("Centisecond= ");
   Serial.print (gps.time.centisecond());
   //Number of satellites in use
   Serial.print ("Number os satellites in use= ");
   Serial.print (gps.satellites.value());
    }
  
    
  
}

