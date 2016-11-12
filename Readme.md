#VescUartControl library
tested with
- Arduino 1.6.11
- Teensyduino 1.30 
- VESC FW 2.18 with communications addon from me UART communication speed should be 256800
- Teensy 3.1 Board
- VESC 4.7 Board

Library for arduino to interface over UART with the Vesc BLDC controler (http://vedder.se/2015/01/vesc-open-source-esc/)
It is used in my own not yet published project.

The files

crc

datatypes

buffer

are directly forked from https://github.com/vedderb/bldc


All available UART handlers the VESC can deal with can be found in the file commands.c (https://github.com/vedderb/bldc)
in the function commands_process_packet. You can write easily own handler functions. Use converting functions in 
the library buffer.c.

The rest shut be comment sufficient in the VescUart.h. and the examples

##Requirements to use this library on bldc FW

The needed changes for the function "UartGetLimits" where hopefully merged by Vedder to the FW in the next time.
At this time only
- begin
- UartSetCurrent
- UartSetCurrentBrake
- UartGetValue

are working with standard VESC FW 2.18 is tested with Teensyduino 3.1 but should work with Arduino also but is untested.

In bldc-tool please activate UART and select a baud rate of 256800.



##Some details to the UART port used in the VESC

It is a uint8_t byte stream. 

First byte: 

0x02 for payload length of 256 byte >> next byte is for the payload length 

0x03 for >256 byte payload length  >> next 2 byte for the payload length - not supported

The follwing 2 bytes after the payload are the checksum. (see crc.h)

The byte stream it terminated with a 0x03.

For more details please refer also to http://vedder.se/2015/10/communicating-with-the-vesc-using-uart/



