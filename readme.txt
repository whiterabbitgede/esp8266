<p align="center"><a href="https://laravel.com" target="_blank"><img src="https://raw.githubusercontent.com/laravel/art/master/logo-lockup/5%20SVG/2%20CMYK/1%20Full%20Color/laravel-logolockup-cmyk-red.svg" width="400"></a></p>


#include <Arduino.h>

// Pin LED
const int GREEN_PIN = D2;
const int YELLOW_PIN = D3;
const int RED_PIN = D4;
const int BUZZER_PIN = D1;

void setup() {
  // pinMode(13, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void bunyiBuzzerDinamis(float multiplier = 1) {
  int baseNada[] = {
    440, 523,    // 61'
    490, 330, 440, 490, 523,  // 73 671'
    440,          // 6    
    0,
    523,           // 1'
    440, 490, 330, // 673
    330, 490, 523, // 371'
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

// --- Fungsi Buzzer Pasif ---
void bunyiTingTong(int repeatCount) {
  // int nada[] = {1319, 1046, 880, 1046}; // E6, C6, A5, C6 (frekuensi Hz)
  // int durasi = 200; // durasi tiap nada (ms)

  // int nada[] = {1046, 784, 880}; // C6, G5, A5 (frekuensi Hz)
  // int durasi = 200; // durasi tiap nada (ms)

  int nada[] = {830, 830, 880, 587, 0, 0, 0, 783, 830}; //A, D, G (frekuensi Hz)
  int durasi = 200; // durasi tiap nada (ms)

  // int nada[] = {1479, 830, 1479, 1479, 1479, 830, 1479, 830, 830}; //90, 80,90 (frekuensi Hz)
  // int durasi = 200; // durasi tiap nada (ms)

  // int nada[] = {659, 587, 523, 494, 440, 392, 349, 330}; // E6, C6, A5, C6 (frekuensi Hz)
  // int durasi = 268; // durasi tiap nada (ms)

  int numNada = sizeof(nada) / sizeof(nada[0]);

  for (int r = 0; r < repeatCount; r++) {
    // for (int i = 0; i < 4; i++) {
    for (int i = 0; i < numNada; i++) {
      tone(BUZZER_PIN, nada[i]);
      delay(durasi);
      noTone(BUZZER_PIN);
      delay(80); // jeda antar nada
    }
    delay(400); // jeda antar pola "ting-tong-tin-tong"
  }
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
  // put your main code here, to run repeatedly:
  // digitalWrite(13, HIGH);
  // delay(1000); 
  // digitalWrite(13, LOW);
  // delay(1000);
  // Lampu Merah ON
  // bunyiTingTong(3);
  // bunyiTingTong(2);
  redOn();
  delay(5000); // 5 detik

  // Lampu Kuning ON
  yellowOn();
  delay(2000); // 2 detik

  // Lampu Hijau ON
  greenOn();
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

  // bunyiTingTong(2);
  // bunyiBuzzer();
  // bunyiBuzzerDinamis(1.0);  // Normal
  // bunyiBuzzerDinamis(1.5);  // 50% lebih tinggi
  bunyiBuzzerDinamis(2);  // 1 oktaf lebih tinggi

}
