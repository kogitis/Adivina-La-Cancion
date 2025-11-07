#include "pitches.h"

// ================== Pines (MEGA 2560) ==================
#define PIN_BTN_START 32
#define PIN_BTN_A     26
#define PIN_BTN_B     28
#define PIN_LED_A     36
#define PIN_LED_B     40
#define PIN_BUZZ      46

// ================== Tiempos (ms) =======================
const unsigned long T_INTRO   = 5000;   // suenan 5 s de la canción
const unsigned long T_VENTANA = 5000;   // 5 s para reaccionar
const unsigned long T_HOLD    = 8000;   // 8 s mostrando ganador
const unsigned long DEBOUNCE  = 25;     // antirrebote

// ================== REPERTORIO =========================
// (dejé tus 6 canciones exactas)

int melody1[] = {
  NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
  NOTE_G5, REST, NOTE_G4, REST, 
  NOTE_C5, NOTE_G4, REST, NOTE_E4,
  NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  REST, NOTE_E5,NOTE_C5, NOTE_D5, NOTE_B4,
  NOTE_C5, NOTE_G4, REST, NOTE_E4,
  NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  REST, NOTE_E5,NOTE_C5, NOTE_D5, NOTE_B4,
  
  REST, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_E5,
  REST, NOTE_GS4, NOTE_A4, NOTE_C4, REST, NOTE_A4, NOTE_C5, NOTE_D5,
  REST, NOTE_DS5, REST, NOTE_D5,
  NOTE_C5, REST,
  
  REST, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_E5,
  REST, NOTE_GS4, NOTE_A4, NOTE_C4, REST, NOTE_A4, NOTE_C5, NOTE_D5,
  REST, NOTE_DS5, REST, NOTE_D5,
  NOTE_C5, REST,
  
  NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  
  NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5, NOTE_E5,
  REST, 
  NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
  NOTE_G5, REST, NOTE_G4, REST, 
  NOTE_C5, NOTE_G4, REST, NOTE_E4,
  
  NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  REST, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4,
  
  NOTE_C5, NOTE_G4, REST, NOTE_E4,
  NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  REST, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4,
  
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,
  
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
  NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,
  
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,
  
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
  NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,
  NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5, NOTE_E5,
  REST,
  
  NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
  NOTE_G5, REST, NOTE_G4, REST, 
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,
  
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
  NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,
  
  // Game over sound
  NOTE_C5, NOTE_G4, NOTE_E4,
  NOTE_A4, NOTE_B4, NOTE_A4, NOTE_GS4, NOTE_AS4, NOTE_GS4,
  NOTE_G4, NOTE_D4, NOTE_E4
};
uint8_t durations1[] = { 8, 8, 8, 8, 8, 8, 8,
  4, 4, 8, 4, 
  4, 8, 4, 4,
  4, 4, 8, 4,
  8, 8, 8, 4, 8, 8,
  8, 4,8, 8, 4,
  4, 8, 4, 4,
  4, 4, 8, 4,
  8, 8, 8, 4, 8, 8,
  8, 4,8, 8, 4,
  4, 8, 8, 8, 4, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  4, 4, 8, 4,
  2, 2,
  4, 8, 8, 8, 4, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  4, 4, 8, 4,
  2, 2,
  8, 4, 8, 8, 8, 4,
  8, 4, 8, 2,
  8, 4, 8, 8, 8, 8, 8,
  1, 
  8, 4, 8, 8, 8, 4,
  8, 4, 8, 2,
  8, 8, 8, 8, 8, 8, 4,
  4, 4, 4, 4, 
  4, 8, 4, 4,
  4, 4, 8, 4,
  8, 8, 8, 4, 8, 8,
  8, 4, 8, 8, 4,
  4, 8, 4, 4,
  4, 4, 8, 4,
  8, 8, 8, 4, 8, 8,
  8, 4, 8, 8, 4,
  8, 4, 8, 4, 4,
  8, 4, 8, 2,
  8, 8, 8, 8, 8, 8,
  8, 4, 8, 2,
  8, 4, 8, 4, 4,
  8, 4, 8, 2,
  8, 4, 8, 8, 8, 8,
  8, 4, 8, 2,
  8, 4, 8, 4, 4,
  8, 4, 8, 2,
  8, 8, 8, 8, 8, 8,
  8, 4, 8, 2,
  8, 4, 8, 4, 4,
  8, 4, 8, 2,
  8, 4, 8, 8, 8, 8,
  8, 4, 8, 2,
  8, 4, 8, 8, 8, 8, 8,
  1,
  8, 4, 8, 8, 8, 4,
  8, 4, 8, 2,
  8, 8, 8, 8, 8, 8, 4,
  4, 4, 4, 4, 
  8, 4, 8, 4, 4,
  8, 4, 8, 2,
  8, 8, 8, 8, 8, 8,
  8, 4, 8, 2,
  8, 4, 8, 4, 4,
  8, 4, 8, 2,
  8, 4, 8, 8, 8, 8,
  8, 4, 8, 2,
  //game over sound
  4, 4, 4,
  8, 8, 8, 8, 8, 8,
  8, 8, 2 };

