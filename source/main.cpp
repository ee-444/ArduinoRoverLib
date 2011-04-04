
#include "main.h"
#include "ArduinoRoverLib.h"

int main(void)
{
    init();
	pinMode(13, OUTPUT);      // sets the digital pin as output

	while(1){
		digitalWrite(13, HIGH);   // sets the LED on
  		delay(1000);                  // waits for a second
  		digitalWrite(13, LOW);    // sets the LED off
  		delay(1000);
	}
        
	return 0;
}

