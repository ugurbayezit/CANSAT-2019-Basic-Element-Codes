int analogInput = 0;
float vout = 0.0;
float vin = 0.0;
float R1 = 100000.0; // 100K ohm direnç
float R2 = 10000.0; // 10K ohm direnç
int value = 0;
void setup(){
   pinMode(analogInput, INPUT);
   Serial.begin(9600);
   
}
void loop(){
   // read the value at analog input
   value = analogRead(analogInput);
   vout = (value * 9.0) / 1024.0; 
   vin = vout / (R2/(R1+R2)); 
   if (vin<0.09) {
   vin=0.0;
} 
 Serial.println(vout);
   delay(500);
}
