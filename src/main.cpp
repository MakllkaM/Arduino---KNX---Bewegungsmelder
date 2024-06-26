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
#define _i_motionDetect         12
#define _b_shortSelection      11      
#define _b_normalSelection     10
#define _b_longSelection        9

// create Variables
int _i_motion             = false;            // local variable fo Integer
int _b_motionSave         = false;



unsigned long _ul_previousMillis = 0;  // will store last time LED was updated

// constants won't change:
const long c_l_shortDelay       = 5000;                    
const long c_l_normalDelay      = 30000;
const long c_l_standardDelay    = 15000;  
const long c_l_longDelay        = 60000;

long delayTime(){
    if (digitalRead(_b_shortSelection) == 1){
        return c_l_shortDelay;
    }else if (digitalRead(_b_snormalSelection) == 1){
        return c_l_normalDelay;
    }else if (digitalRead(_b_longSelection, HIGH) == 1){
        return c_l_longDelay;
    }else{
        return c_l_standardDelay;
    }
}

void setup()
 {
    Serial.begin(9600);

    pinMode(_i_motionDetect, INPUT);
    pinMode(_b_shortSelection, INPUT);
    pinMode(_b_normalSelection, INPUT);
    pinMode(_b_longSelection, INPUT);
 }

 void loop()
 {
    unsigned long _ul_currentMillis = millis(); 

    _i_motion = digitalRead(_i_motionDetect);

    if (_i_motion == HIGH){
        if (_b_motionSave == false){
            Serial.println("true");
        }
        _b_motionSave = true;
        _ul_previousMillis = _ul_currentMillis;
    }

    if (_ul_currentMillis - _ul_previousMillis >= delayTime() and _b_motionSave){
        _b_motionSave = false;
        Serial.println("false");
    }
 
 }