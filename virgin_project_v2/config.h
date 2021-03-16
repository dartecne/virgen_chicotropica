#ifndef CONFIG_H
#define CONFIG_H

#define LEG_LEFT_PIN    13
#define LEG_RIGHT_PIN  12
#define ARM_LEFT_PIN   11
#define ARM_RIGHT_PIN  10
#define EYES_PIN        9
#define EYE_LEFT_PIN      6
#define EYE_RIGHT_PIN      5
#define HEART_PIN      3
#define GSING_1     7
#define GSING_2    4
#define GSING_3    2

#define LEG_LEFT_ID   0
#define LEG_RIGHT_ID  1
#define ARM_LEFT_ID   2
#define ARM_RIGHT_ID  3
#define EYES_ID       4
#define EYE_LEFT_ID   5
#define EYE_RIGHT_ID  6
#define HEART_ID      7

#define EYES_OPEN  10
#define EYES_CLOSE  110

#define ARM_LEFT_DOWN  90
#define ARM_RIGHT_DOWN  90
#define ARM_LEFT_UP  10
#define ARM_RIGHT_UP  170

#define TAU  10
#define NUM_DOF  8

/* Range of all the servo in the application. In 3 seconds */
int p_servo_all_range[2] = {90, 150};
int t_servo_all_range[2] = {0, 3000};

/* Range of left arm in the application. In 3 seconds */
int p_arm_left_all_range[2] = {ARM_LEFT_DOWN, ARM_LEFT_UP};
int t_arm_left_all_range[2] = {0, 3000};

/* Range of right arm in the application. In 3 seconds */
int p_arm_right_all_range[2] = {ARM_RIGHT_DOWN, ARM_RIGHT_UP};
int t_arm_right_all_range[2] = {0, 3000};

/* Range of all the eyes in the application. In 3 seconds */
int p_eyes_all_range[2] = {EYES_CLOSE, EYES_OPEN};
int t_eyes_all_range[2] = {0, 3000};

/* Range of analog leds in 3 secs */
int p_analog_led_all_range[2] = {0, 255};
int t_analog_led_all_range[2] = {0, 3000};

/* Range of digital leds in 3 secs */
int p_digital_led_all_range[2] = {0, 2};
int t_digital_led_all_range[2] = {0, 3000};

/* points for sexy gesture */
int p_arm_left_up[2] = { ARM_LEFT_DOWN, 70 }; /* up 20º */
int p_arm_right_up[2] = { ARM_RIGHT_DOWN, 110 }; /* up 20º */
int p_arm_left_down[2] = { 70, ARM_LEFT_DOWN }; /* up 20º */
int p_arm_right_down[2] = { 110, ARM_RIGHT_DOWN }; /* up 20º */
int t_arm_up[2] = {0, 4000};
int p_eyes_double_blink[6] = {EYES_OPEN, EYES_CLOSE, EYES_OPEN, EYES_OPEN, EYES_CLOSE, EYES_OPEN};
int t_eyes_double_blink[6] = {0, 200, 400, 3600, 3800, 4000};
int p_eye_led_on[2] = { 255, 255 };
int p_heart_pulse[8] = {255, 0, 255, 0, 255, 0, 255, 0 };
int t_heart_pulse[8] = {0, 500, 1000, 1500, 2000, 2500, 3000, 4000};
int p_leg_blink_at_end[8] = {0, 0, 2, 0, 2, 0, 2, 0};
int p_leg_blink_at_end_long[16] = {0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2};
int p_leg_blink_at_end_contra_long[16] = {2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0};
int p_leg_blink_at_end_contra[8] = {2, 2, 0, 2, 0, 2, 0, 0};
int t_leg_blink_at_end[8] = {0, 3000, 3100, 3300, 3500, 3700, 3800, 3900};
int t_leg_blink_at_end_long[16] = {0, 1800, 2000, 2200, 2400, 2600, 2700, 2800, 2900, 3000, 3100, 3300, 3500, 3700, 3800, 3900};
int t_leg_blink_at_begin[8] = {0, 200, 300, 400, 500, 600, 800};

/* points for idle */
int p_arm_left_up_down[2] = { 80, ARM_LEFT_DOWN }; 
int p_arm_right_down_up[2] = { ARM_RIGHT_DOWN, 100 }; 
int t_leg_blink_at_begin_fast[9] = {0, 50, 100, 150, 200, 250, 300, 4000};

/* points for sexy 2 */
int p_arm_left_vibra[6] = { 60, ARM_LEFT_DOWN, 60, ARM_LEFT_DOWN, 60, ARM_LEFT_DOWN }; /* up 20º */
int p_arm_right_vibra[6] = { ARM_RIGHT_DOWN, 120, ARM_RIGHT_DOWN, 120, ARM_RIGHT_DOWN, 120}; /* up 20º */
int p_eye_led_vibra_1[4] = { 0, 255, 0, 255 };
int p_eye_led_vibra_2[4] = { 255, 0, 255, 0 };
int t_eye_led_vibra[4] = { 0, 1000, 2500, 4000 };

/* Initial Test */
int p_1[6] = {90, 95, 100, 110, 120, 180};
int t_1[6] = {0, 100, 150, 300, 1500, 3000};

#endif
