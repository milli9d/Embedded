const char * nameGen(sensors_event_t event,int rnum)            //Generates Psuedo Random File names
{
  if (c0 == 0 && c1 == 0)                                     // Mapped to Amin Chord
  {
    if (event.acceleration.z < 10)                           // Amin Downstroke
  {
    switch(rnum)
    {
      case 0:
      return "Amd1.wav";
      break;
      case 1:
      return "Amd2.wav";
      break;
      case 2:
      return "Amd3.wav";
      break;
      case 3:
      return "Amd4.wav";
      default:
      break;
      }
    
    }
    else if (event.acceleration.z > 10)                        //Amin UpStroke
  {
      switch(rnum)
    {
      case 0:
      return "Amu1.wav";
      break;
      case 1:
      return "Amu2.wav";
      break;
      case 2:
      return "Amu3.wav";
      break;
      case 3:
      return "Amu4.wav";
      default:
      break;
      }
     
  }
 }
  else if (c0 == 0 && c1 == 1)                                     // Mapped to Gmaj Chord
  {
    if (event.acceleration.z < 10)                           // Gmaj Downstroke
  {
    switch(rnum)
    {
      case 0:
      return "Gd1.wav";
      break;
      case 1:
      return "Gd2.wav";
      break;
      case 2:
      return "Gd3.wav";
      break;
      case 3:
      return "Gd4.wav";
      default:
      break;
      }
    
    }
    else if (event.acceleration.z > 10)                        //Gmaj UpStroke
  {
      switch(rnum)
    {
      case 0:
      return "Gu1.wav";
      break;
      case 1:
      return "Gu2.wav";
      break;
      case 2:
      return "Gu3.wav";
      break;
      case 3:
      return "Gu4.wav";
      default:
      break;
      }

}
  }
  else if (c0 == 1 && c1 == 0)                                     // Mapped to Cmaj Chord
  {
    if (event.acceleration.z < 10)                           // Cmaj Downstroke
  {
    switch(rnum)
    {
      case 0:
      return "Cd1.wav";
      break;
      case 1:
      return "Cd2.wav";
      break;
      case 2:
      return "Cd3.wav";
      break;
      case 3:
      return "Cd4.wav";
      default:
      break;
      }
    
    }
    else if (event.acceleration.z > 10)                        //Cmaj UpStroke
  {
      switch(rnum)
    {
      
      case 0:
      return "Cu1.wav";
      break;
      case 1:
      return "Cu2.wav";
      break;
      case 2:
      return "Cu3.wav";
      break;
      case 3:
      return "Cu4.wav";
      default:
      break;
      }
}
}
else if (c0 == 1 && c1 == 1)                                     // Mapped to Fmaj Chord
  {
    if (event.acceleration.z < 10)                           // Fmaj Downstroke
  {
    switch(rnum)
    {
      case 0:
      return "Fd1.wav";
      break;
      case 1:
      return "Fd2.wav";
      break;
      case 2:
      return "Fd3.wav";
      break;
      case 3:
      return "Fd4.wav";
      default:
      break;
      }
    
    }
    else if (event.acceleration.z > 10)                        //Fmaj UpStroke
  {
      switch(rnum)
    {
      case 0:
      return "Fu1.wav";
      break;
      case 1:
      return "Fu2.wav";
      break;
      case 2:
      return "Fu3.wav";
      break;
      case 3:
      return "Fu4.wav";
      default:
      break;
      }
}}
else;
}