int melody2[] = {
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
  NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
  NOTE_A4, NOTE_G4, NOTE_A4, REST,
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
  NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
  NOTE_A4, NOTE_G4, NOTE_A4, REST,
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
  NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, REST,
  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, REST,
  NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, REST,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
  NOTE_D5, NOTE_E5, NOTE_A4, REST,
  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, REST,
  NOTE_C5, NOTE_A4, NOTE_B4, REST,
  NOTE_A4, NOTE_A4,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
  NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
  NOTE_A4, NOTE_G4, NOTE_A4, REST,
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
  NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
  NOTE_A4, NOTE_G4, NOTE_A4, REST,
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
  NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, REST,
  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, REST,
  NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, REST,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
  NOTE_D5, NOTE_E5, NOTE_A4, REST,
  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, REST,
  NOTE_C5, NOTE_A4, NOTE_B4, REST,
  NOTE_E5, REST, REST, NOTE_F5, REST, REST,
  NOTE_E5, NOTE_E5, REST, NOTE_G5, REST, NOTE_E5, NOTE_D5, REST, REST,
  NOTE_D5, REST, REST, NOTE_C5, REST, REST,
  NOTE_B4, NOTE_C5, REST, NOTE_B4, REST, NOTE_A4,
  NOTE_E5, REST, REST, NOTE_F5, REST, REST,
  NOTE_E5, NOTE_E5, REST, NOTE_G5, REST, NOTE_E5, NOTE_D5, REST, REST,
  NOTE_D5, REST, REST, NOTE_C5, REST, REST,
  NOTE_B4, NOTE_C5, REST, NOTE_B4, REST, NOTE_A4
};
uint8_t durations2[] = {
  8,8,4,8,8, 8,8,4,8,8, 8,8,4,8,8, 8,8,4,8,
  8,8,4,8,8, 8,8,4,8,8, 8,8,4,8,8, 8,8,4,8,
  8,8,4,8,8, 8,8,4,8,8, 8,8,4,8,8, 8,8,8,4,8,
  8,8,4,8,8, 4,8,4,8, 8,8,4,8,8, 8,8,4,4,
  4,8, 8,8,4,8,8, 8,8,4,8,8, 8,8,4,8,
  8,8,4,8,8, 8,8,4,8,8, 8,8,4,8,8, 8,8,4,8,
  8,8,4,8,8, 8,8,4,8,8, 8,8,4,8,8, 8,8,8,4,8,
  8,8,4,8,8, 4,8,4,8, 8,8,4,8,8, 8,8,4,4,
  4,8,4,4,8,4, 8,8,8,8,8,8,8,8,4,
  4,8,4,4,8,4, 8,8,8,8,8,2,
  4,8,4,4,8,4, 8,8,8,8,8,8,8,8,4,
  4,8,4,4,8,4, 8,8,8,8,8,2
};

int melody3[] = {
  NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,
  NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,
  NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,
  NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,
  NOTE_A5,NOTE_A5, NOTE_G5,NOTE_G5, NOTE_A5,NOTE_A5, NOTE_G5,NOTE_G5
};
uint8_t durations3[] = {
  5,5,5,5,5,5,5,5,5,5,5,
  5,5,5,5,5,
  5,5,5,5,5,5,5,5,5,5,5,
  5,5,5,5,5,
  1,2, 1,2, 1,2, 1,2
};

