#include <driver/ledc.h>

void set_servo_angle(int PWM_PIN, int angle);
void init_pwm_fade(int channel);