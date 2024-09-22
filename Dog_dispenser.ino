//Written By Vishnu AJay 
//Date 9/26/2022 
//Rev B 
//Deg_Food_Despenser_MVp

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>     // graphics
#include <Adafruit_SSD1306.h> // OLED display
#include <TimeLib.h>          // Capturing time in hours, minutes, and seconds 
#include <Servo.h>

Servo myservo;

const int speakerPin = 8; // speaker to this pin
const int buttonPin = 7;  // push button to this pin

// frequencies 
int melody[] = {
  262, 294, 330, 349, 392, 440, 494, // C4, D4, E4, F4, G4, A4, B4
  523, 587, 659, 698, 784, 880, 988, // C5, D5, E5, F5, G5, A5, B5
};

int noteDuration = 500; //  note duration (in milliseconds)

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  while (!Serial) delay(10);

  myservo.attach(10); // Servo pinto this pin
  pinMode(speakerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // push button pin as input with pull-up resistor

  setTime(16, 59, 40, 1, 1, 1970); // Hours, minutes, seconds, day, month, year 
  //day motnth and year really doesnt matter here but using 16:59:40 to check if the servo works at 17:00:00. 
  //For the corect fuiction I would flash the audrino with the current time. 

  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void playNote(int frequency) {
  tone(speakerPin, frequency, noteDuration);
  delay(noteDuration);
  noTone(speakerPin);
}

void loop() {
  // current time using TimeLib
  int currentHour = hour();
  int currentMinute = minute();
  int currentSecond = second();

  // Check if the push button is pressed
    if (digitalRead(buttonPin) == LOW) {
    myservo.write(180);  // Override: Set servo angle to 180 degrees
    display.clearDisplay();
    display.setCursor(5, 10);
    display.print("BARK BARK!!");
    display.setCursor(5, 40);
    display.print("FOOD TIME");
    display.display();
    delay(8000);

    myservo.write(90); 
    display.clearDisplay();
    display.setCursor(5, 20);
    display.print("Come back later");
    display.display();
    delay(2000); // Display "Come back later" for 2 seconds
    display.clearDisplay();

  } else {

    // Check if it's the scheduled time
    if ((currentHour == 8 && currentMinute == 0 && currentSecond == 0) || 
        (currentHour == 17 && currentMinute == 0 && currentSecond == 0)) {
      // set servo angle to 180 degrees
      myservo.write(180);
      display.clearDisplay();
      display.setCursor(5, 20);
      display.print("BARK BARK!!");
       display.setCursor(5, 40);
      display.print("FOOD TIME.");
      display.display();
      delay(5000);
      // Play the melody
      for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
        playNote(melody[i]);
      }

      myservo.write(90);
      display.clearDisplay();
      display.setCursor(5, 20);
      display.print("Come Back Later");
      display.display();

    }
  }

  display.clearDisplay();
  delay(1000); // Check every 1 second
}
