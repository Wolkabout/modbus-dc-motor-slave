# modbus-dc-motor-slave
This repo implementation of Modbus slave which can control DC motor. It is based on Mikroe development boards with STM32F40x MCU.

DC motor control supports features like motor speed, direction, str/stop, shortbrake and standby. All of this features can be achieved changing Modbus registers. Modbus register mapping is below:

| REG.TYPE   | NAME         | DESCRIPTION                                                             | VALUE RANGE | DEFAULT VALUE |
|------------|--------------|-------------------------------------------------------------------------|-------------|---------------|
| H.Register | Speed        | Motor speed                                                             | [0-200]     | 0             |
| Coil       | Direction    | 1 = clockwise<br>0 = counter clockwise                                  | [0-1]       | 1             |
| Coil       | Stop & Start | 1 = start<br>0 = stop                                                   | [0-1]       | 0             |
| Coil       | Short Brake  | 1 = active - It will cause changing  Stop&Start Coil to zero<br>0 = inactive | [0-1]       | 0             |
| Coil       | Stand by     | 1 = active - It will cause changing  Stop&Start Coil to zero<br>0 = inactive | [0-1]       | 0             |

RS-485 communiction interface settings are:
* Bits per second: 115200bps
* Data bits: 8
* Stop bits: 1
* Parity: none
* Timeout: 0.5 s - (tested value, could be set to a lower one).
* Poll rate: 50 ms - (tested value, could be set to a lower one).
 
## Dependencies

##### HW
* [Clicker 2 for STM32](https://www.mikroe.com/clicker-2-stm32f4)
* [RS485 click](https://www.mikroe.com/rs485-33v-click)
* [DC MOTOR 3 Click](https://www.mikroe.com/dc-motor-3-click)
* [DC Motor Precision Gearmotor - 45 RPM (6-12V)](https://www.sparkfun.com/products/retired/12514). You can use any other DC motor which satisfies driver characteristics.

##### SW
 * [STM32Cube initialization code generator](https://www.st.com/en/development-tools/stm32cubemx.html)
 * [SW4STM32](https://www.st.com/en/development-tools/sw4stm32.html)
 * [USB HID bootloader for Clicker 2 board](https://download.mikroe.com/examples/starter-boards/clicker-2/stm32f4/clicker-2-stm32f4-mikrobootloader-usb-hid-v130.zip)

## Example of Usage

##### Running
Default device address is `1` in this example and it has configured Modbus as it is described above.

Use USB HID bootloader for Clicker 2 board or use [ST LINK/V2 programmer](https://www.st.com/en/development-tools/st-link-v2.html) with appropriate software to programm file:

`modbus-dc-motor-slave/Debug/modbus-dc-motor-slave.hex`

##### Edit source
Import project into SW4STM32 and insert changes. Minimal change that you can make is to change slave address by editing this line `#define SLAVE_ADDRESS 1`

For further editing look at `doc` folder.
