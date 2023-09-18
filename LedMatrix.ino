#define R1 22
#define R2 23
#define R3 24
#define R4 25
#define R5 26
#define R6 27
#define R7 28
#define R8 29
//Columns
#define C1 53
#define C2 52
#define C3 51
#define C4 50
#define C5 10
#define C6 11
#define C7 12
#define C8 13

#define LE0 37
#define LE1 36
#define LE2 35
#define LE3 34
#define LE4 33
#define LE5 32
#define LE6 31
#define LE7 30

int pause=300;


byte zero
  [8] [8] ={
  {0,0,0,0,0,0,0,0,},
{0,0,1,1,1,1,0,0,},
{0,1,0,0,0,0,1,0,},
{0,1,0,0,0,0,1,0,},
{0,1,0,0,0,0,1,0,},
{0,0,1,1,1,1,0,0,},
{0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,}};

byte one
  [8] [8] ={
  {0,0,0,0,0,0,0,0,},
{0,0,0,0,1,0,0,0,},
{0,0,0,0,1,0,0,0,},
{0,0,0,0,1,0,0,0,},
{0,0,0,0,1,0,0,0,},
{0,0,0,0,1,0,0,0,},
{0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,}};


byte two
  [8] [8] ={
  {0,0,0,0,0,0,0,0,},
{0,0,1,1,1,0,0,0,},
{0,0,0,0,0,1,0,0,},
{0,0,0,0,1,0,0,0,},
{0,0,0,1,0,0,0,0,},
{0,0,1,1,1,1,0,0,},
{0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,}};

byte three
  [8] [8] ={
  {0,0,0,0,0,0,0,0,},
{0,0,1,1,1,0,0,0,},
{0,0,0,0,0,1,0,0,},
{0,0,0,1,1,0,0,0,},
{0,0,0,0,0,1,0,0,},
{0,0,1,1,1,0,0,0,},
{0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,}};

byte four  [8] [8] ={
  {0,0,0,0,0,0,0,0,},
{0,0,0,0,1,0,0,0,},
{0,0,0,1,1,0,0,0,},
{0,0,1,1,1,1,0,0,},
{0,0,0,0,1,0,0,0,},
{0,0,0,0,1,0,0,0,},
{0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,}};

byte five  [8] [8] ={
  {0,0,0,0,0,0,0,0,},
{0,0,1,1,1,1,0,0,},
{0,0,1,0,0,0,0,0,},
{0,0,1,1,1,0,0,0,},
{0,0,0,0,0,1,0,0,},
{0,0,1,1,1,0,0,0,},
{0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,}};

byte six  [8] [8] ={
 {0,0,0,0,0,0,0,0,},
{0,0,0,1,1,0,0,0,},
{0,0,1,0,0,0,0,0,},
{0,0,1,1,1,0,0,0,},
{0,0,1,0,0,1,0,0,},
{0,0,1,1,1,0,0,0,},
{0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,}};

byte seven  [8] [8] ={
 {0,0,0,0,0,0,0,0,},
{0,0,1,1,1,1,1,0,},
{0,0,0,0,0,1,0,0,},
{0,0,0,0,1,0,0,0,},
{0,0,0,1,0,0,0,0,},
{0,0,1,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,}};

byte eight [8][8] = {
{0,0,0,0,0,0,0,0,},
{0,0,1,1,1,1,0,0,},
{0,1,0,0,0,0,1,0,},
{0,0,1,1,1,1,0,0,},
{0,1,0,0,0,0,1,0,},
{0,0,1,1,1,1,0,0,},
{0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,}};

byte nine [8][8] = {{0,0,0,0,0,0,0,0,},
{0,0,0,1,1,1,0,0,},
{0,0,1,0,0,0,1,0,},
{0,0,0,1,1,1,1,0,},
{0,0,0,0,0,0,1,0,},
{0,0,1,1,1,1,0,0,},
{0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,}};