int melody4[] = {
  REST,NOTE_E5,NOTE_D5,NOTE_C5,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_B4,
  NOTE_G5,NOTE_E5,NOTE_F5,NOTE_G5,NOTE_E5,NOTE_F5,NOTE_G5,REST,
  NOTE_E5,NOTE_C5,NOTE_D5,NOTE_E5,NOTE_C5,NOTE_D5,NOTE_E5,NOTE_C5,NOTE_D5,NOTE_E5,NOTE_D5,NOTE_C5,
  NOTE_A4,NOTE_A4,REST,NOTE_A4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_G4,REST,NOTE_G4,
  NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_C5,NOTE_B4,
  NOTE_G5,NOTE_E5,NOTE_F5,NOTE_G5,NOTE_E5,NOTE_F5,NOTE_G5,
  NOTE_E5,NOTE_C5,NOTE_D5,NOTE_E5,NOTE_C5,NOTE_D5,NOTE_E5,NOTE_C5,NOTE_D5,NOTE_E5,NOTE_D5,NOTE_C5,
  NOTE_A4,NOTE_A4,REST,NOTE_A4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_G4,REST,NOTE_G4,NOTE_G4,
  NOTE_A4,NOTE_A4,NOTE_A4,REST,NOTE_A4,NOTE_C5,NOTE_B4,NOTE_B4,NOTE_B4,NOTE_B4,NOTE_C5,REST,
  REST
};
uint8_t durations4[] = {
  4,2,2,2,2,2,2,2,4,
  4,8,8,4,8,8,2,2,
  4,8,8,4,8,8,4,8,8,4,8,8,
  4,8,8,4,8,8,8,8,2,8,8,
  8,8,4,4,4,1,
  4,8,8,4,8,8,1,
  4,8,8,4,8,8,4,8,8,4,8,8,
  4,8,8,4,8,8,8,8,4,4,8,8,
  8,8,8,8,4,4,8,8,4,4,8,8,
  1
};

int melody5[] = {
  REST,NOTE_D4, NOTE_G4,NOTE_AS4,NOTE_A4, NOTE_G4,NOTE_D5, NOTE_C5, NOTE_A4,
  NOTE_G4,NOTE_AS4,NOTE_A4, NOTE_F4,NOTE_GS4, NOTE_D4, NOTE_D4,
  NOTE_G4,NOTE_AS4,NOTE_A4, NOTE_G4,NOTE_D5, NOTE_F5,NOTE_E5, NOTE_DS5,NOTE_B4,
  NOTE_DS5,NOTE_D5,NOTE_CS5, NOTE_CS4,NOTE_B4, NOTE_G4, NOTE_AS4,
  NOTE_D5,NOTE_AS4, NOTE_D5,NOTE_AS4, NOTE_DS5,NOTE_D5, NOTE_CS5,NOTE_A4,
  NOTE_AS4,NOTE_D5,NOTE_CS5, NOTE_CS4,NOTE_D4, NOTE_D5, REST,NOTE_AS4,
  NOTE_D5,NOTE_AS4, NOTE_D5,NOTE_AS4, NOTE_F5,NOTE_E5, NOTE_DS5,NOTE_B4,
  NOTE_DS5,NOTE_D5,NOTE_CS5, NOTE_CS4,NOTE_AS4, NOTE_G4
};
uint8_t durations5[] = {
  2,4, 4,8,4, 2,4, 2, 2,
  4,8,4, 2,4, 1, 4,
  4,8,4, 2,4, 2,4, 2,4,
  4,8,4, 2,4, 1, 4,
  2,4, 2,4, 2,4, 2,4,
  4,8,4, 2,4, 1, 4,4,
  2,4, 2,4, 2,4, 2,4,
  4,8,4, 2,4, 1
};

int melody6[] = {
  NOTE_E5,NOTE_B4,NOTE_C5,NOTE_D5,NOTE_C5,NOTE_B4,
  NOTE_A4,NOTE_A4,NOTE_C5,NOTE_E5,NOTE_D5,NOTE_C5,
  NOTE_B4,NOTE_C5,NOTE_D5,NOTE_E5, NOTE_C5,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_B4,NOTE_C5,
  NOTE_D5,NOTE_F5,NOTE_A5,NOTE_G5,NOTE_F5, NOTE_E5,NOTE_C5,NOTE_E5,NOTE_D5,NOTE_C5,
  NOTE_B4,NOTE_B4,NOTE_C5,NOTE_D5,NOTE_E5, NOTE_C5,NOTE_A4,NOTE_A4,REST,
  NOTE_E5,NOTE_B4,NOTE_C5,NOTE_D5,NOTE_C5,NOTE_B4,
  NOTE_A4,NOTE_A4,NOTE_C5,NOTE_E5,NOTE_D5,NOTE_C5,
  NOTE_B4,NOTE_C5,NOTE_D5,NOTE_E5, NOTE_C5,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_B4,NOTE_C5,
  NOTE_D5,NOTE_F5,NOTE_A5,NOTE_G5,NOTE_F5, NOTE_E5,NOTE_C5,NOTE_E5,NOTE_D5,NOTE_C5,
  NOTE_B4,NOTE_B4,NOTE_C5,NOTE_D5,NOTE_E5, NOTE_C5,NOTE_A4,NOTE_A4,REST,
  NOTE_E5,NOTE_C5, NOTE_D5,NOTE_B4, NOTE_C5,NOTE_A4, NOTE_GS4,NOTE_B4,REST,
  NOTE_E5,NOTE_C5, NOTE_D5,NOTE_B4, NOTE_C5,NOTE_E5,NOTE_A5, NOTE_GS5
};
uint8_t durations6[] = {
  4,8,8,4,8,8, 4,8,8,4,8,8, 4,8,4,4, 4,4,8,4,8,8,
  4,8,4,8,8, 4,8,4,8,8, 4,8,8,4,4, 4,4,4,4,
  4,8,8,4,8,8, 4,8,8,4,8,8, 4,8,4,4, 4,4,8,4,8,8,
  4,8,4,8,8, 4,8,4,8,8, 4,8,8,4,4, 4,4,4,4,
  2,2, 2,2, 2,2, 2,4,8, 2,2, 2,2, 4,4,2, 2
};

