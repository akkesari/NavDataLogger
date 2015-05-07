void setup(){
  Serial.begin(38400);
  Serial1.begin(4800);
}

void loop(){
  if(Serial1.available()){
    Serial.write(Serial1.read());
  }
}
