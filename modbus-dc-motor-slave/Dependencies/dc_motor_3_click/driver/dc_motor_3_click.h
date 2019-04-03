/*
 * dc_motor_3_click.h
 *
 *  Created on: Mar 27, 2019
 *      Author: WolkAbout Technology s.r.o.
 */

#ifndef DC_MOTOR_3_CLICK_DC_MOTOR_3_CLICK_H_
#define DC_MOTOR_3_CLICK_DC_MOTOR_3_CLICK_H_

/**
 * @brief 		DC motor initialization. Set initial direction and set speed
 * to zero by controlling GPIO's and PWM. Initially motor will be stopped.
 *
 * @param 		None
 *
 * @return 		None
 */
void dc_motor3_init(void);

/**
 * @brief 		Control DC motor speed. This is related to used DC motor
 * driver.
 *
 * @param speed Speed can be set in range. This range is determinated by used
 * PWM and it's configuration. PWM frequency needs to be 100kHz.
 *
 * @return 		Error Code
 */
int32_t dc_motor3_set_speed(uint16_t speed);

/**
 * @brief 		DC motor short brake mode. This function will cause
 * immediately stop.
 *
 * @param 		None
 *
 * @return 		None
 */
void dc_motor3_short_brake();

/**
 * @brief 		DC motor stop mode. This function will cause normal
 * stop.
 *
 * @param 		None
 *
 * @return 		None
 */
void dc_motor3_stop();

/**
 * @brief 		DC motor stop mode. This function will cause soft stop.
 *
 * @param 		None
 *
 * @return 		None
 */
void dc_motor3_standby();

/**
 * @brief 		Set DC motor direction like clockwise.
 *
 * @param 		None
 *
 * @return 		None
 */
void dc_motor3_clockwise();

/**
 * @brief 		Set DC motor direction opposite of clockwise which is called
 * counterclockwise or anticlockwise.
 *
 * @param 		None
 *
 * @return 		None
 */
void dc_motor3_counter_clockwise();

#endif /* DC_MOTOR_3_CLICK_DC_MOTOR_3_CLICK_H_ */
