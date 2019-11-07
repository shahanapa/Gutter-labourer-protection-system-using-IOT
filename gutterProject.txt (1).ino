int PulseSensorPin = A1;// Pulse Sensor   WIRE connected to ANALOG PIN A0
int sensorPin= A0; // MQ 2 SENSOR WIRE connected to ANALOG PIN A1
int buzzer = 11; // The on-board Arduino buzzer
int Signal; // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 600;// Determine which Signal to "count as a beat", and which to ingore.
int smoke_level;


void setup() {
  pinMode(buzzer, OUTPUT); // pin that will BUZZER to your heartbeat
  pinMode(sensorPin, INPUT);// pin that will  SENSE to the smoke.
  pinMode(PulseSensorPin, INPUT);
  Serial.begin(9600); // Sets up Serial Communication at certain speed.
}

void loop() {
  Signal = analogRead(PulseSensorPin); // Read the PulseSensor's value.
  Serial.println(Signal);
  smoke_level= analogRead(sensorPin); //arduino reads the value from the smoke sensor
  Serial.println(smoke_level);
  
  
   if(Signal < Threshold) { // If the signal is below "80", then "turn-on" Arduino's on-Board buzzer.  
    digitalWrite(buzzer, HIGH);
   Serial.print("Heart beat level is  ABNORMAL");
     } else  {
    digitalWrite(buzzer, LOW); //  Else, the signal must be above "80", so "turn-off" this buzzer
    Serial.print("Heart beat level is  NORMAL"); 
  }
  delay(2000); // wait 2s for next reading

if (smoke_level > 300)  { //if smoke level is greater than 300, the buzzer will go on
digitalWrite(buzzer, HIGH);
Serial.print(" | Smoke detected!");
}
else {
digitalWrite(buzzer, LOW);
Serial.print(" |  NO Smoke detected!"); 
} 
 delay(2000); // wait 2s for next reading

 if ((Signal < Threshold)&&(smoke_level > 300)) {
   Serial.println("Heart beat level is  ABNORMAL" and " Smoke detected!");
    }
    else {
     Serial.println("Heart beat level is  NORMAL" and "  NO Smoke detected!");  
    }
  delay(2000); // wait 2s for next reading //
}

  
