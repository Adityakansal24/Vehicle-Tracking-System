#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12,11, 10, 9,8);
#include <SoftwareSerial.h>
SoftwareSerial mySerial1(5,6);
int as1 = 7;
int s1Value;
int os1 = 0;
int t,s,q = 0;
unsigned char  da8[500];
void setup() 
 {
  pinMode(as1 ,INPUT);
  mySerial1.begin(9600); 
  Serial.begin(9600);
  lcd.begin(20, 4);
  lcd.setCursor(0, 0);
  lcd.print("GPS GSM BASED");
  Serial.println("GPS GSM BASED");
  lcd.setCursor(0, 1);
  lcd.print("TRACKING SYSTEM");
  Serial.println("TRACKING SYSTEM");
  lcd.setCursor(0, 2);
  lcd.print("WELCOME TO ALL ");
  Serial.println("WELCOME TO ALL");
  delay(3000);            
  lcd.clear();
  int byte=0;
  Serial.println("GSM START");
  Serial.print("AT");
  Serial.print(0x0D,byte);
  delay(1000);
  Serial.print("AT+CMGF=1");
  Serial.print(0x0D,byte);
  Serial.println("GSM READY");
  delay(1000);
 } 
  
  void loop()
  {
    int byte=0;
    
     if(Serial.available() ) 
       {  
        if(Serial.read() == 'R') 
       {
    for(t=0; t<45; t++)
     {
      while(!Serial.available() ) ;
         
       da8[t] = Serial.read(); 
      // Serial.write(da8[t]);
       }
        
        lcd.setCursor(0, 0);
        lcd.print("LATI=");
        Serial.println("");
        Serial.print("LATITUDE=");
        lcd.setCursor(5, 0);
        for(t=15; t<28; t++)
       {
        Serial.write(da8[t]);
        lcd.write(da8[t]);
       } 
        lcd.setCursor(0, 1);
        lcd.print("LONG=");
        Serial.println(" ");
        Serial.print("LONGITUDE=");
        lcd.setCursor(5, 1); 
     for(t=28; t<43; t++)
       {
        Serial.write(da8[t]);
        lcd.write(da8[t]);
       } 
      }
          
    }
    
//    if(mySerial1.available() ) 
//       {  
//        if(mySerial1.read() == '1') 
//       {
//    Serial.print("AT");
//   Serial.print(0x0D,byte);
//   delay(1000);
//   Serial.print("AT+CMGF=1");
//   Serial.print(0x0D,byte);
//   delay(1000);
//    Serial.print("AT+CMGS=");
//    Serial.print(0x22,byte);
//    Serial.print("+919424029335");
//    Serial.print(0x22,byte);
//    Serial.print(0x0D,byte);
//    delay(1000);
//    
//     lcd.setCursor(0, 0);
//        lcd.print("lt=");
//        // Serial.println("");
//          Serial.print("lt=");
//        lcd.setCursor(3, 0);
//        for(t=15; t<28; t++)
//       {
//        Serial.write(da8[t]);
//        lcd.write(da8[t]);
//       } 
//        lcd.setCursor(0, 1);
//        lcd.print("lg=");
//        // Serial.println("");
//          Serial.print("lg=");
//        lcd.setCursor(3, 1); 
//     for(t=28; t<43; t++)
//       {
//       Serial.write(da8[t]);
//        lcd.write(da8[t]);
//       } 
//       Serial.println("");
//    Serial.print("DROWSINESS PERSON");
//    Serial.print(0x1A,byte);
//    lcd.setCursor(0, 1);
//    lcd.print("DROWSINESS PERSON"); 
//    delay(2000);
//     }
//       
//     }
    
  s1Value = digitalRead(as1);
  if(s1Value ==LOW)
   {
   Serial.print("AT");
   Serial.print(0x0D,byte);
   delay(1000);
   Serial.print("AT+CMGF=1");
   Serial.print(0x0D,byte);
   delay(1000);
   Serial.print("AT+CMGS=");
   Serial.print(0x22,byte);
   Serial.print("+919424029335"); 
   Serial.print(0x22,byte);
   Serial.print(0x0D,byte);
   delay(1000);
   lcd.setCursor(0, 0);
   lcd.print("LATITUDE=");
   Serial.println("");
   Serial.print("LATITUDE=");
   lcd.setCursor(3, 0);
   for(t=15; t<28; t++)
       {
       Serial.write(da8[t]);
        lcd.write(da8[t]);
       } 
        lcd.setCursor(0, 1);
        lcd.print("LONGITUDE=");
        Serial.println("");
        Serial.print("LONGITUDE=");
        lcd.setCursor(3, 1); 
     for(t=28; t<43; t++)
       {
       Serial.write(da8[t]);
        lcd.write(da8[t]);
       } 
       Serial.println("");
       Serial.print("LOCATION SEND");
       Serial.print(0x1A,byte);
       lcd.setCursor(0, 1);
       lcd.print("LOCATION SEND"); 
       delay(2000);
     }
    
   }
   


         
     
       
  
    
    
    
  
