# Minix Real-Time Clock Driver Improvement #

This is a homework assignment (#4) for COMP410 [Fall 2011] - Operating Systems at Loyola University.

The assignment was to modify a given real-time clock driver for minix to improve it's performance. 

I modified the provided clock driver file (ORIG-time.c), made a small modification on line 140 (time.c) and installed it as a clock driver. I saw an improvement from 1 read/s to over 1000 reads/sec with this modification.

Included are two test read programs - one for just making reads to the character device (test-read.c) and one for actually profiling the speed of the device (read-device.c). Additionally, there's a short script (replace.sh) to replace the originally installed file with the new one to aid in testing.