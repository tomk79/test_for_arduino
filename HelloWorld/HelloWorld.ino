//  Example 01 : Blinking LED
// via: http://www.pxt.jp/ja/diary/article/280/

const int LED = 13; // LEDはデジタルピン13に接続

void setup(){
  pinMode(LED, OUTPUT); // デジタルピンを出力に設定
}

void loop(){
  digitalWrite(LED, HIGH);  // LEDを点ける
  delay(2000);              // 2秒待つ
  digitalWrite(LED, LOW);   // LEDを消す
  delay(2000);              // 2秒待つ
}
