# Programming 8-bit AVR microcontrollers

## Setting up Software environment 

### Windows

- Download and extract [AVR GCC for Windows](https://www.microchip.com/mplab/avr-support/avr-and-arm-toolchains-c-compilers) to `%AVR_TOOLCHAIN_PATH%`
- Download and extract [avrdude](http://download.savannah.gnu.org/releases/avrdude/avrdude-6.3-mingw32.zip) (`avrdude.exe` and `avrdude.conf`) to `%AVR_TOOLCHAIN_PATH%\bin`
- Add `%AVR_TOOLCHAIN_PATH%\bin` to `PATH` environmental variable

### Debian/Ubuntu Linux

- Install `gcc-avr`, `avr-libc`, `make`, `avrdude`

```bash
$ sudo apt -y install gcc-avr avr-libc make avrdude
```

---

## For ATtiny85 USB boards (with bootloader)

### Windows

- Get [micronucleus](https://github.com/micronucleus/micronucleus/raw/master/commandline/micronucleus.exe) and add to `%AVR_TOOLCHAIN_PATH%\bin`
- Install USB driver following the instructions [here](https://github.com/micronucleus/micronucleus/tree/master/windows_driver_installer)

### Linux
- Build and install `micronucleus` tool

```bash
$ sudo apt -y install libusb-dev
$ git clone https://github.com/micronucleus/micronucleus
$ cd commandline
$ sudo make install
```
- Install `udev` rule

```bash
$ sudo cp commandline/49-micronucleus.rules /etc/udev/rules.d/
$ sudo udevadm control --reload-rules 
```