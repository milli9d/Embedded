#include <Audio.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
//include ms10997/Milind Singh

// Use these with the Teensy Audio Shield
#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14

// GUItool: begin automatically generated code
AudioPlaySdWav           playSdWav2;                    //xy=284.2000160217285,419.20001792907715
AudioPlaySdWav           playSdWav1;                    //xy=285.2000198364258,354.20001792907715
AudioEffectFade          fade1;                         //xy=470.1999969482422,368.1999969482422
AudioEffectFade          fade2;                         //xy=486.1999969482422,420.1999969482422
AudioMixer4              mixer1;                        //xy=662,406
AudioOutputI2S           i2s1;                          //xy=891,406
AudioConnection          patchCord1(playSdWav2, 0, fade2, 0);
AudioConnection          patchCord2(playSdWav1, 0, fade1, 0);
AudioConnection          patchCord3(fade1, 0, mixer1, 0);
AudioConnection          patchCord4(fade2, 0, mixer1, 1);
AudioConnection          patchCord5(mixer1, 0, i2s1, 0);
AudioConnection          patchCord6(mixer1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;                    //xy=876,513
// GUItool: end automatically generated code

char fname[32];                                         //Global Variable to store file name 
int c0 ,c1;                                             //Test
uint32_t name0 = 0x6D73;                                //
void configAudio()                                      //Configure Sgtlmodule
{
  AudioMemory(32);                                      //Allocate Dynamic Memory for Audio Processing
  sgtl5000_1.enable();                                  //Enable Sgtl control module
  sgtl5000_1.volume(0.5);                               //Set Volume 
  mixer1.gain(0,0.8);                                   //Set Mixer Gains , Total at any instant should not exceed 1  
  mixer1.gain(1,0.8);
  mixer1.gain(2,0.8);
  mixer1.gain(3,0.8);
}

void init_peripherals(void){
  Serial.println("ADXL343 Air Guitar Diagnostic :"); Serial.println("");
  if(!accData.begin())                                  //Initialize ADXL343 Object
  { 
    Serial.println("Error 01 -- ADXL343 not detected -- Check wiring");
    while(1);
    }
    else;
  SPI.setMOSI(SDCARD_MOSI_PIN);                         //Configure SD Card Interface
  SPI.setSCK(SDCARD_SCK_PIN);                           //
  if (!(SD.begin(SDCARD_CS_PIN)))                       //Initialize SD card Interface
  {
   Serial.println("Error 02 -- SD card Not Detected");
   while(1);
  }
  else;
}
  