// ===== Empaquetado del repertorio =====
struct Song { int* m; uint8_t* d; uint16_t len; const char* name; };
#define MINLEN(a,b) ((sizeof(a)/sizeof(a[0]) < sizeof(b)/sizeof(b[0]))? (sizeof(a)/sizeof(a[0])):(sizeof(b)/sizeof(b[0])))
const uint16_t len1 = MINLEN(melody1,durations1);
const uint16_t len2 = MINLEN(melody2,durations2);
const uint16_t len3 = MINLEN(melody3,durations3);
const uint16_t len4 = MINLEN(melody4,durations4);
const uint16_t len5 = MINLEN(melody5,durations5);
const uint16_t len6 = MINLEN(melody6,durations6);

Song SONGS[] = {
  {melody1,durations1,len1,"Cancion 1"},
  {melody2,durations2,len2,"Cancion 2"},
  {melody3,durations3,len3,"Cancion 3"},
  {melody4,durations4,len4,"Cancion 4"},
  {melody5,durations5,len5,"Cancion 5"},
  {melody6,durations6,len6,"Cancion 6"}
};
const uint8_t NUM_SONGS = sizeof(SONGS)/sizeof(SONGS[0]);

// ================== FSM Moore ===========================
enum State { E0_ESPERA, E1_INTRO, E2_VENTANA, E3A_PROV_A, E3B_PROV_B, E4A_GAN_A, E4B_GAN_B };
State st = E0_ESPERA, prev = E0_ESPERA;

unsigned long t0=0;
bool lastA=false, lastB=false;
uint8_t currentSong=0;

inline bool pressedLOW(uint8_t pin){
  if (digitalRead(pin)==LOW){ delay(DEBOUNCE); return digitalRead(pin)==LOW; }
  return false;
}
void allOff(){ digitalWrite(PIN_LED_A,LOW); digitalWrite(PIN_LED_B,LOW); noTone(PIN_BUZZ); }

// --------- Música de victoria en bucle (simple) ----------
const int VICT_NOTES[] = { NOTE_C6, NOTE_E6, NOTE_G6, NOTE_C7, REST };
const uint8_t VICT_DURS[] = { 8, 8, 8, 4, 8 }; // 1 compás corto

void playVictory8s(bool winA){
  // Solo el LED del ganador queda encendido
  digitalWrite(PIN_LED_A, winA ? HIGH : LOW);
  digitalWrite(PIN_LED_B, winA ? LOW  : HIGH);

  unsigned long tStart = millis();
  while (millis() - tStart < T_HOLD) {
    for (uint8_t i=0; i<sizeof(VICT_NOTES)/sizeof(VICT_NOTES[0]); ++i){
      int n = VICT_NOTES[i];
      int ms = 1000 / (VICT_DURS[i] ? VICT_DURS[i] : 4);
      if (n==REST){ noTone(PIN_BUZZ); delay(ms); }
      else { tone(PIN_BUZZ, n, ms); delay((int)(ms*1.15)); noTone(PIN_BUZZ); }
      if (millis() - tStart >= T_HOLD) break; // por si se cumple durante el compás
    }
  }
  noTone(PIN_BUZZ);
}

