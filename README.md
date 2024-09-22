# 🐾 Deg_Food_Dispenser_MVP 🐾

**Author**: Vishnu AJay  
**Date**: 9/26/2022  
**Revision**: B  

---
**"Where every BARK means FOOD TIME!"**

A fun and functional automatic food dispenser for your furry friend. 🐕 Designed to dispense food at scheduled times with a delightful melody and messages just for your pet. It even lets you manually feed with a button press! 🐾

---

## 🛠 Project Overview

This project uses the **Arduino MetroMini** to control a food dispenser for pets. It dispenses food at scheduled times (or with a manual button press) and features an OLED screen for cute messages like **"BARK BARK!! FOOD TIME"** 🐶 and a melody to catch your pet's attention. The servo motor opens the food gate, and your hungry companion is satisfied!

## ✨ Components Used

1. **🐕 Arduino MetroMini** (or any compatible Arduino board)
2. **🦴 Servo Motor** - Opens the food dispenser at the right time.
3. **🐾 Push Button** - Manual override for food dispensing.
4. **🎵 Speaker** - Plays a melody at feeding time.
5. **💬 OLED Display** - Displays messages for your pet.
6. **⏰ TimeLib Library** - Keeps track of time for scheduled feedings.

## 📚 Libraries Required

- **Wire** - Used for I2C communication.
- **SPI** - Used for SPI communication.
- **Adafruit GFX** - Graphics library for the OLED display.
- **Adafruit SSD1306** - OLED display driver.
- **TimeLib** - For capturing time in hours, minutes, and seconds.
- **Servo** - To control the servo motor.

### 📦 **Install these libraries via the Arduino IDE's Library Manager before uploading the code.**

---

## 🐶 How It Works

1. **Scheduled Feeding**: The food dispenser opens at two scheduled times — **8:00 AM** and **5:00 PM** — allowing your pet to chow down.
2. **Manual Feeding**: Got a hungry pup? Press the button to feed your pet outside of schedule.
3. **Melody & Messages**: Plays a fun melody when dispensing food, and the OLED screen displays **"BARK BARK!! FOOD TIME"**.
4. **OLED Display**: Provides playful feedback, showing messages like **"Come back later"** when food is finished.
5. **Servo Control**: The servo motor controls the food gate, opening and closing at the right times.

---

## 🐕 Hardware Setup

- **Servo Motor**: Pin 10 controls the food gate.
- **Push Button**: Pin 7 is for manual feeding control.
- **Speaker**: Pin 8 is connected to the speaker for sound output.
- **OLED Display**: I2C connection to the display (SDA, SCL).
- **Arduino MetroMini**: The brains of the operation, making sure your pet stays well-fed!

---

## 🐾 Features

- **⏰ Scheduled Feeding**: Food is dispensed automatically at 8:00 AM and 5:00 PM.
- **🎵 Melody**: Plays a delightful melody while the food is dispensed.
- **🐕 Manual Override**: Press the button to dispense food anytime.
- **💬 OLED Display Messages**: Displays fun messages like **"BARK BARK!! FOOD TIME"** and **"Come back later"** to keep things playful.

---

## 💡 Code Walkthrough

### `setup()`

- Initializes serial communication, the servo, button, speaker, and OLED display.
- Time is manually set in the code for testing purposes.
  
### `loop()`

- Continuously checks the current time using `TimeLib`.
- If the **push button** is pressed, it dispenses food manually.
- At scheduled times (8:00 AM and 5:00 PM), the servo opens the food gate and plays a melody.
- After dispensing food, the display shows **"Come Back Later"** and closes the gate.

---

## 🎉 Fancy Features Coming Soon

- **RTC Module Integration**: Keep perfect time, even after power loss.
- **Multiple Feed Times**: Set more custom feeding times throughout the day.
- **Portion Control**: Customize the amount of food dispensed based on time.

---

## 🐾 Usage

1. **Step 1**: Upload the code to your Arduino.
2. **Step 2**: Wire the components according to the pin configuration.
3. **Step 3**: Press the button for manual feeding or let the automatic schedule take care of feeding your pet!

---

## 🐕💡 Fun Fact

Did you know that dogs have internal clocks? They can sense time and routine—so they'll be ready at exactly 8:00 AM and 5:00 PM for their meals! With this project, you'll always be on time for your dog's feeding schedule.

---

## 🎶 Melody

The food dispenser plays a series of notes for your dog during feeding times:
- **C4, D4, E4, F4, G4, A4, B4** 
- **C5, D5, E5, F5, G5, A5, B5**

---

## 🐕 Example Messages on OLED

- **BARK BARK!! FOOD TIME** 🦴
- **Come Back Later** 🐕‍🦺

---

## 🚀 Future Improvements

- Add an **RTC module** for real-time clock functionality.
- **More feeding schedules**.
- **Customizable meal portions**.

---

## 🐶💬 **Your Pup Will Thank You!**

With the **Deg_Food_Dispenser_MVP**, feeding time becomes a seamless and enjoyable experience for both you and your furry friend. No more worries about missing meals or overfeeding — it's **"BARK BARK!! FOOD TIME"** on time, every time.

---

