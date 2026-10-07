#define TRIG_PIN 9
#define ECHO_PIN 10
#define BUZZER_PIN 3
#define LED_PIN 4

// Batas maksimum pendeteksian objek
const int MAX_DISTANCE = 100;

// Variabel pengaturan buzzer
unsigned long previousBeep = 0;

// Variabel pengaturan LED
unsigned long previousLed = 0;
bool ledState = false;

float readDistance() {
  // Mengirimkan sinyal ultrasonik
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Membaca pantulan ultrasonik
  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000UL);

  // Jika tidak ada pantulan
  if (duration == 0) {
    return -1;
  }

  // Menghitung jarak dalam centimeter
  float distance = duration * 0.0343 / 2;

  return distance;
}

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(TRIG_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
  noTone(BUZZER_PIN);

  Serial.println("Smart Blind Stick Ready!");
}

void loop() {
  float distance = readDistance();

  // Jika sensor tidak mendapatkan pembacaan valid
  if (distance < 0) {
    noTone(BUZZER_PIN);
    digitalWrite(LED_PIN, LOW);
    ledState = false;

    delay(50);
    return;
  }

  Serial.print("Jarak objek: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Jika objek berada di luar jangkauan
  if (distance > MAX_DISTANCE) {
    noTone(BUZZER_PIN);

    digitalWrite(LED_PIN, LOW);
    ledState = false;
  }
  else {
    // Membatasi jarak agar sesuai dengan rentang 10-100 cm
    int safeDistance = constrain(
      (int)distance,
      10,
      MAX_DISTANCE
    );

    // Semakin dekat objek,
    // semakin pendek interval peringatan
    int warningInterval = map(
      safeDistance,
      100, 10,
      600, 120
    );

    unsigned long currentTime = millis();

    // KONTROL BUZZER
    if (currentTime - previousBeep >= warningInterval) {
      tone(BUZZER_PIN, 2000, 100);
      previousBeep = currentTime;
    }

    // KONTROL LED
    if (currentTime - previousLed >= warningInterval) {
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
      previousLed = currentTime;
    }
  }

  delay(50);
}