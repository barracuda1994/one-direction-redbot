/**
 * Roger Xue
 * ENGR 0716
 * 28 February 2015
 */
 #include <RedBot.h>

RedBotMotors motors;
RedBotAccel accelerometer;

const int buzzerPin = 9;
const int buttonPin = 12;
const int beatsPerMinute = 125;

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);          // configures the button as an INPUT
  // INPUT_PULLUP defaults it to HIGH.
  pinMode(buzzerPin, OUTPUT);                // configures the buzzerPin as an OUTPUT
}

void loop()
{ 

  accelerometer.read();
  //if ( digitalRead(buttonPin) == LOW )       // if the button is pushed (LOW)
  if (abs(accelerometer.x) > 15000)
  {             
    whatMakesYouBeautiful();
    rest(0);
    oneThing();
  }
  else
  { 
  }
}

//void playNote(int frequency, double duration)  {
// tone(buzzerPin, frequency); 
// int toneLength = (int) ((duration / beatsPerMinute) * 60 * 1000);
// delay(toneLength);  
// noTone(buzzerPin);
// rest(0.05);
// }

void rest(double duration)  {
  int restLength = (int) ((duration / beatsPerMinute) * 60 * 1000);
  delay(restLength);
}

void playNote(int frequency, double duration)  {  
  int toneLength = (int) ((duration / beatsPerMinute) * 60 * 1000);
  tone(buzzerPin, frequency, toneLength); 
  
  int rand = random(1,12);

  if (duration > 1.5)
    rand = random(0,7);    

  if (rand <= 3) 
    turnLeft(duration);
  else if (rand >= 4 && rand <= 6)
    turnRight(duration);
  else if (rand == 7 || rand == 8)
    goForward(duration);
  else if (rand == 9 || rand == 10) 
    goBackwards(duration);
  else
    doNothing(duration);

  rest(0.05);

}

void playNote(int frequency, double duration, int danceMove)  {        // manual dance move override
  int toneLength = (int) ((duration / beatsPerMinute) * 60 * 1000);
  tone(buzzerPin, frequency, toneLength); 

  if (danceMove == 1) 
    goForward(duration);
  else if (danceMove == 2)
    goBackwards(duration);
  else if (danceMove == 3)
    turnLeft(duration);
  else if (danceMove == 4) 
    turnRight(duration);
  else
    doNothing(duration);

  rest(0.05);

}

void goForward(double duration)  {
  motors.leftMotor(-144);
  motors.rightMotor(140);
  int toneLength = (int) ((duration / beatsPerMinute) * 60 * 1000);
  delay(toneLength);  
  motors.stop(); 
}

void goBackwards(double duration)  {
  motors.leftMotor(144);
  motors.rightMotor(-140);
  int toneLength = (int) ((duration / beatsPerMinute) * 60 * 1000);
  delay(toneLength);  
  motors.stop(); 
}

void turnRight(double duration)  {
  motors.rightMotor(-200); 
  motors.leftMotor(-200); 
  int toneLength = (int) ((duration / beatsPerMinute) * 60 * 1000);
  delay(toneLength);     
  motors.brake();          
}

void turnLeft(double duration)  {
  motors.rightMotor(200); 
  motors.leftMotor(200); 
  int toneLength = (int) ((duration / beatsPerMinute) * 60 * 1000);
  delay(toneLength);     
  motors.brake();       
}

void doNothing(double duration)  {
  int toneLength = (int) ((duration / beatsPerMinute) * 60 * 1000);
  delay(toneLength);
}

