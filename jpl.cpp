// - node mcu LOLIN (WEMOS) D1 mini (clone) (esp8266:esp8266:d1_mini_clone)

#include <Arduino.h>
#include <Servo.h>

// Pin LED
const int GREEN_PIN = D2;
const int YELLOW_PIN = D3;
const int RED_PIN = D4;
const int BUZZER_PIN = D1;
const int servoPin = D5;
Servo servo;  
int angle = 0;
int pos = 0;
int curPos = 0;

void setup() {
  // Serial.begin(115200);
  // pinMode(13, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  servo.attach(servoPin);
  closegate();
}

void opengate(){
  for (pos = curPos; pos <=  180; pos++) {
    // Serial.print(pos);
    servo.write(pos);
    curPos = pos;
    delay(25);
  }  
}

void closegate(){
  // servo.write(180);
  for (pos = curPos; pos >=  0; pos--) {
    // Serial.print(pos);
    servo.write(pos);
    curPos = pos;
    delay(25);
  }  
}

void bunyiBuzzerDinamis(float multiplier = 1) {
  int baseNada[] = {
    440, 523,    // 61'
    493.88, 330, 440, 493.88, 523,  // 73 671'
    440,          // 6    
    0,
    523,           // 1'
    440, 493.88, 330, // 673
    330, 493.88, 523, // 371'
    440            // 6
  };

  int durations[] = {
    600, 600,    // 61'
    500, 700, 500, 500, 600,  // 73 671' 
    800,          // 6    
    1000,
    600,           // 1'
    500, 500, 600, // 673  
    500, 500, 600, // 371'
    800            // 6
  };


  int numNada = sizeof(baseNada) / sizeof(baseNada[0]);
  for (int i = 0; i < numNada; i++) {
    if (baseNada[i] == 0) {
      noTone(BUZZER_PIN);
      delay(durations[i]);
    } else {
      int freqTinggi = baseNada[i] * multiplier; // Naikkan frekuensi
      tone(BUZZER_PIN, freqTinggi, durations[i]);
      delay(durations[i] + 100);
    }
  }
  noTone(BUZZER_PIN);
  delay(1000);
}



void rygOff(){
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
}

void redOn(){
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
}

void yellowOn(){
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
}

void greenOn(){
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
}

void loop() {
  redOn();
  bunyiBuzzerDinamis(1.0);
  closegate();
  delay(5000); // 5 detik

  // Lampu Kuning ON
  yellowOn();
  delay(2000); // 2 detik

  // Lampu Hijau ON
  greenOn();
  opengate();
  delay(5000); // 5 detik

  rygOff();
  delay(500);

  // Lampu Kuning ON
  yellowOn();
  delay(500); // 0.5 detik

  rygOff();
  delay(500);

  // Lampu Kuning ON
  yellowOn();
  delay(500); // 0.5 detik

  rygOff();
  delay(500);
  
  // Lampu Kuning ON
  yellowOn();
  delay(500); // 0.5 detik

  rygOff();
  delay(500);

    // Buzzer bunyi 3 kali dengan nada naik
  // for (int i = 0; i < 3; i++) {
  //   bunyiBuzzer(1000 + (i * 200), 200);
  // }

  // bunyiBuzzerDinamis(1.0);  // Normal
  // bunyiBuzzerDinamis(1.5);  // 50% lebih tinggi
  // bunyiBuzzerDinamis(2);  // 1 oktaf lebih tinggi

  // opengate();
  // servo.write(180);
  // delay(3000);
  // servo.write(0);
  // closegate();

}
