void PlayFile(char name[] ){                                                                      //Audio File Control Module , Handles 2 files playing simultaenously , Can be expanded to handle more
  
  if (playSdWav1.isPlaying() == false && playSdWav2.isPlaying()== false)                          //When both are not playing
    {
      Serial.println("Now Playing on Sd1");                                                       // 
      playSdWav1.play(name);                                                                      //Start Playback on Sd1
      delay(10);                                                                                  //Buffer to read meta data 
    }
  else if (playSdWav1.isPlaying() == false && playSdWav2.isPlaying()== true)                      // When Sd1 = off Sd1= Playing
    {
      int x = (playSdWav2.lengthMillis() - playSdWav2.positionMillis())/2 ;                       // Get time left to end of clip on sd2 and half it = x
      fade2.fadeOut(x);                                                                           // fade out in time x
      Serial.println("Now Playing On Sd1");                                                       //
      fade1.fadeIn(x/2);
      playSdWav1.play(name);                                                                      //Start playback on Sd1
      delay(x/2);                                                                                   //wait for sd2 playback to end ;till x
      playSdWav2.stop();                                                                          //Stop sd2
    }
  else if (playSdWav1.isPlaying() == true && playSdWav2.isPlaying()== false)                      //When Sd1=On Sd2=Off , start playback on sd2 , fade out sd1
    {
      int x = (playSdWav1.lengthMillis() - playSdWav1.positionMillis())/2 ;                       //Similiar as Above
      fade1.fadeOut(x);                                                                           //
      Serial.println("Now Playing On Sd2");                                                       //
      fade2.fadeIn(x/2);
      playSdWav2.play(name);                                                                      //
      delay(x/2);                                                                                   //
      playSdWav1.stop();                                                                          //
   }
  else if (playSdWav1.isPlaying() == true && playSdWav2.isPlaying()== true)                       //When both are playing
    {
     int temp = playSdWav2.positionMillis() - playSdWav1.positionMillis();                        //Check which started earlier
     if (temp > 0)                                                                                //SdWav2 started earlier ,fade it out
        {
          int x = playSdWav2.lengthMillis() - playSdWav2.positionMillis() ;
          fade2.fadeOut(x);
          Serial.println("Now Playing On Sd1");
          fade1.fadeIn(x/2);
          playSdWav1.play(name);
          delay(x/2);
          playSdWav2.stop();
        }
     else if(temp <= 0)                                                                           //SdWav1 started earlier ,fade it out
        {
          int x = playSdWav1.lengthMillis() - playSdWav1.positionMillis() ;
          fade1.fadeOut(x);
          Serial.println("Now Playing On Sd2");
          fade2.fadeIn(x/2);
          playSdWav2.play(name);
          delay(x/2);
          playSdWav1.stop();
        }
        else;
    }
    else;
 }

 uint32_t name11 = 0x6D73; 
