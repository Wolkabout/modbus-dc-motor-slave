/*
 * dc_motor_3_click.c
 *
 *  Created on: Mar 27, 2019
 *      Author: WolkAbout Technology s.r.o.
 */
#include <stdbool.h>
#include <stdint.h>

#include "dc_motor_3_click.h"
#include "dc_motor_3_click_driver_init.h"

void dc_motor3_init(void)
{
    in1_pin_control(false);
    in2_pin_control(false);
    slp_pin_control(true);

    pwm_init();
    pwm_set_duty(0);
}

int32_t dc_motor3_set_speed(uint16_t speed)
{
    return pwm_set_duty(speed);
}

void dc_motor3_short_brake()
{
    in1_pin_control(true);
    in2_pin_control(true);
}

void dc_motor3_stop()
{
    slp_pin_control(true);
    in1_pin_control(false);
    in2_pin_control(false);
}

void dc_motor3_standby()
{
    slp_pin_control(false);
}

void dc_motor3_clockwise()
{
    slp_pin_control(true);
    in1_pin_control(false);
    in2_pin_control(true);
}

void dc_motor3_counter_clockwise()
{
    slp_pin_control(true);
    in1_pin_control(true);
    in2_pin_control(false);
}