/*  ASM diliyle BLINK
      Bu program ATMEGA'nın PIN, DDR ve PORT yazmaçlarını kullanarak
      PIN ayarları yapmayı gösteriyor.
      Kod IOreg adresi tekniğini kullanıyor.

      // Added by RK for Atmega2560 chip (see datashhet page 96)
      PINA  IOreg = 0x00     offset = 0x20
      DDRA  IOreg = 0x01     offset = 0x21  
      PORTA IOreg = 0x02     offset = 0x22

      PINL  IOreg = 0x00     offset = 0x20
      DDRL  IOreg = 0x01     offset = 0x21  
      PORTL IOreg = 0x02     offset = 0x22
      // rk

      PINB  IOreg = 0x03     offset = 0x23
      DDRB  IOreg = 0x04     offset = 0x24  
      PORTB IOreg = 0x05     offset = 0x25
      PINC  IOreg = 0x06     offset = 0x26
      DDRC  IOreg = 0x07     offset = 0x27
      PORTC IOreg = 0x08     offset = 0x28
      PIND  IOreg = 0x09     offset = 0x29
      DDRD  IOreg = 0x0A     offset = 0x2A
      PORTD IOreg = 0x0B     offset = 0x2B
 
      SAYMAÇLAR:  X: r27:r26          Y: r29:r28          ve Z: r31:r30
 */

volatile byte rowdata_mem;
volatile byte coldata_mem;
volatile byte ledata_mem;

// ROW  at port A
// COL  at port B
// LE   at port C

void writeToROWCOL(volatile byte rowdata, volatile byte coldata, volatile byte ledata){
  rowdata_mem=rowdata;
  coldata_mem=coldata;
  ledata_mem=ledata;

  asm (
    "lds r26, (rowdata_mem) \n" //store r26 into memory location of variable a
    "lds r27, (coldata_mem) \n" //store r26 into memory location of variable a
    "lds r28, (ledata_mem) \n" //store r26 into memory location of variable a
    //"sts (count2), r26 \n" //store r26 into memory location of variable a
    "out 0X02, r26 \n"          // PORTD saymacını güncelle (IOreg = 0x0B)
    "out 0x05, r27 \n"          // PORTD saymacını güncelle (IOreg = 0x0B)
    "out 0x08, r28 \n"          // PORTD saymacını güncelle (IOreg = 0x0B)
  );
  
}


void setup() {
   
    asm (
    "ldi r26, 0xff \n" //store r26 into memory location of variable a
    "out 0X01, r26 \n"          // DDRA 
    "out 0x04, r26 \n"          // DDRB 
    "out 0x07, r26 \n"          // DDRC 
  );
    
    Serial.begin(57600);
   
   pinMode(R1, OUTPUT);

   pinMode(R2, OUTPUT);
   pinMode(R3, OUTPUT);
   pinMode(R4, OUTPUT);

   pinMode(R5, OUTPUT);
   pinMode(R6, OUTPUT);
   pinMode(R7, OUTPUT);

   pinMode(R8, OUTPUT);
   pinMode(C1, OUTPUT);
   pinMode(C2, OUTPUT);

   pinMode(C3, OUTPUT);
   pinMode(C4, OUTPUT);
   pinMode(C5, OUTPUT);

   pinMode(C6, OUTPUT);
   pinMode(C7, OUTPUT);
   pinMode(C8, OUTPUT);

   pinMode(LE0,OUTPUT);
   pinMode(LE1,OUTPUT);
   pinMode(LE2,OUTPUT);
   pinMode(LE3,OUTPUT);
   pinMode(LE4,OUTPUT);
   pinMode(LE5,OUTPUT);
   pinMode(LE6,OUTPUT);
   pinMode(LE7,OUTPUT);

  /* digitalWrite(LE0,HIGH);
   digitalWrite(LE1,HIGH);
   digitalWrite(LE2,HIGH);
   digitalWrite(LE3,HIGH);
   digitalWrite(LE4,HIGH);
   digitalWrite(LE5,HIGH);
   digitalWrite(LE6,HIGH);
   digitalWrite(LE7,HIGH);*/

  digitalWrite(R1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);

  digitalWrite(R4,HIGH);
  digitalWrite(R5,HIGH);
  digitalWrite(R6,HIGH);

  digitalWrite(R7,HIGH);
  digitalWrite(R8,HIGH);
  digitalWrite(C1,LOW);

  digitalWrite(C2,LOW);
  digitalWrite(C3,LOW);
  digitalWrite(C4,LOW);

  digitalWrite(C5,LOW);
  digitalWrite(C6,LOW);
  digitalWrite(C7,LOW);

  digitalWrite(C8,LOW);
}



