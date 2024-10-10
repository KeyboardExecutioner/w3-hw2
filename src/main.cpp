#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

LED led(LED_PIN, LED_ACT);
LED led2(LED_PIN2, LED_ACT);
int label = 1;

void btnPush();
void btnDouble();
void btnHold();
OneButton button(BTN_PIN, !BTN_ACT);

void setup()
{
    led.off();
    led2.off();
    button.attachClick(btnPush);
    button.attachDoubleClick(btnDouble);
    button.attachLongPressStart(btnHold);
}

void loop()
{
    led.loop();
    led2.loop();
    button.tick();
}

void btnPush()
{
    if(label == 1){
        led.flip();
    }
    if(label == 2){
        led2.flip();
    }
}

void btnDouble()
{
    if(label == 1){
        label = 2;
    }
    if(label == 2){
        label = 1;
    }
}

void btnHold()
{
    if(label == 1){
        led.blink(200);
    }
    if(label == 2){
        led2.blink(200);
    }
}