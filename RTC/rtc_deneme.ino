#include <RTClib.h>
#include <Wire.h>
RTC_DS1307 RTC;

void setup () {
    
    Serial.begin(9600);
    Wire.begin();
    RTC.begin();
    if (! RTC.isrunning()) {
    Serial.println("RTC calismiyor");
    }
    RTC.adjust(DateTime(2019,03,24,14,03,00));  // tarih ve saat bilgisi ayarlanıyor...burada başlangıç ayarları yapılıyor..
  }


void loop () {
    DateTime now = RTC.now();
    Serial.print("Tarih:");
    Serial.print(now.day(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.year(), DEC);
    Serial.print(' ');
    Serial.print("Saat :");
    if (now.hour()<10)
    Serial.print('0');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    if (now.minute()<10)
    Serial.print('0');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    if (now.second()<10)
    Serial.print('0');
    Serial.print(now.second(), DEC); 
    Serial.println('/');
    delay(1000);
}
