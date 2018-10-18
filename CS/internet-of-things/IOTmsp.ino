#define SENSOR_PIN         P6_0

/*Fill in th ecode below to read an input from one of the pins
and then send that input over serial communication to the PC*/

/* You will need the following functions to do so
pinMode(pin_name, INPUT or OUTPUT); 
    This specifies that a pinbe the input or output. 
analogRead(pin_name) 
    This reads an analog value from the pin specified


Serial.begin(9600); 
    This starts serial communication with the PC
Serial.println(value); 
    This sends data to the PC

delay(time_in_milliseconds);
    This function pauses the program for a certain amount of time
*/

//We have created a variable for you SENSOR_PIN that holds
//the value of the MSP Pin you will be reading from
//The variable curr_value will hold the value read using analogRead()
 
int curr_value; 

void setup() {
  //This is the setup() function. Code in this function is run only once
  //when the MSP first turns on 
}

void loop() {
  //This is the loop() function. Code in this function is run continuously 
  //while the MSP is on. 
}
