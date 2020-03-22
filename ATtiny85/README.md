# Compiling examples for ATtiny85

- Go any example folder and run `make`

```bash
$ cd blink
$ make
```
- To compile and burn the HEX file to flash memory.
```bash
$ make flash
```

### NOTE
- ATtiny85 should have USB bootloader flashed on the chip for the above command to work.
- Get ATtiny85 USB bootloader HEX file [here](https://github.com/micronucleus/micronucleus/blob/master/firmware/releases/t85_default.hex) and flash
- Program fuse with the below values 
    - LFUSE = 0xE1 
    - HFUSE = 0xDD 
    - EFUSE = 0xFE