/*
 * modbus_configuration.c
 *
 *  Created on: Mar 27, 2019
 *      Author: WolkAbout Technology s.r.o.
 */
#include "modbus_configuration.h"
#include "modbus.h"

modbus_variables_map_t modbus_variables_map;

void modbus_register_mapping_init(void)
{
    modbus_variable_init(&modbus_variables_map.speed[0], &HoldingRegister[SPEED]);

    modbus_variable_init(&modbus_variables_map.direction, &Coils[DIRECTION]);
    modbus_variable_init(&modbus_variables_map.stop_start, &Coils[STOP_START]);
    modbus_variable_init(&modbus_variables_map.short_brake, &Coils[SHORT_BRAKE]);
    modbus_variable_init(&modbus_variables_map.stand_by, &Coils[STAND_BY]);
}
