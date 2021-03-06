/*
  Calculator System.
  Displaying the 4 arithmetic operation i.e. +, -, *, / using the 4*4 keypad and LCD screen.
  Outputs Shown On - LCD Screen.
  Libraries Used - LiquidCrystal.h, Keypad.h
  This code has the Basic Version.
  We have connected the 4*4 Keypad and LCD Screen to the Uniko Ekam Board.
  The output is calculated by the various functions and displayed on the LCD Screen.
  The output shown has no problems and is accurate with the calculations.
  Author - NISHIT R MISTRY
  Date - 28-08-2019
  References - https://circuitdigest.com/microcontroller-projects/arduino-calculator-using-4x4-keypad
*/

#include <LiquidCrystal.h> //Header file for LCD from https://www.arduino.cc/en/Reference/LiquidCrystal
#include <Keypad.h> //Header file for Keypad from https://github.com/Chris--A/Keypad

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

// Define the Keymap
char keys[ROWS][COLS] = {

  {'7','8','9','D'},

  {'4','5','6','C'},

  {'1','2','3','B'},

  {'*','0','#','A'}

};

byte rowPins[ROWS] = { 4, 5, 6, 7 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these board pins.

byte colPins[COLS] = { 8, 9, 10, 11 }; // Connect keypad COL0, COL1 and COL2 to these board pins.

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //  Create the Keypad

//using the Analog Pins for connecting LCD Screen!
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);  // (rs, e, d4, d5, d6, d7)

//initializing basic variables for calculation and storing results.
long Num1,Num2,Number;
char key,action;
boolean result = false;
 
void setup() 
{
  lcd.begin(16, 2); //We are using a 16*2 LCD display
  lcd.print("Calculator"); //Display a intro message
  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
  lcd.print("-NishitMistry"); //Display a intro message 
  delay(2000); //Wait for display to show info
  lcd.clear(); //Then clean the display
}

void loop() 
{
  
key = kpd.getKey(); //storing pressed key value in a char

//loop for detecting the key pressed in the keypad.
if (key!=NO_KEY)
DetectButtons();

//if key pressed is found, then calculate the respective operation
if (result==true)
CalculateResult();

//display the result on the LCD Screen.
DisplayResult();   
}

void DetectButtons()
{ 
    lcd.clear(); //Clear the LCD Screen
    if (key=='*') //If cancel Button is pressed
    {Serial.println ("Button Cancel"); Number=Num1=Num2=0; result=false;}
    
     if (key == '1') //If Button 1 is pressed
    {Serial.println ("Button 1"); 
    if (Number==0)
    Number=1;
    else
    Number = (Number*10) + 1; //Pressed twice
    }
    
     if (key == '4') //If Button 4 is pressed
    {Serial.println ("Button 4"); 
    if (Number==0)
    Number=4;
    else
    Number = (Number*10) + 4; //Pressed twice
    }
    
     if (key == '7') //If Button 7 is pressed
    {Serial.println ("Button 7");
    if (Number==0)
    Number=7;
    else
    Number = (Number*10) + 7; //Pressed twice
    } 
  

    if (key == '0') //Button 0 is Pressed
    {Serial.println ("Button 0"); 
    if (Number==0)
    Number=0;
    else
    Number = (Number*10) + 0; //Pressed twice
    }
    
     if (key == '2') //Button 2 is Pressed
    {Serial.println ("Button 2"); 
     if (Number==0)
    Number=2;
    else
    Number = (Number*10) + 2; //Pressed twice
    }
    
     if (key == '5') //Button 5 is Pressed
    {Serial.println ("Button 5"); 
     if (Number==0)
    Number=5;
    else
    Number = (Number*10) + 5; //Pressed twice
    }
    
     if (key == '8') //Button 8 is Pressed
    {Serial.println ("Button 8"); 
     if (Number==0)
    Number=8;
    else
    Number = (Number*10) + 8; //Pressed twice
    }   
  

    if (key == '#') //Button # is Pressed
    {Serial.println ("Button Equal"); 
    Num2=Number;
    result = true;
    }
    
     if (key == '3') //Button 3 is Pressed
    {Serial.println ("Button 3"); 
     if (Number==0)
    Number=3;
    else
    Number = (Number*10) + 3; //Pressed twice
    }
    
     if (key == '6') //Button 6 is Pressed
    {Serial.println ("Button 6"); 
    if (Number==0)
    Number=6;
    else
    Number = (Number*10) + 6; //Pressed twice
    }
    
     if (key == '9') //Button 9 is Pressed
    {Serial.println ("Button 9");
    if (Number==0)
    Number=9;
    else
    Number = (Number*10) + 9; //Pressed twice
    }  

      if (key == 'A' || key == 'B' || key == 'C' || key == 'D') //Detecting Buttons on Column 4
  {
    Num1 = Number;    
    Number =0;
    if (key == 'A')
    {Serial.println ("Addition"); action = '+';}
     if (key == 'B')
    {Serial.println ("Subtraction"); action = '-'; }
     if (key == 'C')
    {Serial.println ("Multiplication"); action = '*';}
     if (key == 'D')
    {Serial.println ("Division"); action = '/';}  

    delay(100);
  }
  
}

void CalculateResult()
{
  if (action=='+') //loop for addition
    Number = Num1+Num2;

  if (action=='-') //loop for subtraction
    Number = Num1-Num2;
 
  if (action=='*') //loop for multiplication
    Number = Num1*Num2;

  if (action=='/') //loop for division
    Number = Num1/Num2; 
}

void DisplayResult()
{
  lcd.setCursor(0, 0);   // set the cursor to column 0, line 1
  lcd.print(Num1); lcd.print(action); lcd.print(Num2); //print the answer
  
  if (result==true)
  {lcd.print(" ="); lcd.print(Number);} //Display the result
  
  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
  lcd.print(Number); //Display the result
}
