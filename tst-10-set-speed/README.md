# Set Speed
This test is to verify that the chip is configured correctly and that the prescaler setting works.

If so, a LED on PB1 should blink TIMES_SLOW times, at (DELAY * 2) milliseconds intervals.

Then the chip will speed up to around 16 MHz and PB1 will flash TIMES_FAST times. After that, the chip
will be restored to the original settings and will continue to flash.
