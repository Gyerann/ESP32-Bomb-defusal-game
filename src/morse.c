#include <morse.h>

char* toMorse(char ch) {
    char* morse[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
        "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
    };

    if (isalpha(ch)) {
        ch = toupper(ch);
        return morse[ch - 'A'];
    } else if (isdigit(ch)) {
        return morse[ch - '0' + 26];
    }

    return "";
}

void morse_blink(char* message, int MORSE_PIN) {
    //Length of . and -
    int dotTime = 17;
    int dashTime = 50;

    char* morseCode;

    for (int i = 0; i < strlen(message); i++) {
        char ch = message[i];
        morseCode = toMorse(ch);

        for(int i = 0; i < strlen(morseCode); i++) {
            if (morseCode[i] == '.') {
                gpio_set_level(MORSE_PIN, 1);
                vTaskDelay(dotTime / portTICK_PERIOD_MS);
                gpio_set_level(MORSE_PIN, 0);
            } else if (morseCode[i] == '-'){
                gpio_set_level(MORSE_PIN, 1);
                vTaskDelay(dashTime / portTICK_PERIOD_MS);
                gpio_set_level(MORSE_PIN, 0);
            }
            
        }

    }
}