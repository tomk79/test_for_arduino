int count = 0;

void setup(){
  Serial.begin(9600);
  delay(100);
  Serial.write('s');
  Serial.write('e');
  Serial.write('t');
  Serial.write('u');
  Serial.write('p');
  Serial.write('(');
  Serial.write(')');
  Serial.write(' ');
  Serial.write('d');
  Serial.write('o');
  Serial.write('n');
  Serial.write('e');
  Serial.write('.');
  Serial.print("\n");
  delay(1000);

}

void loop(){
  count ++;
  if( count > 120 ){ count = 1; }
  
  Serial.print(count);
  Serial.print("\n");

  delay(200);
}
