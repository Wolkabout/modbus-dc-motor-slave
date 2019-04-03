/*
 * driver_init.c

 *
 *  Created on: Mar 27, 2019
 *      Author: WolkAbout Technology s.r.o.
 */
#include "driver_init.h"

/*
 * UART IRQ's
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart)
{
    if (huart->Instance == USART2) {
        __HAL_UART_CLEAR_PEFLAG(&huart2);

        rx_cb_modbus_dependencies_usart();
    }
}
void HAL_UART_TxCpltCallback(UART_HandleTypeDef* huart)
{
    tx_cb_modbus_dependencies_usart();
}


void rs485_interface_init(void)
{
    __HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);
}

void usart_enable(void)
{
    __HAL_UART_ENABLE(&huart2);
}

void usart_disable(void)
{
    __HAL_UART_DISABLE(&huart2);
}

int32_t write_byte(const uint8_t* const buf)
{
    return HAL_UART_Transmit_IT(&huart2, (uint8_t*)buf, 1);
}

int32_t read_byte(uint8_t* const buf)
{
    *buf = huart2.Instance->DR;

    return true;
}


void gpio_set_re_pin_level(bool state)
{
    HAL_GPIO_WritePin(RE_GPIO_Port, RE_Pin, state);
}

void gpio_set_de_pin_level(bool state)
{
    HAL_GPIO_WritePin(DE_GPIO_Port, DE_Pin, state);
}

void led_tx(bool state)
{
    HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, state);
}
void led_rx(bool state)
{
    HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, state);
}


uint8_t timer_init(void)
{
    HAL_StatusTypeDef result = HAL_TIM_Base_Start_IT(&htim3);
    if (result > 0)
        return result;

    return timer_stop();
}

int8_t timer_start()
{
    return HAL_TIM_Base_Start_IT(&htim3);
}

uint8_t timer_stop()
{
    return HAL_TIM_Base_Stop_IT(&htim3);
}