void whatMakesYouBeautiful()  {

  playNote(415,0.5); //INTRO 1
  rest(1);
  playNote(415,0.5);
  playNote(554,0.5);
  rest(1);
  playNote(554,0.5);

  playNote(622,0.5);
  rest(1);
  playNote(622,0.5);
  rest(0.5);
  playNote(622,0.5);
  rest(0.5);
  playNote(622,0.5);

  playNote(415,0.5);
  rest(1);
  playNote(415,0.5);
  playNote(554,0.5);
  rest(1);
  playNote(554,0.5);

  playNote(622,0.5);  
  rest(0.5);
  playNote(622,0.5);  
  rest(0.5);
  playNote(622,0.5);  

  playNote(1318,0.5); //5
  playNote(1318,0.5);
  playNote(1318,0.5);

  playNote(1318,1); //5
  rest(1.5);
  playNote(1318,0.5);
  playNote(1318,0.5);
  playNote(1318,0.5);

  playNote(988,0.5);
  rest(2);
  playNote(1318,0.5);
  playNote(1318,0.5);
  playNote(1318,0.5);

  playNote(1318,1);
  playNote(1318,0.5);
  playNote(1318,0.5);
  playNote(1318,1);
  playNote(1318,0.5);
  playNote(1318,0.5);

  playNote(1480,0.5);
  playNote(1661,0.5);
  playNote(1480,0.5);
  rest(1);
  playNote(1318,0.5);
  playNote(1318,0.5);
  playNote(1318,0.5);

  playNote(1318,0.5);
  rest(2);
  playNote(1318,0.5);
  playNote(1318,0.5);
  playNote(1318,0.5);

  playNote(988,0.5); //10
  rest(2.0);
  playNote(1318,0.5);
  playNote(1318,0.5);
  playNote(1318,0.5);

  playNote(1318,1);
  playNote(1318,0.5);
  playNote(1318,0.5);
  playNote(1318,1);
  playNote(1318,0.5);
  playNote(1318,0.5);

  playNote(1480,0.5);
  playNote(1661,0.5);
  playNote(1480,1);
  rest(2);

  playNote(1318,1);
  playNote(1661,0.5);
  playNote(1976,0.5);
  playNote(2215,1);
  playNote(2215,0.5);
  playNote(1976,0.5);

  playNote(1661,1);
  playNote(1661,0.5);
  playNote(1661,1);
  playNote(1480,1.5);

  playNote(1318,1);  //15
  playNote(1661,0.5);
  playNote(1976,0.5);
  playNote(2215,1);
  playNote(2215,0.5);
  playNote(1976,0.5);

  playNote(1661,2);    
  rest(0.5);
  playNote(3322,0.5);
  playNote(2960,0.5);
  playNote(2637,0.5);

  playNote(2637,1);
  playNote(2637,0.5);
  playNote(2637,0.5);
  playNote(2637,1);
  playNote(2637,0.5);
  playNote(2637,0.5);

  playNote(2960,1);
  playNote(3322,0.5);
  playNote(2960,1);
  playNote(3322,0.5);
  playNote(2960,0.5);
  playNote(2637,0.5);

  playNote(2637,1);
  playNote(2637,0.5);
  playNote(2637,0.5);
  playNote(2637,1);
  playNote(2637,0.5);
  playNote(2637,0.5);

  playNote(2960,1); //20
  playNote(3322,0.5);
  playNote(2960,1);
  playNote(3322,0.5);
  playNote(2960,0.5);
  playNote(2637,0.5);

  playNote(2637,1);
  playNote(2637,0.5);
  playNote(2637,0.5);
  playNote(2637,1);
  playNote(2637,0.5);
  playNote(2637,0.5);

  playNote(3322,1);
  playNote(2960,0.5);
  playNote(2960,1);
  playNote(3322,0.5);
  playNote(2960,0.5);
  playNote(2637,0.5);

  playNote(2637,1.5);
  playNote(2960,0.5);
  playNote(3322,2);

  playNote(3322,0.5);
  playNote(3322,0.5);
  playNote(3322,0.5);
  playNote(3322,0.5);
  playNote(3322,0.75);
  playNote(2960,0.75);
  playNote(2637,0.5);

  playNote(2637,1);  //25
  playNote(2637,0.5);
  playNote(2637,0.5);
  playNote(2637,1);
  playNote(2637,0.5);
  playNote(2637,0.5);

  playNote(2960,1);
  playNote(3322,0.5);
  playNote(2960,1);
  playNote(3322,0.5);
  playNote(2960,0.5);
  playNote(2637,0.5);

  playNote(2637,1);
  playNote(2637,0.5);
  playNote(2637,0.5);
  playNote(2637,1);
  playNote(2637,0.5);
  playNote(2637,0.5);

  playNote(2960,1);
  playNote(3322,0.5);
  playNote(2960,1);
  playNote(3322,0.5);
  playNote(2960,0.5);
  playNote(2637,0.5);

  playNote(2637,1);
  playNote(2637,0.5);
  playNote(2637,0.5);
  playNote(2637,1);
  playNote(2637,0.5);
  playNote(2637,0.5);

  playNote(3322,1);  //30
  playNote(2960,0.5);
  playNote(2960,1);
  playNote(3322,0.5);
  playNote(2960,0.5);
  playNote(2637,0.5);

  playNote(2637,1.5);
  playNote(2960,0.5);
  playNote(3322,2);

  playNote(3322,0.5);
  playNote(3322,0.5);
  playNote(3322,0.5);
  playNote(3322,0.5);
  playNote(3322,0.75);
  playNote(2960,0.75);
  playNote(2637,0.5);

  playNote(2637,1.5);
  playNote(2960,0.5);
  playNote(3322,2);

  playNote(3322,0.5);  //34
  playNote(3322,0.5);
  playNote(3322,0.5);
  playNote(3322,0.5);
  playNote(3322,0.75);
  playNote(2960,0.75);
  playNote(2637,0.5);
}

