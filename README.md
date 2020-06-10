# PadCom & PadComLib
A Communication UI and Arduino library for controlling the Arrow Flight Computer in Pad Configuration or controlling your own projects/devices!

![IDE PIC](https://i.imgur.com/Cn5pzh5.png)


PadCom is a Processing (Java) based application that reads, interprets and sends data via Serial. 
PadCom makes it easy to create realistic launch sequences, and monitor your launchpad up to the first seconds of flight!



PadCom is compatiable with "PadComLib" (PRE-ALPHA) which is a Arduino Library that adds support for PadCom in only four lines and a very easy API

[Be sure to check out PadCom's sister project](https://github.com/RockoonTechnologies/BoardCom)
### Features
 - Works with any arduino board and the Arrow Flight Computer
 - Supports custom messages/functions
 - Multiple launch time options
 - Safe Abort system that will disable the pad in case of emergency
 - Has custom library that supports all above features within the Arduino IDE (also supports the Web IDE)


# Setup:

## PadCom
To setup PadCom, copy/download the installer from the directory.

*PadCom requires the latest version of Java & is only verified to work on Windows 10 

Create a shortcut to for the .exe file, and your all set!

Note: Upon the execution of PadCom, the program may take several seconds to finalize and interpret the data, make sure your device is plugged in

## PadComLib
Download the library zip;
[Follow this guide to install a Library from .zip](https://www.arduino.cc/en/guide/libraries#toc4)

# Usage (PadCom)

## PadCom
![IDE PIC](https://i.imgur.com/Cn5pzh5.png)

The light green button labled "Launch Now" will begin the countdown at T-20 seconds.
The light yellow button labled "Begin Countdown" will begin the countdown at T-300 seconds.
Clicking the Red "Abort Button" will instantly pause the countdown and disarm the pad. Clicking one of the prior buttons will restart the countdown at there respective times.

### Send a Custom Message 
 *Custom Message is a Beta-Feature, it is not completely approved 
 
 To send a custom message, just type (there is a currently a bug where backspace does not work).
 Then click "Send" - The message may take a few moments to send as PadCom attempts to sync its communications
 
 A Custom message can be easily linked to an action on your device.



# Integration (Syntax) - How to add support for your board

![code pic](https://i.imgur.com/rx6Ou6q.png)

The Library can be implemented in only four lines of code.

*Make sure to add ```#include <PadComLib.h>``` to the beginning of your code
 
 ##### Initialize
 
 ```initialize();``` simply enables Serial and establishes communication with the PadCom, this means appending ```Serial.begin(9600);``` is not needed, and may cause errors if used. ```initialize()``` should be located in the ```void Setup()``` section of your code, and is a boolean meaning it can be configured to be "true" or "false", On and Off respectively.
 Ex: ```initialize(true);```
 
##### padStatus
 ```padStatus();``` sends the status of the launchpad to the PadCom program. ```padStatus();``` can be located in any function of your code. ```padStatus();```  is a limited string meaning it can be set to parenthesis (ie: ```padStatus("Idle");```) or a String Variable.

*HOWEVER*  ```padStatus();``` can only be three modes: Idle, Countdown, Abort. Any-other string presented will be ignored and no data will be sent. Ex: ```padStatus("Countdown");```

##### mainCom
 ```mainCom();``` sends is the main communication function of the library, so far it controls actual launch commands and custom messages. ```mainCom();``` can be located in any function of your code.  ```mainCom();``` requires four operators, a string, boolean a integer and another string (ex: ```mainCom("custommsg", true, 9, "HIGH);```) the first string is the custom message, make this your custom text (no spaces, cap sensitive, numbers may be clipped) that you type in PadCom that sets an action.
 
 *note: the ability to add a custom action is not available yet in the library*
 The boolean controls whether you want to launch; "true" means yes, "false" means no. 
 
 Think of the last two variables like the ```digitalWrite()``` function, the integer is the pin (has to be digital) and the String is ```HIGH``` or ```Low```. This is the actual action that takes place when launch is set to happen, so if you have a mosfet (for example) on pin 9 that controls the pyro, you use that.
 
 *The pin still must be set as a ouput in ```void setup()```

Ex: ```mainCom("getready", true, 9, HIGH);``` - custom message = getready, will launch when command is sent, send HIGH to pin 9


# Troubleshooting (PadCom)

*I installed the program but on boot the program is static and is a frozen grey window, like my soul*


   This can be a number of reasons. Make sure java is installed and you have the correct version for your architecture.
   If this does not work, see if the "Roboto-Light" font file is present, if not the program may crash.
   Lastly, make sure your Flight Computer or Arduino is plugged in and operating, if a serial device is not detected the program may crash or fail to boot.

# RoadMap:

- Finalize custommsg
- [x] Make lib 
- Add support for minutes

# Extra Info

- Can support any Arduino Device (still test Mbed OS)
- Palette: https://coolors.co/000f08-136f63-e0ca3c-f34213-3e2f5b
- PadCom has aims refresh rate of .999 seconds, changes are not instant
