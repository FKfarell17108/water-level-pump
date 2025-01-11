#include <LiquidCrystal.h>

// Inisialisasi pin LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// Definisi pin
const int trigPin = 8;
const int echoPin = 9;
const int relayPin = 12;

// Variabel jarak dan persentase
long duration;
int distance;
int waterLevel;

// Konstanta jarak minimum dan maksimum
const int minDistance = 1;  // Air penuh
const int maxDistance = 10;  // Air kosong

void setup() {
  // Inisialisasi LCD
  lcd.begin(16, 2);
  lcd.print("Water Level:");

  // Inisialisasi pin
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);

  // Pompa dimatikan saat start
  digitalWrite(relayPin, HIGH);
}

void loop() {
  // Mengirim sinyal trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Membaca sinyal echo
  duration = pulseIn(echoPin, HIGH);

  // Menghitung jarak (dalam cm)
  distance = duration * 0.034 / 2;

  // Menghitung persentase level air
  waterLevel = map(distance, maxDistance, minDistance, 0, 100);
  if (waterLevel > 100) waterLevel = 100; // Batas maksimum
  if (waterLevel < 0) waterLevel = 0;     // Batas minimum

  // Menampilkan level air dalam persentase pada LCD
  lcd.setCursor(0, 1);
  lcd.print("Level: ");
  lcd.print(waterLevel);
  lcd.print("%     "); // Tambahkan spasi untuk menghapus karakter lama

  // Logika kontrol pompa
  if (waterLevel >= 100) {
    // Air penuh, pompa mati
    digitalWrite(relayPin, LOW); // Relay mati
    lcd.setCursor(0, 0);
    lcd.print("Pump: OFF      ");
  } else if (waterLevel <= 25) {
    // Air rendah, pompa hidup
    digitalWrite(relayPin, HIGH); // Relay hidup
    lcd.setCursor(0, 0);
    lcd.print("Pump: ON       ");
  }

  delay(100); // Update setiap 100ms
}
