# Compiling examples for ATMega328P / Arduino Uno

- Go any example folder and run `make`

```bash
$ cd blink
$ make
```
- To compile and burn the HEX file to flash memory. Specify correct COM port.
```bash
$ make flash PORT=COM22
```
### NOTE
- ATmega328P should have bootloader flashed on the chip for the above command to work.
- Get Arduino Uno bootloader HEX file [here](https://github.com/arduino/ArduinoCore-avr/blob/master/bootloaders/optiboot/optiboot_atmega328.hex) 
