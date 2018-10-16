#include <stdio.h>
#include <wiringPi.h>
#include "ifttt.h"

int main(int argc, char *argv[])
{
/*
  ifttt("https://maker.ifttt.com/trigger/button_pressed/with/key/56-YpOKO17vOh-gimC2xK1qRAhRdzXXXX", "my1", "my 2", "my 333334");
*/
  wiringPiSetup () ;
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  while(1) {
    printf("Waiting for reset\n");
    digitalWrite (1, HIGH);
    digitalWrite (2, LOW);
    while(digitalRead(0) == 1);
    printf("Alarms off!\n");
    ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/214438469", "Alarms Off", "shiyi", "du");
    digitalWrite (2, HIGH);
    digitalWrite (1, LOW);
    printf("Waiting for event\n");
    while(digitalRead(0) == 0);
    printf("Motion Detected! Trying to connect to server\n");
    ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/214438469", "Motion Detected", "shiyi", "du");
    printf("Alarm\n");
  }
  /*NOTREACHED*/  
  return 0;
}
