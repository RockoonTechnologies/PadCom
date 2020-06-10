/*

*/
#include <PadComLib.h>

void setup() {
  
  initialize(true);
}

void loop() {
  padStatus("Abort");
  maincom("custom", true, 9, "HIGH");
  
}


