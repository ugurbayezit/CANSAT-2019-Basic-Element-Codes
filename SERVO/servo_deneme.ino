#include <Servo.h>  /* Servo kutuphanesi projeye dahil edildi */
Servo servoNesnesi;  /* servo motor nesnesi yaratildi */
#define buton 10
int durum = 0;
int sayac=0;
void setup()
{
  Serial.begin(9600);
  servoNesnesi.attach(9);  /* Servo motor 9 numarali pine baglandi */
  pinMode(buton,INPUT);
}
 
void loop()
{
  durum= digitalRead(buton);
  if(durum==HIGH)
  { 
    sayac=sayac+1;
    Serial.println(sayac);
    if(sayac==1)
    {
      servoNesnesi.write(90);
      delay(100);
    }
    else if (sayac==2)
    {
      servoNesnesi.write(-90);
      sayac=0;
      delay(100);
    }
    delay(100);
  }
//  if (sayac=='49')
//  {
//    servoNesnesi.write(90);
//    Serial.print(sayac);
//  }
//  else
//  {
//    servoNesnesi.write(0);
//  }
   
     /* Motor mili 20. dereceye donuyor */
}
