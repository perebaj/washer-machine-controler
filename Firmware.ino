
// Include Libraries
#include "Arduino.h"
#include "Relay.h"
#include "SolenoidValve.h"


// Pin Definitions
#define RELAYMODULE_PIN_SIGNAL	3
#define SOLENOIDVALVE_PIN_COIL1	2



// Global variables and defines

// object initialization
Relay relayModule(RELAYMODULE_PIN_SIGNAL);
SolenoidValve solenoidValve(SOLENOIDVALVE_PIN_COIL1);


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1') {
    // Relay Module - Test Code
    // The relay will turn on and off for 500ms (0.5 sec)
    relayModule.on();       // 1. turns on
    delay(500);             // 2. waits 500 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    relayModule.off();      // 3. turns off.
    delay(500);             // 4. waits 500 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    }
    else if(menuOption == '2') {
    // 12V Solenoid Valve - 3/4'' - Test Code
    // The solenoid valve will turn on and off for 500ms (0.5 sec)
    solenoidValve.on(); // 1. turns on
    delay(500);       // 2. waits 500 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    solenoidValve.off();// 3. turns off
    delay(500);       // 4. waits 500 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.

    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) Relay Module"));
    Serial.println(F("(2) 12V Solenoid Valve - 3/4''"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing Relay Module"));
    		else if(c == '2') 
    			Serial.println(F("Now Testing 12V Solenoid Valve - 3/4''"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}
