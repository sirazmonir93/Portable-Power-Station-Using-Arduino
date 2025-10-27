unsigned long previousMillis = 0;
const long interval = 10; // 20 ms for a 50 Hz PWM signal
int pwmState = 0; // 0 or 1 to alternate between pins 2 and 4
#define PWM_PIN 9
#define ANALOG_PIN_A0 A0
#define ANALOG_PIN_A1 A1
const int numReadings = 10;
int readingsA0[numReadings];
int readingsA1[numReadings];
int index = 0;
int totalA0 = 0;
int totalA1 = 0;
int a;
int x = 10;
void setup() {
 pinMode(2, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(PWM_PIN, OUTPUT);
 Serial.begin(9600);
 TCCR1B = TCCR1B & 0b11111000 | 0x01; // set timer 1 divisor to 1 for PWM
frequency of 31372.55 Hz
}
void loop() {
 // Smooth out the reading from A0
 totalA0 = totalA0 - readingsA0[index];
 readingsA0[index] = analogRead(ANALOG_PIN_A0);
 totalA0 = totalA0 + readingsA0[index];
 // Smooth out the reading from A1
 totalA1 = totalA1 - readingsA1[index];
 readingsA1[index] = analogRead(ANALOG_PIN_A1);
 totalA1 = totalA1 + readingsA1[index];
 index = (index + 1) % numReadings;
 int smoothedA0 = totalA0 / numReadings;
 int smoothedA1 = totalA1 / numReadings;
 a= smoothedA1-smoothedA0;
 if (a>200)
 {
 x=x-1;

 }
if (a<200)
 {
 x=x+1;

 }
 analogWrite(PWM_PIN, x); // Example PWM output, not affected by
smoothing
 unsigned long currentMillis = millis();
 if (currentMillis - previousMillis >= interval) {
 previousMillis = currentMillis;
 // Toggle between pins 2 and 4
 pwmState = 1 - pwmState;
 // Set the duty cycle based on the current PWM state
 if (pwmState == 0) {
 digitalWrite(2, HIGH); // 50% duty cycle on pin 2
 digitalWrite(4, LOW); // 0% duty cycle on pin 4
 } else {
 digitalWrite(2, LOW); // 0% duty cycle on pin 2
 digitalWrite(4, HIGH); // 50% duty cycle on pin 4
 }
 }
}
