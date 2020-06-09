String incomingByte = ""; // for incoming serial data
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
