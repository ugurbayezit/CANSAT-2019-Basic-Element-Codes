#include <Adafruit_GPS.h> //Adafruit GPS kütüphanesi yükle
#include <SoftwareSerial.h> // Software Serial library yükle.Serial port olustuyormus gibi islem yapar.
SoftwareSerial mySerial(3,2); // GPS serial portlarini nereye bagladigimizi atadik.
Adafruit_GPS GPS(&mySerial); //GPS in myserial portlarina baglandigini belirttik.

String NMEA1; // Ilk NMEA cümlesi için degisken atandi.
String NMEA2;  // Ikinci NMEA cümlesi için degisken atandi.
char c; // GPS ten gelen karakterleri okumak için karakter atandi.

void setup() {
 Serial.begin(115200); // Serial ekranini açar.
 GPS.begin(9600); // GPS'i 9600 baud'da çalistirir.
 GPS.sendCommand("$PGCMD,33,0*6D"); // Gereksiz bilgi gelmemesi için antenden gelen güncellemeler kapatildi.Harita bilgisi almaya gerek yok.
 GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ); // Data güncellemesi 10 Hz'e ayarlandi.
 GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);// Sadece RMS ve GGA satirlarini okur.
 delay(1000); 

}

void loop() {
  
 readGPS(); // GPS verileri okumasi için fonksiyon olusturuldu.
 
  
}

void readGPS() {
clearGPS(); // Delay verdigimizde eski gerekesiz bilgi olmasin diye her yeni blgi için fonksiyon temizlendi.
 
 while(!GPS.newNMEAreceived()) { //Dogru okuma alana kadar döngü devam etsin.
 c=GPS.read(); //GPS.newNMEAReceived dogru(1) olana kadar c karakterini okur.
 }

 GPS.parse(GPS.lastNMEA()); // Son okunan dogru bilgiyi ayristir.
 NMEA1=GPS.lastNMEA(); //Son okunup ayristirilan dogru bilgi ilk NMEA cümlesine atansin. 


 while(!GPS.newNMEAreceived()) { //Dogru okuma alana kadar döngü devam etsin.
 c=GPS.read(); //GPS.newNMEAReceived dogru(1) olana kadar c karakterini okur.
 }

 GPS.parse(GPS.lastNMEA()); // Son okunan dogru bilgiyi ayristir.
 NMEA2=GPS.lastNMEA(); //Son okunup ayristirilan dogru bilgi ikinci NMEA cümlesine atansin. 

Serial.print("\nTime: ");
    Serial.print(GPS.hour, DEC); Serial.print(':');
    Serial.print(GPS.minute, DEC); Serial.print(':');
    Serial.print(GPS.seconds, DEC); Serial.print('.');
    Serial.println(GPS.milliseconds);
    Serial.print("Date: ");
    Serial.print(GPS.day, DEC); Serial.print('/');
    Serial.print(GPS.month, DEC); Serial.print("/20");
    Serial.println(GPS.year, DEC);
    Serial.print("Fix: "); Serial.print((int)GPS.fix);
    Serial.print(" quality: "); Serial.println((int)GPS.fixquality); 
    if (GPS.fix) {
      Serial.print("Location: ");
      Serial.print(GPS.latitude, 4); Serial.print(GPS.lat);
      Serial.print(", "); 
      Serial.print(GPS.longitude, 4); Serial.println(GPS.lon);
      
      Serial.print("Speed (knots): "); Serial.println(GPS.speed);
      Serial.print("Angle: "); Serial.println(GPS.angle);
      Serial.print("Altitude: "); Serial.println(GPS.altitude);
      Serial.print("Satellites: "); Serial.println((int)GPS.satellites);
  Serial.print(GPS.longitude,4); //Write measured longitude to file
  Serial.print(GPS.lon); //Which Hemisphere E or W
  Serial.print(",");
  Serial.println(GPS.altitude);
  Serial.println(NMEA1);
  Serial.println(NMEA2);
 }
}

void clearGPS() {
  while(!GPS.newNMEAreceived()) { //Dogru okuma alana kadar döngü devam etsin.
 c=GPS.read(); //GPS.newNMEAReceived dogru(1) olana kadar c karakterini okur.
 }

 GPS.parse(GPS.lastNMEA()); // Son okunan dogru bilgiyi ayristir.

 while(!GPS.newNMEAreceived()) { //Dogru okuma alana kadar döngü devam etsin.
 c=GPS.read(); //GPS.newNMEAReceived dogru(1) olana kadar c karakterini okur.
 }

 GPS.parse(GPS.lastNMEA()); // Son okunan dogru bilgiyi ayristir.

 while(!GPS.newNMEAreceived()) { //Dogru okuma alana kadar döngü devam etsin.
 c=GPS.read(); //GPS.newNMEAReceived dogru(1) olana kadar c karakterini okur.
 }

 GPS.parse(GPS.lastNMEA()); // Son okunan dogru bilgiyi ayristir.


}