// ------------------ Intro de 5s -------------------------
void playIntro5s(const Song& s){
  unsigned long t = millis();
  for (uint16_t i=0; i<s.len && (millis()-t) < T_INTRO; ++i){
    int note = s.m[i];
    uint8_t den = s.d[i]; if(!den) den=4;
    int ms = 1000 / den;
    if (note == REST){ noTone(PIN_BUZZ); delay((int)(ms*1.25)); }
    else { tone(PIN_BUZZ, note, ms); delay((int)(ms*1.25)); noTone(PIN_BUZZ); }
  }
}

void setup(){
  pinMode(PIN_LED_A,OUTPUT); pinMode(PIN_LED_B,OUTPUT); pinMode(PIN_BUZZ,OUTPUT);
  pinMode(PIN_BTN_START,INPUT_PULLUP); pinMode(PIN_BTN_A,INPUT_PULLUP); pinMode(PIN_BTN_B,INPUT_PULLUP);
  Serial.begin(9600);
  randomSeed(analogRead(A0));
  allOff();
  Serial.println("FSM Moore + repertorio aleatorio (MEGA). START para comenzar.");
}

void loop(){
  // Acciones al entrar a un estado
  if (st!=prev){
    switch(st){
      case E0_ESPERA: allOff(); break;

      case E1_INTRO:
        allOff();
        currentSong = random(NUM_SONGS);
        Serial.print("Cancion: "); Serial.println(SONGS[currentSong].name);
        playIntro5s(SONGS[currentSong]);
        break;

      case E2_VENTANA:
        allOff(); t0 = millis();
        lastA = (digitalRead(PIN_BTN_A)==LOW);
        lastB = (digitalRead(PIN_BTN_B)==LOW);
        break;

      case E3A_PROV_A:
        digitalWrite(PIN_LED_A,HIGH); digitalWrite(PIN_LED_B,LOW); // solo A encendido
        // sonidito corto opcional de provisional (se mantiene)
        tone(PIN_BUZZ, NOTE_A5, 120); delay(150); noTone(PIN_BUZZ);
        lastA = (digitalRead(PIN_BTN_A)==LOW);
        lastB = (digitalRead(PIN_BTN_B)==LOW);
        break;

      case E3B_PROV_B:
        digitalWrite(PIN_LED_B,HIGH); digitalWrite(PIN_LED_A,LOW); // solo B encendido
        tone(PIN_BUZZ, NOTE_A5, 120); delay(150); noTone(PIN_BUZZ);
        lastA = (digitalRead(PIN_BTN_A)==LOW);
        lastB = (digitalRead(PIN_BTN_B)==LOW);
        break;

      case E4A_GAN_A:
        // victory loop bloqueante 8s; al terminar volvemos a E0
        playVictory8s(true);
        st = E0_ESPERA;
        break;

      case E4B_GAN_B:
        playVictory8s(false);
        st = E0_ESPERA;
        break;
    }
    prev = st;
  }

  // Transiciones (tabla)
  switch(st){
    case E0_ESPERA:
      if (pressedLOW(PIN_BTN_START)) st = E1_INTRO;
      break;

    case E1_INTRO:
      st = E2_VENTANA;
      break;

    case E2_VENTANA:{
      bool a = (digitalRead(PIN_BTN_A)==LOW);
      bool b = (digitalRead(PIN_BTN_B)==LOW);
      bool edgeA = a && !lastA;
      bool edgeB = b && !lastB;
      lastA=a; lastB=b;

      if (edgeA && !edgeB)       st = E3A_PROV_A;
      else if (edgeB && !edgeA)  st = E3B_PROV_B;
      else if (millis()-t0 >= T_VENTANA) st = E0_ESPERA;
    } break;

    case E3A_PROV_A:{
      bool a = (digitalRead(PIN_BTN_A)==LOW);
      bool b = (digitalRead(PIN_BTN_B)==LOW);
      bool edgeA = a && !lastA;
      bool edgeB = b && !lastB;
      lastA=a; lastB=b;

      if (edgeA) st = E4A_GAN_A;   // juez confirma A
      if (edgeB) st = E4B_GAN_B;   // juez corrige a B
    } break;

    case E3B_PROV_B:{
      bool a = (digitalRead(PIN_BTN_A)==LOW);
      bool b = (digitalRead(PIN_BTN_B)==LOW);
      bool edgeA = a && !lastA;
      bool edgeB = b && !lastB;
      lastA=a; lastB=b;

      if (edgeB) st = E4B_GAN_B;   // juez confirma B
      if (edgeA) st = E4A_GAN_A;   // juez corrige a A
    } break;

    case E4A_GAN_A:
    case E4B_GAN_B:
      // nada: la transición a E0 se hace al terminar playVictory8s()
      break;
  }
}
