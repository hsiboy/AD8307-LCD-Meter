// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//pwr sensor stuff
const int sensorpin = A0;
void setup() {
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);
  // Print a message to the LCD.

}
void loop() {
  // power in
  int sensorval = analogRead(sensorpin);
  float voltage = (sensorval / 1024.0) * 5.0;
  float pwr = ((voltage - 0.269) * 40) - 77;
  float volts = ((voltage - 0.269) * 40);
  float pwrW = pow(10, ((pwr - 30) / 10));
  float vts = sqrt(pwrW * 50);
  float ptp = vts * 2.828;
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Pwr ");
  lcd.print(pwr, 1);
  lcd.print("dBm PtP ");
  lcd.setCursor(0, 1);
  if (vts > 0.9)
  {
    lcd.print(" V ");
    lcd.print(vts, 2);
    float ptp = vts * 2.828;
    lcd.print(" ");
    lcd.print(ptp, 2);
  }
  if (vts < 1 and vts > 0.001)
  {
    vts = vts * 1000;
    lcd.print("mV ");
    lcd.print(vts, 2);
    float ptp = vts * 2.828;
    lcd.print(" ");
    lcd.print(ptp, 2);
  }
  if (vts < .001)
  {
    vts = vts * 1000000;
    lcd.print("uV ");
    lcd.print(vts, 2);
    float ptp = vts * 2.828;
    lcd.print(" ");
    lcd.print(ptp, 2);
  }

}
