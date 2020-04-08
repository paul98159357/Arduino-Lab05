#include <Keypad.h>
const byte ROWS = 4; // 4 Rows
const byte COLS = 4; // 4 Columns
// 定義 Keypad 的按鍵
char keys[ROWS][COLS] = {{'F', 'B', 'A', '0'},
                         {'E', '3', '2', '1'},
                         {'D', '6', '5', '4'}, 
                         {'C', '9', '8', '7'}};
// 定義 Keypad 連到 Arduino 的接腳 // 按鍵模組，列1~4接腳。
byte rowPins[ROWS] = {2, 3, 4, 5};
// 連到 Keypad 的 4 個 Rows       // 按鍵模組，行1~4接腳。 
byte colPins[COLS] = {6, 7, 8, 9};
// 連到 Keypad 的 4 個 Columns

// 建立 Keypad 物件
Keypad keypad =Keypad( makeKeymap(keys), rowPins,colPins, ROWS, COLS );
int seg7[]={17, 16, 15, 14, 13, 12, 11};
char TAB1[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,0x7F,0x67};
char TAB2[]={0x77,0x7C,0x39,0x5E,0x79,0x71};
int i,j;
char ch;
byte no;

void setup() {
  for(i=0;i<7;i++){
    pinMode(seg7[i],OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("Please press the keyboard:");
}

void loop() {

  char key = keypad.getKey(); // 讀取 Keypad的輸入
  if(key!=NO_KEY)
  {
    Serial.print("Key Value : ");
    Serial.println(key);//印出所按下的字元
}
  if(key>='0' && key<='9'){   /*實驗1*/
   no=key-'0';
   OutPort(TAB1[no]);
   delay(1000);
   
  }if(key>='A' && key<='F'){   /*實驗2*/
    no=key-'A';//將ASCII值轉成數值no
    OutPort(TAB2[no]);//OutPort我no的數值
    delay(1000);
   }
}
void OutPort(byte dat){
  for(j=0;j<7;j++){
    if(dat%2==1)
      digitalWrite(seg7[j],HIGH);
     else
      digitalWrite(seg7[j],LOW);
     dat = dat/2;
  }
}
