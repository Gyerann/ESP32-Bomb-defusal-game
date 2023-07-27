#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <driver/gpio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

char* toMorse(char ch);

void morse_blink(char* message, int MORSE_PIN);