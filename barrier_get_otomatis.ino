//Library Servo
#include <Servo.h>
Servo myservo;

// Library sensor ultrasonik
#include <NewPing.h>

// Pin yang digunakan untuk menghubungkan sensor ultrasonik
const int trigPin = 11;   // Pin trigger sensor ultrasonik
const int echoPin = 12;   // Pin echo sensor ultrasonik

// Objek NewPing untuk mengontrol sensor ultrasonik
NewPing sonar(trigPin, echoPin);

void setup() {
  Serial.begin(9600);  // Inisialisasi komunikasi serial
  
  myservo.attach(9);  // servo terhubung pin 9

  // Mengkonfigurasi pin trigger sebagai output
  pinMode(trigPin, OUTPUT);
  // Mengkonfigurasi pin echo sebagai input
  pinMode(echoPin, INPUT);
  
}

void loop() {

  // Mengukur jarak menggunakan sensor ultrasonik
  int jarak = sonar.ping_cm();

  // Mencetak hasil ke Serial Monitor
  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.println(" cm");

  delay(500);


if(jarak <= 15)
{
  Serial.println("Mobil Terdeteksi"); 
  myservo.write(0);
  myservo.write(120); 
  delay(2000);
}

else{
  Serial.println("Tidak Ada Mobil"); 
  myservo.write(120); 
  myservo.write(0);
  delay(1000);  
  
}

}