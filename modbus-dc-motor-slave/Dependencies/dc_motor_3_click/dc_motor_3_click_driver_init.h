/*
 * dc_motor_3_click_driver_init.h
 *
 *  Created on: Mar 27, 2019
 *      Author: WolkAbout Technology s.r.o.
 */

#ifndef DC_MOTOR_3_CLICK_DRIVER_INIT_H_
#define DC_MOTOR_3_CLICK_DRIVER_INIT_H_

/**
 * @brief 		Control signal input 1. Together with in2 it is used for set
 * motor direction or to stop it.
 *
 * @param state Can be true or false.
 *
 * @return 		None
 */
void in1_pin_control(bool state);

/**
 * @brief 		Control signal input 2. Together with in1 it is used for set
 * motor direction or to stop it.
 *
 * @param state Can be true or false.
 *
 * @return 		None
 */
void in2_pin_control(bool state);

/**
 * @brief 		Standby pin. Set motor into Start mode(equals High) or in
 * Standby mode(equals Low).
 *
 * @param state Can be true or false.
 *
 * @return 		None
 */
void slp_pin_control(bool state);

/**
 * @brief 		PWM initialization. The functions to initialize PWM need to
 * be called here. PWM is used for controlling speed of the motor.
 *
 * @param 		None
 *
 * @return 		Error Code
 */
int32_t pwm_init(void);

/**
 * @brief 		Set PWM duty cycle. It will determine duration of high
 *state in square impulse.
 *
 * @param duty_cycle 	Depending of HAL setup of PWM. Boundaries are values
 *that determines duration of high value in square impulse. For defined PWM
 *range of duty cycle is [0-200], which is DC motor speed.
 *
 * @return		Error Code
 */
int32_t pwm_set_duty(uint16_t duty_cycle);

#endif /* DC_MOTOR_3_CLICK_DRIVER_INIT_H_ */
