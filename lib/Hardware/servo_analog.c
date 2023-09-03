#include "./servo_analog.h"

#define PWM_FREQ 50
#define PWM_MAX_DUTY 8192
#define PWM_CHANNEL LEDC_CHANNEL_0
#define PWM_TIMER LEDC_TIMER_0

#define SERVO_MIN_ANGLE 0
#define SERVO_MAX_ANGLE 180
#define SERVO_MIN_DUTY 500
#define SERVO_MAX_DUTY 2400

void init_pwm_fade(int channel){
  ledc_fade_func_install(channel);
}

void set_servo_angle(int PWM_PIN, int angle){

  ledc_fade_func_install(LEDC_CHANNEL_0);

  uint32_t duty = (uint32_t) (angle * (4095.0 / 180.0));
  
  // Configure PWM output
  ledc_timer_config_t timer_conf = {
    .duty_resolution = LEDC_TIMER_12_BIT,
    .freq_hz = PWM_FREQ,                 
    .speed_mode = LEDC_HIGH_SPEED_MODE,  
    .timer_num = PWM_TIMER               
  };
  ledc_timer_config(&timer_conf);
  
  ledc_channel_config_t channel_conf = {
    .channel = PWM_CHANNEL,
    .duty = duty,
    .gpio_num = PWM_PIN,
    .speed_mode = LEDC_HIGH_SPEED_MODE,
    .timer_sel = PWM_TIMER
  };
  ledc_channel_config(&channel_conf);
  
  ledc_set_duty_and_update(LEDC_HIGH_SPEED_MODE, PWM_CHANNEL, duty, 0);
}
