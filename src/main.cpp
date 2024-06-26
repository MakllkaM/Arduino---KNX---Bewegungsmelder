/*
 * short Description   : Motiondetection - Arduino to KNX
 * versionNo.          : 1.00
 * date                : 2024-06-24
 * programmer          : mark
 *
 * changes to version   : ?.??          on <yyyy-mm-day> by <name>: - ......
 *
 * function description:
 *
 *
 */

 // define PINS
 #define _i_motionDetect    12

 // create Variables
 int l_i_motion             = false;            // local variable fo Integer
 int l_b_motionSave         = false;

 unsigned long l_ul_previousMillis = 0;  // will store last time LED was updated

 // constants won't change:
 const long c_l_interval = 5000;                    // interval at which to blink (milliseconds)
 

void setup()
 {
    Serial.begin(9600);

    pinMode(_i_motionDetect, INPUT);
 }

 void loop()
 {
    unsigned long l_ul_currentMillis = millis(); 

    l_i_motion = digitalRead(_i_motionDetect);

    if (l_i_motion == HIGH){
        if (l_b_motionSave == false){
            Serial.println("true");
        }
        l_b_motionSave = true;
        l_ul_previousMillis = l_ul_currentMillis;
    }

    if (l_ul_currentMillis - l_ul_previousMillis >= c_l_interval and l_b_motionSave){
        l_b_motionSave = false;
        Serial.println("false");
    }
 
 }