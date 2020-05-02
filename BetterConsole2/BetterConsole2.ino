#include "decl.h"
#include "display.h"
#include "logic.h"

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  ts.begin();
  tft.begin();
  
  welcomeScreen();                                    //Start Game at Welcome Screen
  drawstartGrid(ILI9341_WHITE);                       //Draw Starting Grid Fresh
  gameStart();                                        //Start Touch detection and Game logic
}

void loop() {
  // put your main code here, to run repeatedly:
  touch =0;                                           //Very Important for Touch Detection functions to work!!
}
