/*Philip Vallone
2-axis joystick connected to an Arduino Micro
to output 4 pins, up, down, left & right
*/

int UD = 0;
int LR = 0;
/* Arduino Micro output pins*/
int DWN = 12;
int UP = 11;
int LEFT = 10;
int RT = 9;
/* Arduino Micro Input Pins */
int IUP=A0;
int ILR=A1;

int MID = 10; // 10 mid point delta arduino, use 4 for attiny
int LRMID = 0;
int UPMID = 0;
void setup(){
  
  pinMode(DWN, OUTPUT);
  pinMode(UP, OUTPUT);  
  pinMode(LEFT, OUTPUT); 
  pinMode(RT, OUTPUT);
   
  digitalWrite(DWN, LOW);
  digitalWrite(UP, LOW);
  digitalWrite(LEFT, LOW);
  digitalWrite(RT, LOW);
  
  //calabrate center
  LRMID = analogRead(ILR);
  UPMID = analogRead(IUP);
}

void loop(){

  UD = analogRead(IUP);
  LR = analogRead(ILR);
  // UP-DOWN
  if(UD < UPMID - MID){
   digitalWrite(DWN, HIGH);
  }else{
   digitalWrite(DWN, LOW);
  }
  
  if(UD > UPMID + MID){
   digitalWrite(UP, HIGH);
  }else{
   digitalWrite(UP, LOW);
  }
  // LEFT-RIGHT
  if(LR < LRMID - MID){
   digitalWrite(LEFT, HIGH);
  }else{
   digitalWrite(LEFT, LOW);
  }
  
  if(LR > LRMID + MID){
   digitalWrite(RT, HIGH);
  }else{
   digitalWrite(RT, LOW);
  }
 
  delay(400);


}
