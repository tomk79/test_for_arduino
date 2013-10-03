// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo myservo0;  // create servo object to control a servo 
Servo myservo1;  // create servo object to control a servo 
 
int potpin0 = 0;  // analog pin used to connect the potentiometer
int potpin1 = 1;  // analog pin used to connect the potentiometer
int val0;    // variable to read the value from the analog pin 
int val1;    // variable to read the value from the analog pin 
 
void setup() 
{ 
  myservo0.attach(9);  // attaches the servo on pin 9 to the servo object 
  myservo1.attach(8);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);
    // ↑シリアル接続を開始する。
    // 　引数 9600 は、スピードとのこと。
}//setup();




 
void loop() 
{ 
  val0 = analogRead(potpin0);            // reads the value of the potentiometer (value between 0 and 1023) 
  val0 = map(val0, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
      //可変抵抗は0〜1023の値を返すが、Arduinoのサーボ出力は0〜179までで指示をしないといけない
  myservo0.write(val0);                  // sets the servo position according to the scaled value 

  val1 = analogRead(potpin1);            // reads the value of the potentiometer (value between 0 and 1023) 
  val1 = map(val1, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
      //可変抵抗は0〜1023の値を返すが、Arduinoのサーボ出力は0〜179までで指示をしないといけない
  val1 = 179 - val1;//←逆回転させる
      //  val1 = map(val1, 0, 1023, 179, 0); //←これでもOK
  myservo1.write(val1);                  // sets the servo position according to the scaled value 

  delay(15);                           // waits for the servo to get there 

  Serial.print("BooFooWoo\n");
    // この命令でシリアルポートに文字列を送る。
    // 右上のシリアルモニタで送った値をみることができる。
    // traceみたいなことができる。
    // これを使うと、Arduino IDE以外のアプリケーションと通信することもできる。

}//loop();




