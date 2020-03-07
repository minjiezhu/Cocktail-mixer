// First, include the mandatory headers.
#include <Wire.h>                          
#include <hd44780.h>                       
#include <hd44780ioClass/hd44780_I2Cexp.h> 
#include <Servo.h>


// Declare the objects.
hd44780_I2Cexp lcd; 
Servo servo;

// Constants.
const int LCD_COLS = 16; // 16 columns.
const int LCD_ROWS = 2; // 2 rows.

int valve1 = 7;
int valve2 = 8;
int valve3 = 9;
int pos = 0;

void setup ()
{
  servo.attach(3);//PIN 3
  servo.write(0);
  
  pinMode(valve1, OUTPUT); 
  pinMode(valve2, OUTPUT); 
  pinMode(valve3, OUTPUT); 
  
  pinMode(10,INPUT);//A
  pinMode(11,INPUT);//B
  pinMode(12,INPUT);//Clear

   // The following code was inspired by the example of I2Cexp module.
  int status;
  status = lcd.begin(LCD_COLS, LCD_ROWS);
  if(status) // non zero status means it was unsuccesful
  {
    status = -status; // convert negative status value to positive number
    // begin() failed so blink error code using the onboard LED if possible
    hd44780::fatalError(status); // does not return
  }
}

void loop()
{
  lcd.setCursor(0,0); 
  lcd.print("ST:Valve Closed ");
  lcd.setCursor(0,1); 
  lcd.print("BTN A B ClearAll");

  
  
  int a = digitalRead(10);// Cocktail A(Left)
  int b = digitalRead(11);// B middle
  int c = digitalRead(12);// Clear right

  //Cocktail A
  if (a==HIGH)          
  {
   lcd.setCursor(0,0); 
   lcd.print("ST:Valve OPEN    ");

   lcd.setCursor(0,1); 
   lcd.print("Progress:0%    A");
   
   digitalWrite(valve1, HIGH);
   delay(1500); 

   lcd.setCursor(0,1); 
   lcd.print("Progress:33%   A");
   
   digitalWrite(valve1, LOW);
   delay(500);
   
   digitalWrite(valve2, HIGH);
   delay(1500); 
   
   digitalWrite(valve2, LOW);

   lcd.setCursor(0,1); 
   lcd.print("Progress:66%   A");
   
   // Stirring.(Extra function)
   for (pos = 0; pos <= 180; pos += 1) { 
    servo.write(pos);           
    delay(5);                
   }  
  for (pos = 180; pos >= 0; pos -= 1) {
    servo.write(pos);             
    delay(5);                       
  }

     for (pos = 0; pos <= 180; pos += 1) { 
    servo.write(pos);           
    delay(5);                
   }  
  for (pos = 180; pos >= 0; pos -= 1) {
    servo.write(pos);             
    delay(5);                       
  }

     for (pos = 0; pos <= 180; pos += 1) { 
    servo.write(pos);           
    delay(5);                
   }  
  for (pos = 180; pos >= 0; pos -= 1) {
    servo.write(pos);             
    delay(5);                       
  }

  
   lcd.setCursor(0,1); 
   lcd.print("Progress:100%  A");
   lcd.setCursor(0,0); 
   lcd.print("Drink A FINISHED");
   delay(3000);
}

// Cocktail B
if (b==HIGH)          
  {
   lcd.setCursor(0,0); 
   lcd.print("ST:Valve OPEN    ");

   lcd.setCursor(0,1); 
   lcd.print("Progress:0%    B");
   
   digitalWrite(valve2, HIGH);
   delay(1500); 

   lcd.setCursor(0,1); 
   lcd.print("Progress:33%   B");
   
   digitalWrite(valve2, LOW);
   delay(500);
   
   digitalWrite(valve3, HIGH);
   delay(1500); 
   
   digitalWrite(valve3, LOW);
   lcd.setCursor(0,1); 
   lcd.print("Progress:66%   B");

  // Stirring.
   for (pos = 0; pos <= 180; pos += 1) { 
    servo.write(pos);           
    delay(5);                
   }  
  for (pos = 180; pos >= 0; pos -= 1) {
    servo.write(pos);             
    delay(5);                       
  }

     for (pos = 0; pos <= 180; pos += 1) { 
    servo.write(pos);           
    delay(5);                
   }  
  for (pos = 180; pos >= 0; pos -= 1) {
    servo.write(pos);             
    delay(5);                       
  }

     for (pos = 0; pos <= 180; pos += 1) { 
    servo.write(pos);           
    delay(5);                
   }  
  for (pos = 180; pos >= 0; pos -= 1) {
    servo.write(pos);             
    delay(5);                       
  }
  
   lcd.setCursor(0,0); 
   lcd.print("Drink B FINISHED");
   delay(3000);
}

// Cocktail C
if (c==HIGH)          
  {
   lcd.setCursor(0,0); 
   lcd.print("ST:Valve OPEN    ");

   lcd.setCursor(0,1); 
   lcd.print("Clearing....    ");
   digitalWrite(valve1, HIGH);
   digitalWrite(valve2, HIGH);
   digitalWrite(valve3, HIGH);
   delay(5000); 

   lcd.setCursor(0,1); 
   lcd.print("Container Clred ");
   digitalWrite(valve1, LOW);
   digitalWrite(valve2, LOW);
   digitalWrite(valve3, LOW);

   delay(3000);
}

}