void SelectRow(int row){
  if (row==1)
  digitalWrite(R1,LOW); else digitalWrite(R1,HIGH);
  if (row==2) digitalWrite(R2,LOW);
  else digitalWrite(R2,HIGH);
  if (row==3) digitalWrite(R3,LOW); else digitalWrite(R3,HIGH);

  if (row==4) digitalWrite(R4,LOW); else digitalWrite(R4,HIGH);
  if (row==5)
  digitalWrite(R5,LOW); else digitalWrite(R5,HIGH);
  if (row==6) digitalWrite(R6,LOW);
  else digitalWrite(R6,HIGH);
  if (row==7) digitalWrite(R7,LOW); else digitalWrite(R7,HIGH);

  if (row==8) digitalWrite(R8,LOW); else digitalWrite(R8,HIGH);
}

void Set_LED_in_Active_Row(int column, int state){
  if (column==1) digitalWrite(C1,state);
  
  if (column==2) digitalWrite(C2,state); 
  if (column==3) digitalWrite(C3,state);
  
  if (column==4) digitalWrite(C4,state); 
  if (column==5) digitalWrite(C5,state);
  
  if (column==6) digitalWrite(C6,state); 
  if (column==7) digitalWrite(C7,state);
  
  if (column==8) digitalWrite(C8,state); 
}

void loop() {
  
  int num1;
  int num2;
  int num3;
  int num4;
  if (Serial.available()) {
    char input1 = Serial.read();
    if (isdigit(input1)) {
       num1 = input1 - '0';
      Serial.print(input1);
    }
    
    while (!Serial.available()){

    }

    char input2 = Serial.read();
    if (isdigit(input2)) {
       num2 = input2 - '0';
      Serial.print(input2);
    }

    while (!Serial.available()){

    }

    char input3 = Serial.read();
    if (isdigit(input3)) {
       num3 = input3 - '0';
      Serial.print(input3);
    }

    while (!Serial.available()){

    }

    char input4 = Serial.read();
    if (isdigit(input4)) {
       num4 = input4 - '0';
      Serial.print(input4);
    }

counter (num1,num2,num3,num4);

    

  }

display1(num1);
display2(num2);
display3(num3);
display4(num4);


     

 
}

void counter (int num1, int num2 ,int num3, int num4 ) {
display1(num1);
display2(num2);
display3(num3);
display4(num4);


int target = num1 * 1000 + num2 * 100 + num3 * 10 + num4;  

   int thousandscounter = 0;
   int hundredscounter = 0;
   int tenscounter = 0;
   int onescounter = 0;
   int counter = 0;

    int delayTime = analogRead(A0); // Read the value from the potentiometer
    delayTime = map(delayTime, 0, 1023, 0, 1023); // Map the potentiometer value to the desired delay range
    

    while (counter <= target) {
    
    display1(thousandscounter);
    display2(hundredscounter);
    display3(tenscounter);
    display4(onescounter);

    onescounter++;

    if (onescounter == 10) {
      tenscounter++;
      onescounter = 0;
    }

    if (tenscounter == 10) {
      hundredscounter++;
      tenscounter = 0;
    }

    if (hundredscounter == 10) {
      thousandscounter++;
      hundredscounter = 0;
    }
     
    int delayTime = analogRead(A0); // Read the value from the potentiometer
    delayTime = map(delayTime, 0, 1023, 0, 1023); // Map the potentiometer value to the desired delay range

    counter++;
    
    delay(delayTime);

  }

}

void display1 (int num) {

  digitalWrite(LE0,HIGH);
  digitalWrite(LE4,HIGH);

  if (num == 0) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,zero[j][i]);
        
        
      }
      delay(1);

    }
    }
 
