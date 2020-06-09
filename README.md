# BoardCom
A Communication UI/Terminal for controling the Arrow Flight Computer in Pad Configuration or controlling your own projects!
![IDE PIC](https://i.imgur.com/Cn5pzh5.png)


PadCom is a Processing (Java) based application that reads, interprets and sends data via Serial. 
PadCom makes it easy to create realistic launch sequences, and monitor your launchpad up to the first seconds of flight!


[Be sure to check out PadCom's sister project!](https://github.com/RockoonTechnologies/BoardCom)
### Features
 - Works with any arduino board and the Arrow Flight Computer
 - Supports custom messages
 - Multiple launch time options
 - Safe Abort system that will disable the pad in case of emergency
 - Can be customized inside the Arduino IDE


# Setup:
To setup PadCom, copy/download the application folder from the directory.

*PadCom requires the latest version of Java & is only verified to work on Windows 10 

Create a shortcut to for the .exe file, and your all set!
Note: Upon the execution of PadCom, the program may take several seconds to finalize and interpret the data

# Usage
![IDE PIC](https://i.imgur.com/Cn5pzh5.png)

The light green button labled "Launch Now" will begin the countdo
wn at T-20 seconds
The light yellow button labled "Begin Countdown" will begin the countdown at T-300 seconds
Clicking the Red "Abort Button" will instantly pause the countdown and disarm the pad. Clicking one of the prior buttons will restart the countdown at there repsective times.

### Send a Custom Message
 *Custom Message is a Beta-Feature, it is not completely approved 
 
 To send a custom message, just type (there is a currently a bug where backspace does not work).
 Then click "Send" - The message may take a few moments to send as PadCom attempts to sync its communications
 
 A Custom message can be easily linked to an action on your device.

# Demo:

A quick demonstration of the functionality of PadCom is in the Demo folder.

Using the Arduino IDE, load the provided .ino file onto the your Arduino device. Then procceed to execute the PadCom application.
You can start a countdown with the respective button(s), Abort and send a preconfigured custom message ("poll", which just blinks leds)



# Integration - How to add support for your board

This is a snippet of code that proves as an example of basic implementation.

```String incomingByte = ""; // for incoming serial data
String custommsg = "poll";
String padstatus = "Idle";

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
 
  
  Serial.print(padstatus); //prints pad status (can be changed like anyother variable depending on the pads status
  delay(1000); // keep this, makes it easier on program
  if (Serial.available() > 0) { // detects if new data is available
    
    incomingByte = Serial.readString();  // reads new data
    if (incomingByte.equals(custommsg) == true) // sees if new data is your custom message
     
      digitalWrite(LED_BUILTIN, HIGH);
      delay(500);
      digitalWrite(LED_BUILTIN, LOW);
     
     }
    if (incomingByte.equals("launch") == true) // checks if new data is the command to launch
      //code to run. Ex: Mosfet Pin- HIGH
      digitalWrite(LED_BUILTIN, HIGH);
      delay(500);
      digitalWrite(LED_BUILTIN, LOW);
      
     }
}
}
```

Essentially, you can configure the variables, "custommsg" to whatever your custom message is, and append the code necessary for your code to take place, EX - move servo, LED, etc.

When its ready to launch, PadCom will always output "launch", meaning don't change the ```if (incomingByte.equals("launch") == true)``` line

# Troubleshooting

*I installed the program but on boot the program is static and is a frozen grey window*


   This can be a number of reasons. Make sure java is installed and you have the correct version for your architecture.
   If this does not work, see if the "Roboto-Light" font file is present, if not the program may crash.
   Lastly, make sure your Flight Computer or Arduino is plugged in and operating, if a serial device is not detected the program may crash or fail to boot.

# RoadMap:

- Finalize custommsg
- Make lib
- Add support for minutes
