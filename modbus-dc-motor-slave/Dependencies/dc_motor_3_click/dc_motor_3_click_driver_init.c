/*
 * dc_motor_3_click_driver_init.c
 *
 *  Created on: Mar 27, 2019
 *      Author: WolkAbout Technology s.r.o.
 */
#include <stdbool.h>
#include <stdint.h>

#include "dc_motor_3_click_driver_init.h"
#include "main.h"

extern TIM_HandleTypeDef htim4;

void in1_pin_control(bool state)
{
    HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, state);
}

void in2_pin_control(bool state)
{
    HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, state);
}

void slp_pin_control(bool state)
{
    HAL_GPIO_WritePin(SLP_GPIO_Port, SLP_Pin, state);
}

int32_t pwm_init(void)
{
    return HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
}

int32_t pwm_set_duty(uint16_t duty_cycle)
{
    if (duty_cycle < 0 || duty_cycle > 200)
        return false;

    return __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_1, duty_cycle);
}

