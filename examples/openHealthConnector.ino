//
// File: example.ino
// Name: Mihály Tóth
// Date: 2019.10.25.
// Ver.: v0.4
// Desc: Example code for the OpenHealthConnector for Arduino development platform.
//

#include "../src/openHealthConnector.h"

openHealth openhealth = openHealth();

void setup()
{
    Serial.begin(9600);
    openhealth.openHealth_init();
}

void loop()
{
    Serial.println("Ez egy teszt.");
    delay(1000);
    
}
