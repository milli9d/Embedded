#include "ADXL.h"
#include "AudioShield.h"
#include "AudioQueue.h"
#include "FileMap.h"
//include ms10997/Milind Singh

void setup() {
   // put your setup code here, to run once:
 /* Initialise the sensor */
Serial.begin(9600);                                                   //Open Serial Port
 //while(!Serial);                                                      //Stop if communication breaks
init_peripherals();
config_interrupts();                                                  //Configure Interrupts, Refer ADXL.h
configAudio();                                                        //Configure Audio Shield,Refer AudioShield.h
Serial.println("Air Guitar Initialized. Ready for Input.");
}

void loop() {
  // put your main code here, to run repeatedly:
sensors_event_t event;                                                //Make new object of sensor event type
accData.getEvent(&event);                                             //Write last recorded event to object event
randomSeed(analogRead(A0));                                           //Generate Random Seed for Random playback of variations
int rnum;                                                             //Store Random Number
c0= !digitalRead(4);                                                  //Capacitive Touch Pads
c1 =!digitalRead(6);                                                  //Capacitive Touch Pads

delay(100);                                                          
Serial.print(nameGen(event,rnum));Serial.println(""); 
while(g_ints_fired) {                                                 //Check Interrupt Fired Flag
      Serial.println("INT detected!");
      Serial.print("\tACT Count:    "); Serial.println(g_int_stats.activity, DEC);
   uint8_t src = accData.readRegister(0x30);                          //Read Source Register to reset interrupts
   uint8_t source = accData.readRegister(0x2B);                       //Read Act Status Register
   int rnum = random(0,4); 
   PlayFile(nameGen(event,rnum));                                     //Play audio file <fname>
   g_ints_fired--;                                                    //Reset Interrupt Fired Flag
     
}
}
