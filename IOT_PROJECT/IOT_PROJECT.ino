

/*
*#################################################
*The TTTCMR
*By Daniel Kovzan, Mark Dee, Clintano Perrins and Gatis Berzins
*Modified By Daniel Kovzan 16:51 11/03/2021
*
*
*
*
*
*
*#################################################
*/
#include <Wire.h>
#include <Bridge.h>
#include <BlynkSimpleYun.h>
//#include <RTClib.h>
//RTC_DS1302 rtc;

// You should get Auth Token in the Blynk App.
char auth[] = "8mgU1evnl2zeJBSTzcDIWm60yNy23ihB";


int hoursUp, hoursDown, minsUp, minsDown;

static unsigned long lastTick = 0;
int curMin = 0,curHour = 0, userChoice = 0;

static int hour = 0;
static int minute =  0;
static int second = 0;

//Blynk Menu Setup, hope it works
//I think that you need to restart the program eahc time you wish to change timezone since i donty think the program ever returns to this piece of code

/*
BLYNK_WRITE(V1) {
  hour = param.asInt();
  
}*/




//############################################################################
void setup() {
  // put your setup code here, to run once:
  for (int i=1; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
  Wire.begin();
  Blynk.begin(auth);
 // rtc.begin();
 
//  DateTime now = rtc.now();
//  second = now.second();
//  minute = now.minute();
//  hour = now.hour();



}


BLYNK_WRITE(V1)
{
  hoursUp = param.asInt();
}

BLYNK_WRITE(V2)
{
  hoursDown = param.asInt();
}

BLYNK_WRITE(V3)
{
  minsUp = param.asInt();
}

BLYNK_WRITE(V4)
{
  minsDown = param.asInt();
}



//##############################################################################
void loop()
{

Blynk.run();

//Seconds
if(millis() -  lastTick >1000)
{
  lastTick = millis();
  second++;
}
//Minutes
if(second >= 60)
{
  minute++;
  second = 0;
}
//Hours
if(minute >= 60)
  {
    hour++;
    minute = 0;
  }

//When the hour goes becomes 24, it goes back to 0 since it cant get to 25
  if (hour >=24) {
hour=0;
minute = 0; 
}

curMin = minute % 10;//gets the right side of minutes
curHour = hour % 10;//gets the right side of the hours

//############################################################################
//Minutes Output

//Pin 1 Binary 1 min
if(curMin == 1 || curMin == 3 || curMin == 5 || curMin == 7 || curMin == 9)
  digitalWrite(1, HIGH);
else
  digitalWrite(1, LOW);
  
//pIN 2 bINARY 2 min
if(curMin == 2 || curMin == 3 || curMin == 6 || curMin == 7 )
  digitalWrite(2, HIGH);
else
  digitalWrite(2, LOW);
  
//pin 3 binary 4 min
if(curMin == 4 || curMin == 5 || curMin == 6 || curMin == 7)
  digitalWrite(3, HIGH);
else
  digitalWrite(3, LOW);
  
  //pin 4 binary 8 min
if(curMin == 8 || curMin == 9)
  digitalWrite(4, HIGH);
else
  digitalWrite(4, LOW);

//--------------------------------------------------------------------------------------
  
//Tens of Minutes

//Pin 5 10 mins
if((minute >= 10 && minute < 20) || (minute >= 30 && minute < 40) || (minute >= 50 && minute < 60)) {
   digitalWrite(5, HIGH);
} else {
   digitalWrite(5,LOW);
}

//Pin 6 20 mins
if(minute >= 20 && minute < 40) {
   digitalWrite(6, HIGH);
} else {
   digitalWrite(6,LOW);
}

//Pin 7 40 mins
if(minute >= 40 && minute < 60) {
   digitalWrite(7, HIGH);
} else {
   digitalWrite(7,LOW);
}

//#########################################################################################
//#########################################################################################
//#########################################################################################
//Hours Output

//Pin 8 Binary 1 hour
if(curHour == 1 || curHour == 3 || curHour == 5 || curHour == 7 || curHour == 9)
  digitalWrite(8, HIGH);
else
  digitalWrite(8, LOW);
  
//pIN 9 bINARY 2 hour
if(curHour == 2 || curHour == 3 || curHour == 6 || curHour == 7 )
  digitalWrite(9, HIGH);
else
  digitalWrite(9, LOW);
  
//pin 10 binary 4 hour
if(curHour == 4 || curHour == 5 || curHour == 6 || curHour == 7)
  digitalWrite(10, HIGH);
else
  digitalWrite(10, LOW);
  
  //pin 11 binary 8 hour
if(curHour == 8 || curHour == 9)
  digitalWrite(11, HIGH);
else
  digitalWrite(11, LOW);

//--------------------------------------------------------------------------------------
  
//Tens of Hours

//Pin 12 10 Hours
if(hour >= 10 && hour < 20) {
   digitalWrite(12, HIGH);
} else {
   digitalWrite(12,LOW);
}

//Pin 13 20 - 24 hours
if(hour >= 20 && hour < 24) {
   digitalWrite(13, HIGH);
} else {
   digitalWrite(13,LOW);
}
//#########################################################################################

  if (hoursUp == 1)
  {
    hour++;
  }

  if (hoursDown == 1)
  {
    hour--;
  }
  
  if (minsUp == 1)
  {
  minute++;
  }

  if (minsDown == 1)
  {
    minute--;
  }



}