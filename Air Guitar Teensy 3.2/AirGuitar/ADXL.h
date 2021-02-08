#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL343.h>

//include ms10997/Milind Singh

#define pInt1 (01)                                                                        //Macros
#define pInt2 (02)                                                                        //Macros
Adafruit_ADXL343 accData = Adafruit_ADXL343(12345);                                       //Declare a new object of ADXL343 library and assign unique ID=12345

struct adxl_int_stats {                                                                   //Define Struct to store Interrupt Counts
    uint32_t single_tap;
    uint32_t double_tap;
    uint32_t activity;
    uint32_t inactivity;
    uint32_t total;
};

struct adxl_int_stats g_int_stats = { 0 } ;                                               // Create new object of type interrupt stats
uint32_t g_ints_fired = 0 ;                                                               // Total number of unused interrupts fired??

int_config g_int_enabled = { 0 };                                                         //Masks for Interrupts 
int_config g_int_map = { 0 };                               

void int1_isr(void)                                                                       // Single tap ISR
{
  g_ints_fired++;
  g_int_stats.activity++;
  g_int_stats.total++;
  delay(80);
 }

void int2_isr(void){


}





void config_interrupts(void)                                                              //Function to Configure GPIO and Interrupts Controller
{
accData.setRange(ADXL343_RANGE_16_G);                                                     //Set range for ADXL343 16g

pinMode(pInt1,INPUT);                                                                     //Configure Teensy GPIO 
pinMode(pInt2,INPUT);                                                                     //
pinMode(4,INPUT_PULLUP);                                                                  //C0 Conductive Tape Switch
pinMode(6,INPUT_PULLUP);                                                                  //C1 Conductive Tape Switch

attachInterrupt(digitalPinToInterrupt(pInt1),int1_isr,RISING);                            //Attach Interrupts Teensy
attachInterrupt(digitalPinToInterrupt(pInt2),int2_isr,RISING);

g_int_enabled.bits.activity = true;                                                       //Enable Activity Interrupt
accData.enableInterrupts(g_int_enabled);                                                  //Write to ADXL 

g_int_map.bits.activity = ADXL343_INT1;                                                   //Map single tap to INT1
g_int_map.bits.double_tap = ADXL343_INT2;                                                 //Map double tap to INT2
accData.mapInterrupts(g_int_map);                                                         //Write to ADXL

accData.writeRegister(ADXL343_REG_THRESH_ACT, 0x50);                                      //Activity threshold mg /LSB
accData.writeRegister(ADXL343_REG_ACT_INACT_CTL, 0b01010000);                             //Activity Control Register
  
}



uint32_t name1 = 0x6D73; 