else if (num == 1) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,one[j][i]);
        
        
      }
      delay(1);

    }
    }

    else if (num == 2) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,two[j][i]);
        
        
      }
      delay(1);

    }
    }
    else if (num == 3) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,three[j][i]);
        
        
      }
      delay(1);

    }
    }
    else if (num == 4) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,four[j][i]);
        
        
      }
      delay(1);

    }
    }
   else if (num == 5) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,five[j][i]);
        
        
      }
      delay(1);

    }
    }
 else if (num == 6) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,six[j][i]);
        
        
      }
      delay(1);

    }
    }
     else if (num == 7) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,seven[j][i]);
        
        
      }
      delay(1);

    }
    }
     else if (num == 8) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,eight[j][i]);
        
        
      }
      delay(1);

    }
    }
     else if (num == 9) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,nine[j][i]);
        
        
      }
      delay(1);

    }
    }
    
   digitalWrite(LE0,LOW);
  digitalWrite(LE4,LOW);

}

void display2 (int num) {
  digitalWrite(LE1,HIGH);
  digitalWrite(LE5,HIGH);
  
  if (num == 0) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,zero[j][i]);
        
        
      }
      delay(1);

    }
    }
 
else if (num == 1) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,one[j][i]);
        
        
      }
      delay(1);

    }
    }

    else if (num == 2) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,two[j][i]);
        
        
      }
      delay(1);

    }
    }
    else if (num == 3) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,three[j][i]);
        
        
      }
      delay(1);

    }
    }
    else if (num == 4) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,four[j][i]);
        
        
      }
      delay(1);

    }
    }
   else if (num == 5) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,five[j][i]);
        
        
      }
      delay(1);

    }
    }
 else if (num == 6) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,six[j][i]);
        
        
      }
      delay(1);

    }
    }
     else if (num == 7) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,seven[j][i]);
        
        
      }
      delay(1);

    }
    }
     else if (num == 8) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,eight[j][i]);
        
        
      }
      delay(1);

    }
    }
     else if (num == 9) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,nine[j][i]);
        
        
      }
      delay(1);

    }
    }
   
digitalWrite(LE1,LOW);
  digitalWrite(LE5,LOW);
}

void display3 (int num) {
  digitalWrite(LE2,HIGH);
  digitalWrite(LE6,HIGH);
  
  if (num == 0) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,zero[j][i]);
        
        
      }
      delay(1);

    }
    }
 
else if (num == 1) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,one[j][i]);
        
        
      }
      delay(1);

    }
    }

    else if (num == 2) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,two[j][i]);
        
        
      }
      delay(1);

    }
    }
    else if (num == 3) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,three[j][i]);
        
        
      }
      delay(1);

    }
    }
    else if (num == 4) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,four[j][i]);
        
        
      }
      delay(1);

    }
    }
   else if (num == 5) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,five[j][i]);
        
        
      }
      delay(1);

    }
    }
 else if (num == 6) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,six[j][i]);
        
        
      }
      delay(1);

    }
    }
     else if (num == 7) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,seven[j][i]);
        
        
      }
      delay(1);

    }
    }
     else if (num == 8) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,eight[j][i]);
        
        
      }
      delay(1);

    }
    }
     else if (num == 9) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,nine[j][i]);
        
        
      }
      delay(1);

    }
    }

digitalWrite(LE2,LOW);
  digitalWrite(LE6,LOW);
}

void display4 (int num) {
  digitalWrite(LE3,HIGH);
  digitalWrite(LE7,HIGH);
  
  if (num == 0) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,zero[j][i]);
        
        
      }
      delay(1);

    }
    }
 
else if (num == 1) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,one[j][i]);
        
        
      }
      delay(1);

    }
    }

    else if (num == 2) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,two[j][i]);
        
        
      }
      delay(1);

    }
    }
    else if (num == 3) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,three[j][i]);
        
        
      }
      delay(1);

    }
    }
    else if (num == 4) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,four[j][i]);
        
        
      }
      delay(1);

    }
    }
   else if (num == 5) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,five[j][i]);
        
        
      }
      delay(1);

    }
    }
 else if (num == 6) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,six[j][i]);
        
        
      }
      delay(1);

    }
    }
     else if (num == 7) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,seven[j][i]);
        
        
      }
      delay(1);

    }
    }
     else if (num == 8) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,eight[j][i]);
        
        
      }
      delay(1);

    }
    }
     else if (num == 9) {for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){

        Set_LED_in_Active_Row(i+1 ,nine[j][i]);
        
        
      }
      delay(1);

    }
    }

    
digitalWrite(LE3,LOW);
  digitalWrite(LE7,LOW);
}