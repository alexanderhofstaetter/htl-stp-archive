avr-gcc main.c -Os -std=c99 -o output/output.elf -mmcu=atmega32u4;
avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex output/output.elf output/output.hex
./Loadhex.sh atmega32u4 erase flash output/output.hex start