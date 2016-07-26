volatile int flow_frequency; // Sensor palsı
unsigned int l_hour; // Hesaplanan Litre/saat
unsigned char flowsensor = 18; // Sensor Giriş Pini
unsigned long currentTime;
unsigned long cloopTime;
int i=0; int yeni=0; int eski=0;
float flowRate; int a=0;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres;
int sayac=0;
int yenisayac=0;
int sondurum=0;
int emmemiktari=0;
void flow () // Kesme Fonksiyonu
{
   flow_frequency++;
   debi();
   sayac++;

}


void setup()
{
   pinMode(flowsensor, INPUT);
 // digitalWrite(flowsensor, HIGH); // Optional Dahili Pull-Up
   Serial.begin(9600);
   attachInterrupt(0, flow, RISING); // Kesmeleri Yükler.
   sei();    // Kesmeleri aktif yapar.
   currentTime = millis();
   cloopTime = currentTime;
  
  flowRate          = 0.0;
  flowMilliLitres   = 0;
  totalMilliLitres  = 0;
}

void loop ()
{ 
 }
void debi(){
   currentTime = millis();
   // Her saniye hesaplar ve litre/saat yazdırır.
   if(currentTime >= (cloopTime + 1000))
   {
      flowRate = ((1000.0 / (millis() - cloopTime)) * flow_frequency) / 4.5;
      cloopTime = millis(); // cloopTime güncelle,yenile 
    
      flowMilliLitres = (flowRate / 60)*1000 ;
      totalMilliLitres += flowMilliLitres;
      
      eski=totalMilliLitres;
      yeni=flow_frequency+totalMilliLitres;
     
     
      l_hour = (flow_frequency * 60 / 15); // (Darbe frekansı x 60 dk) / 7.5Q = Akış Hızı Litre/saat
      flow_frequency = 0; // Sayacı Sıfırla..
      
      //Serial.print("  Sivi Akis Hizi: "); 
     // Serial.print(l_hour, DEC); // Yazdır litre/saat
     // Serial.println(" L/saat \n");
      
     // Serial.print("  Sivi Akis Hizi MiliLitre: "); 
     // Serial.print(flowMilliLitres, DEC); // Yazdır litre/saat
     // Serial.println(" mL/saniye \n");
      
     Serial.print("  Toplam Sivi: "); 
      Serial.print(totalMilliLitres);
Serial.println("mL \n"); 
             
             i++;

     /* Serial.print("ESKI "); 
      Serial.print(eski); // Yazdır..
      Serial.println(" \n\n");
      
      Serial.print("YENI"); 
      Serial.print(yeni); // Yazdır..
      Serial.println(" \n\n");  */
           
   

  }
  
  }
