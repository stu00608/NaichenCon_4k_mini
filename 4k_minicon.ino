#include "Keyboard.h"

#define BUTTON_NUM 4

typedef struct{
  uint8_t btnPin;
  uint8_t ledPin;
  char data;
  bool state;
}Button;

uint8_t buttonPinList[BUTTON_NUM] = {9, 8, 5, 2};
uint8_t buttonLedList[BUTTON_NUM] = {10, 16, 18, 21};
char buttonDataList[BUTTON_NUM] = {'a', 'b', 'c', 'd'};

bool state[BUTTON_NUM] = {false};

Button button_list[BUTTON_NUM];

void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<BUTTON_NUM;i++){
    button_list[i].btnPin = buttonPinList[i];
    button_list[i].ledPin = buttonLedList[i];
    pinMode(button_list[i].btnPin,INPUT_PULLUP);
    pinMode(button_list[i].ledPin,OUTPUT);
    digitalWrite(button_list[i].ledPin,LOW);
    button_list[i].data = buttonDataList[i];
    button_list[i].state = false;
  }

  Keyboard.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<BUTTON_NUM;i++) button_list[i].state = (digitalRead(button_list[i].btnPin)==LOW)? HIGH:LOW;

  for(int i=0;i<BUTTON_NUM;i++){
    if(button_list[i].state){
        Keyboard.press(button_list[i].data);
        digitalWrite(button_list[i].ledPin,HIGH);
    }else{
        Keyboard.release(button_list[i].data);
        digitalWrite(button_list[i].ledPin,LOW);
    }
  }
}