void oneThing()  {

  playNote(370,1,0);  //1
  playNote(370,1,0);
  playNote(277,0.5,0);
  playNote(277,0.5,0);
  playNote(277,0.5,0);
  rest(0.5);

  playNote(370,1);
  rest(0.5);
  playNote(370,1);
  rest(1.5);

  playNote(1175,1);
  playNote(1175,1);
  playNote(1318,0.5);
  playNote(1318,0.5);
  playNote(1480,1);

  playNote(1480,4);

  playNote(1480,1); //5
  playNote(1480,0.5);
  playNote(1480,0.5);
  playNote(1760,0.5);
  playNote(1760,0.5);
  playNote(1976,1);

  playNote(1976,4);

  playNote(1976,1);
  playNote(1976,1);
  playNote(1760,0.5);
  playNote(1760,0.5);
  playNote(1976,1);

  playNote(1480,3);
  playNote(1175,1);

  playNote(1480,1.5);
  playNote(1480,1.5);
  playNote(1175,1);

  playNote(1318,1.5);  //10
  playNote(1175,1);
  rest(1.5);

  playNote(1175,1);
  playNote(1175,1);
  playNote(1318,0.5);
  playNote(1318,0.5);
  playNote(1480,1);

  playNote(1480,4);

  playNote(1480,1);
  playNote(1480,1);
  playNote(1760,1);
  playNote(1760,1);

  playNote(1976,3);
  rest(1.5);

  playNote(1976,1);      //15
  playNote(1976,1);
  playNote(1760,0.5);
  playNote(1760,0.5);
  playNote(1976,1);

  playNote(1480,1.5);
  playNote(1318,1.5);
  playNote(1175,1);

  playNote(1480,1.5);
  playNote(1480,1.5);
  playNote(1175,1);

  playNote(1318,1.5);   
  playNote(1175,1.5);
  playNote(2349,0.5);
  playNote(2349,0.5);

  playNote(1760,0.5);
  playNote(1760,0.5);
  playNote(1568,1);
  playNote(1480,2);

  rest(1);            //20
  playNote(1760,0.5);
  playNote(1760,0.5);
  playNote(2349,0.75);
  playNote(2349,0.5);
  playNote(1760,0.5);
  playNote(1760,0.5);

  playNote(1568,0.75);
  playNote(1480,1);
  playNote(1318,2);

  playNote(1760,0.5);
  playNote(1760,0.5);
  playNote(2349,0.75);
  playNote(2349,0.5);
  playNote(1760,0.5);
  playNote(1760,0.5);
  playNote(1568,0.75);

  playNote(1480,2);
  rest(1);
  playNote(1175,1);

  playNote(1480,1.5);
  playNote(1480,1.5);
  playNote(1175,1);

  playNote(1318,1.5);    //25
  playNote(1175,1.5);
  playNote(2960,1);

  playNote(2637,0.5);
  playNote(2960,1);
  playNote(2637,0.5);
  playNote(2960,1);
  playNote(2960,1);

  playNote(2637,0.5);
  playNote(2960,0.5);
  playNote(3520,0.5);
  playNote(2960,1);
  rest(0.5);
  playNote(2359,1);

  playNote(2637,0.5);
  playNote(2960,1);
  playNote(2637,0.5);
  playNote(2960,1);
  playNote(2960,1);

  playNote(2637,1.5);
  playNote(2960,1);
  rest(1);
  playNote(2637,0.5);

  playNote(2960,1);  //30
  playNote(2637,0.5);
  playNote(2960,1);
  playNote(2960,1);
  playNote(2637,0.5);

  playNote(2960,0.5);
  playNote(3520,0.5);
  playNote(2960,1.5);
  rest(0.5);
  playNote(2349,0.75);
  rest(0.25);

  playNote(2960,1.5);
  playNote(2960,1);
  playNote(2349,1.5);

  playNote(2637,1.5);
  playNote(2349,1);
  rest(0.5);
  playNote(1976,0.5);
  rest(0.5);

  playNote(2960,1.5);
  playNote(2960,1.5);
  playNote(2349,0.5);
  rest(0.5);

  rest(0.5);      //35
  playNote(2637,1.5);
  playNote(2349,1.5);
  rest(0.5);
}







