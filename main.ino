int a;
int b;
int c;
int d;
int e;

int a1;
int b1;
int a2 = 0;
int b2 = 0;
int c1 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  Serial.begin(9600);

  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

  pinMode(5,INPUT);
  pinMode(6,INPUT);

  pinMode(10,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);


  

}

void loop() {
  // put your main code here, to run repeatedly:
  

  digitalWrite(14,HIGH);
  digitalWrite(15,LOW);
  a = analogRead(A0);
  b = analogRead(A1);
  c = analogRead(A2);
  d = analogRead(A3);
  e = analogRead(A4);
  a1 = digitalRead(5);
  b1 = digitalRead(6);

  if(a1 == 0){
    delay(500);
    if(a2 == 0){
      a2 = 1;

    }
    else{
      a2 = 0;
    }
  }

  if(b1 == 0){
    delay(500);
    if(b2 == 0){
      b2 = 1;

    }
    else{
      b2 = 0;
    }
  }

  if(a > 600 || a2 == 1){
    digitalWrite(2,HIGH);
  }
  else{
    digitalWrite(2,LOW);
  }
  if(b > 600 || b2 == 1){
    digitalWrite(3,HIGH);
  }
  else{
    digitalWrite(3,LOW);
  }
  if(c > 600){
    digitalWrite(12,HIGH);
    analogWrite(10,250);
  }
  else{
    digitalWrite(12,LOW);
    analogWrite(10,0);
  }
  if(d > 600){
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }
  if(e > 600){
    delay(1000);
    if(c1 == 0){
      c1 = 1;
      Serial.println("first");
    }
    else{
      c1 = 0;
      Serial.println("second");
    }
  }
  
}
