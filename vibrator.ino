//vibrator with modifiable intenstity v1.0 22/08/23
//use reasonable transistor

#define CONTROLLER_PIN 10
#define ADDITION_BUTTON_PIN 9
#define SUBTRACTION_BUTTON_PIN 8

float num = 20.0; //starting value
void setup() {
  pinMode(CONTROLLER_PIN, OUTPUT); //gives out the signal to the transistor
  pinMode(ADDITION_BUTTON_PIN, INPUT); //button that increases num
  pinMode(SUBTRACTION_BUTTON_PIN, INPUT); //button that decreases num
  Serial.begin(9600);
}

void loop() {
  //seems to be a useless check, but whatever, I'll keep it in
  if (num <= 0.0) {
    num = 1.0;
  }
  if (num >= 200.0) {
    num = 200.0;
  }
  //reading input from buttons, doing corresponding addition/subtraction
  if (digitalRead(SUBTRACTION_BUTTON_PIN) == HIGH) {
    num -= num / 50.0;
  }
    if (digitalRead(ADDITION_BUTTON_PIN) == HIGH) {
    num += num / 50.0;
  }
  (int) num; //delay takes in an integer so we have to convert our num variable
  digitalWrite(CONTROLLER_PIN, HIGH);
  delay(num);
  digitalWrite(CONTROLLER_PIN, LOW);
  delay(num);
  Serial.println(num);
}