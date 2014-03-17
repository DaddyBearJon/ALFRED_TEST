// Do not remove the include below
#include "ALFRED_TEST.h"

#define LED 13 // This is the L LED
#define one_sec 1000000
#define ten_sec 10000000
#define thirty_sec 30000000


byte com = 0;
byte error = 0;
byte timerCounter = 0;
boolean connected;
char serialData[32];
long Timer2Period = 0L;
bool init_watchdog = false;
void reset()
{
	digitalWrite(LED, LOW);
    connected = false;
}


boolean parseCommand(char* command, int* returnValues, byte returnNumber)
/**
 * This function makes int's out of the received serial data, the 2 first
 * characters are not counted as they consist of the command character and
 * a comma separating the first variable.
 *
 * @params command The whole serial data received as an address
 * @params returnValues The array where the return values go as an address
 * @params returnNumber The number of values to set inside the returnValues variable
 */
{
  // parsing state machine
  byte i = 1, j = 0, sign = 0, ch = 0, number;
  int temp = 0;
  while(i++) // keep incrementing i until we break
  {
    switch(*(command + i))
    {
    case '\0': //or the next one
    case ':':
    case ',':
      // set return value
      if(ch != 0)  // looking for a number ch = 0 until we find a number
      {
        returnValues[j++] = sign?-temp:temp; // If sign then temp = negative else it's positive
        sign = 0;
        temp = 0;
        ch = 0;
      }
      else
      {
        return false;
      }
      break;
    case '-':
      sign = 1;
      break;
    default:
      // convert string to int
      number = *(command + i) - '0';
      if(number < 0 || number > 9)
      {
        return false;
      }
      temp = temp * 10 + number;
      ch++;
    }

    // enough return values have been set
    if(j == returnNumber)
    {
      return true;
    }
    // end of command reached
    else if(*(command + i) == '\0')
    {
      return false;
    }
  }
}

void timeout_handler()
{
    // no data has been passed since last time
    // interpret as communication failure
    reset();

}
//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
	Serial.begin(115200);
	Serial.println("Bluetooth test!");
	pinMode(LED, OUTPUT);
	// the bluetooth dongle communicates at 115200 baud only
	Serial1.begin(115200);
	// set up timeout timer on timer2 in case of lost connection
	// Initialise counter
	Timer2.attachInterrupt(timeout_handler); //Initialise timed interrupt
	Timer2.start(ten_sec); // Call thirty second timed interrupt
	init_watchdog = true;
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
	  if(Serial1.available() > 0)
	  {
		  Timer2.stop();
		  init_watchdog = false;
		  digitalWrite(LED, HIGH);
		  connected = true;

	    Serial1.readBytesUntil('\n', serialData, 31);
	    switch(serialData[0])
	    {
	    case 0:
	      Serial1.println(0);
	      break;
	    case 'd':
	      // set left and right motor speeds
	    	Serial.println(serialData);
	      int speed[2];
	      if(parseCommand(serialData, speed, 2))
	      {
	        //setSpeed(speed[0], speed[1]);
	        Serial1.println("New speed set");
	        Serial1.print("Speed A = ");
	        Serial1.print(speed[0]);
	        Serial1.println(" %");
	        Serial1.print("Speed B = ");
	        Serial1.print(speed[1]);
	        Serial1.println(" %");
	      }
	      else
	      {
	        Serial1.println("Error while setting new speed");
	      }
	      break;
	    case 'i':
	    case 'I':
	      // inform about robot
	      Serial1.println("ALFRED TEST");
	      break;
	    case 'r':
	      // quickly stop
	      reset();
	      Serial1.println("Robot reset");
	      break;
	    default:
	      // inform user of non existing command
	      Serial1.println("Command not recognised");
	    }

	    // clear serialData array
	    memset(serialData, 0, sizeof(serialData));
	  }
	  else
	  {

		 // Timer2.attachInterrupt(timeout_handler); //Initialise timed interrupt
		 if (!init_watchdog)
		 {
			 Timer2.start(ten_sec); // Call thirty second timed interrupt
			 init_watchdog = true;
		 }

	  }
}
