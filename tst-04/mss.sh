#!/bin/bash

# Clean all
make squeaky_clean

# Make all
make all

# Flash Tiny85 with an USBasp
make flash

# Flash Tiny85 with an STK500
# make flash_stk500

if avrdude -c usbasp -p attiny85 -B3 -U lfuse:r:lfuse.hex:h -U hfuse:r:hfuse.hex:h -U efuse:r:efuse.hex:h 2>>/dev/null;
then
	echo "AVR microcontroller fuses"
	echo "========================="
    echo "Low fuse = [`cat lfuse.hex`]"
    echo "High fuse = [`cat hfuse.hex`]"
    echo "Extended fuse = [`cat efuse.hex`]"
	rm lfuse.hex hfuse.hex efuse.hex;
else
	echo "AVRdude execution error!";
fi
