#include <SoftwareSerial.h> //시리얼 통신 라이브러리 호출
 
int blueTx=10;   //Tx (보내는핀 설정)
int blueRx=11;   //Rx (받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
String myString=""; //받는 문자열
int layer[4] = {2, 3, 4, 5};
int R[16] = {22, 25, 28, 31, 34, 37, 40, 43, 46, 49, 21, 18, A15, A12, A9, A6};
int G[16] = {23, 26, 29, 32, 35, 38, 41, 44, 47, 50, 20, 17, A14, A11, A8, A5};
int B[16] = {24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 19, 16, A13, A10, A7, A4};
int* led[3] = {R, G, B};
int d1 = 5;
int d2 = 10;
int d3 = 50;
int d4 = 100;
int c1 = 0;

void p1();
void inputcheck();
void redp();
void grep();
void blup();
void back();
void p2();
void p3();
void p4(int, int);
void p5();
void redp1();
void redp2();
void p4p(int);

void setup() {
  Serial.begin(9600);   //시리얼모니터 
  mySerial.begin(9600); //블루투스 시리얼 개방
  
  for(int i = 0; i < 4; i++){
    pinMode(layer[i], OUTPUT);
  }
  for(int i = 0; i < 16; i++){
    pinMode(R[i], OUTPUT);
    pinMode(G[i], OUTPUT);
    pinMode(B[i], OUTPUT);
  }
  p1();
}
 
void loop() {
  inputcheck();
  if(!myString.equals("")){  //myString 값이 있다면
    Serial.println("input value: "+myString); //시리얼모니터에 myString값 출력
    Serial.println(c1);
    initlayer();
    initled();
     if(myString=="1"){
        c1 = ++c1 % 4;
       if(c1 == 1){
        digitalWrite(layer[0], 1);
        digitalWrite(G[0], 0);
      }
      else if(c1 == 2){
        digitalWrite(layer[0], 1);
        digitalWrite(B[0], 0);
      }
      else if(c1 == 3){
        digitalWrite(layer[0], 1);
        digitalWrite(R[0], 0);
        digitalWrite(G[0], 0);
        digitalWrite(B[0], 0);
      }
      else if(c1 == 0){
        digitalWrite(layer[0], 1);
        digitalWrite(R[0], 0);
      }
     }
     else if(myString=="5"){
      if(c1 == 0){
        redp();
      }
      else if(c1 == 1){
        grep();
      }
      else if(c1 == 2){
        blup();
      }
      else if(c1 == 3){
        bacp();
      }
     }
  }
}

void inputcheck(){
  myString="";
  while(mySerial.available()){  //mySerial 값이 있으면
    char myChar = (char)mySerial.read();  //mySerial int형식의 값을 char형식으로 변환
    myString=myChar;   //수신되는 문자열을 myString에 모두 붙임 (1바이트씩 전송되는 것을 모두 붙임)
    delay(5);           //수신 문자열 끊김 방지
  }
}

void initlayer(){
  for(int i = 0; i < 4; i++){
    digitalWrite(layer[i], 0);
  }
}

void initled(){
  for(int i = 0; i < 16; i++){
    digitalWrite(R[i], 1);
    digitalWrite(G[i], 1);
    digitalWrite(B[i], 1);
  }
}

void redp(){
  digitalWrite(layer[1], 1);
  digitalWrite(led[0][0], 0);
  int c2 = 0;
  while(1){
    do{
    inputcheck();
  }while(myString.equals(""));
    initled();
    initlayer();
    if(myString == "1"){
      c2 = ++c2 % 3; 
      p4(0, 1);
    }
    else if(myString == "2"){
      c2 = --c2 % 3;
      if(c2 < 0){
        c2 = 3;
      }
      p4(0, 0);
    }
    else if(myString == "U"){
      return;
    }
    else if(myString == "5"){
      if(c2 == 0){
        redp1();
      }
      else if(c2 == 1){
        redp2();
      }
    }
  }
}

void grep(){
  digitalWrite(layer[1], 1);
  digitalWrite(led[1][0], 0);
  int c2 = 0;
  while(1){
    do{
    inputcheck();
  }while(myString.equals(""));
    initled();
    initlayer();
    if(myString == "1"){
      c2 = ++c2 % 3; 
      p4(1, 1);
    }
    else if(myString == "2"){
      c2 = --c2 % 3;
      if(c2 < 0){
        c2 = 3;
      }
      p4(1, 0);
    }
    else if(myString == "U"){
      return;
    }
    else if(myString == "5"){
      if(c2 == 0){
        grep1();
      }
      else if(c2 == 1){
        grep2();
      }
    }
  }
}

void blup(){
 digitalWrite(layer[1], 1);
  digitalWrite(led[2][0], 0);
  int c2 = 0;
  while(1){
    do{
    inputcheck();
  }while(myString.equals(""));
    initled();
    initlayer();
    if(myString == "1"){
      c2 = ++c2 % 3; 
      p4(2, 1);
    }
    else if(myString == "2"){
      c2 = --c2 % 3;
      if(c2 < 0){
        c2 = 3;
      }
      p4(2, 0);
    }
    else if(myString == "U"){
      return;
    }
    else if(myString == "5"){
      if(c2 == 0){
        blup1();
      }
      else if(c2 == 1){
        blup2();
      }
    }
  }
}

void bacp(){
  int c2 = 0;
  digitalWrite(layer[1], 1);
  digitalWrite(led[0][0], 0);
  digitalWrite(led[1][0], 0);
  digitalWrite(led[2][0], 0);
  while(1){
    do{
    inputcheck();
  }while(myString.equals(""));
    Serial.println("bacp value: "+myString); //시리얼모니터에 myString값 출력
    Serial.println(c2);
    initled();
    initlayer();
    if(myString == "1"){
      c2 = ++c2 % 3; 
      p4p(1);
    }
    else if(myString == "2"){
      c2 = --c2 % 3;
      if(c2 < 0){
        c2 = 3;
      }
      p4p(0);
    }
    else if(myString == "U"){
      return;
    }
    else if(myString == "5"){
      if(c2 == 0){
        p2();
      }
      else if(c2 == 1){
        p3();
      }
      else if(c2 == 2){
        Serial.println("check p5();");
        p5();
      }
    }
  }
}

void redp1(){
  int d = d4;
   while(1){
      inputcheck();
    if(myString == "U"){
      return;
    }
    else if(myString == "T"){
      digitalWrite(layer[1], 1);
      digitalWrite(layer[2], 1);
      digitalWrite(R[5], 0);
      digitalWrite(R[6], 0);
      digitalWrite(R[9], 0);
      digitalWrite(R[10], 0);
      delay(d);

      digitalWrite(layer[0], 1);
      digitalWrite(layer[3], 1);
      digitalWrite(R[0], 0);
      digitalWrite(R[1], 0);
      digitalWrite(R[2], 0);
      digitalWrite(R[3], 0);
      digitalWrite(R[4], 0);
      digitalWrite(R[7], 0);
      digitalWrite(R[8], 0);
      digitalWrite(R[11], 0);
      digitalWrite(R[12], 0);
      digitalWrite(R[13], 0);
      digitalWrite(R[14], 0);
      digitalWrite(R[15], 0);
      delay(d);
      for(int i = 0; i < 10; i++){
        initled();
        initlayer();
  
        digitalWrite(layer[0], 1);
        digitalWrite(layer[3], 1);
        digitalWrite(R[0], 0);
        digitalWrite(R[1], 0);
        digitalWrite(R[2], 0);
        digitalWrite(R[3], 0);
        digitalWrite(R[4], 0);
        digitalWrite(R[5], 0);
        digitalWrite(R[6], 0);
        digitalWrite(R[7], 0);
        digitalWrite(R[8], 0);
        digitalWrite(R[9], 0);
        digitalWrite(R[10], 0);
        digitalWrite(R[11], 0);
        digitalWrite(R[12], 0);
        digitalWrite(R[13], 0);
        digitalWrite(R[14], 0);
        digitalWrite(R[15], 0);
        delay(d1);
  
        initled();
        initlayer();
  
        digitalWrite(layer[1], 1);
        digitalWrite(layer[2], 1);
        digitalWrite(R[0], 0);
        digitalWrite(R[1], 0);
        digitalWrite(R[2], 0);
        digitalWrite(R[3], 0);
        digitalWrite(R[4], 0);
        digitalWrite(R[7], 0);
        digitalWrite(R[8], 0);
        digitalWrite(R[11], 0);
        digitalWrite(R[12], 0);
        digitalWrite(R[13], 0);
        digitalWrite(R[14], 0);
        digitalWrite(R[15], 0);
        delay(d1);
      }
      initlayer();
      initled();
    }
   }
}

void redp2(){
  int d = d3;
  int s = 0;
   while(1){
      inputcheck();
    if(myString == "U"){
      return;
    }
    else if(myString == "T"){
      if(s == 16){
        s = 0;
      }
      else{
        s++;
      }
      digitalWrite(R[s], 0);
      digitalWrite(layer[0], 1);
      delay(d);
      initlayer();
      digitalWrite(layer[1], 1);
      delay(d);
      initlayer();
      digitalWrite(layer[2], 1);
      delay(d);
      initlayer();
      digitalWrite(layer[3], 1);
      delay(d);
      initlayer();
      initled();
    }
   }
}

void blup1(){
  int d = d4;
  int s = 0;
   while(1){
      inputcheck();
    if(myString == "U"){
      return;
    }
    else if(myString == "1"){
      for(int i = 0; i < 8; i++){
        s = random(16);
        digitalWrite(B[s], 0);
        digitalWrite(layer[3], 1);
        delay(d);
        initlayer();
        digitalWrite(layer[2], 1);
        delay(d);
        initlayer();
        digitalWrite(layer[1], 1);
        delay(d);
        initlayer();
        digitalWrite(layer[0], 1);
        delay(d);
        initlayer();
        initled();
      }
    }
   }
}

void blup2(){
  int d = d4;
  int s = 0;
  int q = 0;
   while(1){
      inputcheck();
    if(myString == "U"){
      return;
    }
    else if(myString == "1"){
      for(int i = 0; i < 8; i++){
        s = random(16);
        q = random(4);
        digitalWrite(B[s], 0);
        digitalWrite(layer[q], 1);
        delay(d);
        initlayer();
        initled();
      }
    }
   }
}

void grep1(){
  int d = d4;
  int s = 0;
  int q = 0;
  int n = 0;
   while(1){
      inputcheck();
    if(myString == "U"){
      initlayer();
      initled();
      return;
    }
    else if(myString == "2"){
      n = random(4);
      for(int i = 0; i < n; i++){
        s = random(16);
        q = random(4);
        digitalWrite(G[s], 0);
        digitalWrite(layer[q], 1);
        delay(d);
      }
    }
   }
}

void grep2(){
  int d = d4;
  int s = 0;
  int q = 0;
   while(1){
      inputcheck();
    if(myString == "U"){
      return;
    }
    else if(myString == "2"){
        digitalWrite(G[3], 0);
        digitalWrite(G[7], 0);
        digitalWrite(G[11], 0);
        digitalWrite(G[15], 0);
        digitalWrite(layer[0], 1);
        digitalWrite(layer[1], 1);
        digitalWrite(layer[2], 1);
        digitalWrite(layer[3], 1);
        delay(d);
        initlayer();
        initled();
      }
      else if(myString == "1"){
        digitalWrite(G[0], 0);
        digitalWrite(G[4], 0);
        digitalWrite(G[8], 0);
        digitalWrite(G[12], 0);
        digitalWrite(layer[0], 1);
        digitalWrite(layer[1], 1);
        digitalWrite(layer[2], 1);
        digitalWrite(layer[3], 1);
        delay(d);
        initlayer();
        initled();
      }
    }
   }

void p1(){
  initlayer();
  initled();
  int d = d2;
  for(int i = 0; i < 4; i++){
    digitalWrite(layer[i], 1);
    for(int j = 0; j < 16; j++){
      digitalWrite(B[j], 0);
      delay(d);
      digitalWrite(B[j], 1);
      delay(d);
      digitalWrite(R[j], 0);
      delay(d);
      digitalWrite(R[j], 1);
      delay(d);
      digitalWrite(G[j], 0);
      delay(d);
      digitalWrite(G[j], 1);
      delay(d);
      }
    digitalWrite(layer[i], 0);
    }
  initlayer();
  initled();
}

void p2(){
  initlayer();
  initled();
  int d = d3;
  while(1){
  for(int i = 0; i < 4; i++){
    digitalWrite(layer[i], 1);
    for(int j = 0; j < 16; j++){
      inputcheck();
      Serial.println("p2 input value: "+myString);
      if(myString == "U"){
        initlayer();
        initled();
        return;
      }
      digitalWrite(R[j], 0);
      delay(d);
    }
    initled();
    for(int j = 0; j < 16; j++){
      inputcheck();
      Serial.println("p2 input value: "+myString);
      if(myString == "U"){
        initlayer();
        initled();
        return;
      }
      digitalWrite(G[j], 0);
      delay(d);
    }
    initled();
    for(int j = 0; j < 16; j++){
      inputcheck();
      Serial.println("p2 input value: "+myString);
      if(myString == "U"){
        initlayer();
        initled();
        return;
      }
      digitalWrite(B[j], 0);
      delay(d);
    }
    initled();
    initlayer();
  }
  }
}

void p3(){
  initlayer();
  initled();
  int c = 0;
  int d = d1;
  while(1){
    for(int i = 0; i < 24; i++){
      inputcheck();
    if(myString == "U"){
      return;
    }
    else if(myString == "1"){
      c = ++c%3;
    }
    digitalWrite(layer[0], 1);
    digitalWrite(led[c][0], 0);
    delay(d);
    initlayer();
    initled();
    }
    //
    for(int i = 0; i < 12; i++){
      inputcheck();
    if(myString == "U"){
      return;
    }
    else if(myString == "1"){
      c = ++c%3;
    }
    digitalWrite(layer[0], 1);
    digitalWrite(led[c][1], 0);
    digitalWrite(led[c][4], 0);
    delay(d);
    initlayer();
    initled();

    digitalWrite(layer[1], 1);
    digitalWrite(led[c][0], 0);
    delay(d);
    initlayer();
    initled();
    }
    //
    for(int i = 0; i < 8; i++){
      inputcheck();
    if(myString == "U"){
      return;
    }
    else if(myString == "1"){
      c = ++c%3;
    }
    digitalWrite(layer[0], 1);
    digitalWrite(led[c][2], 0);
    digitalWrite(led[c][5], 0);
    digitalWrite(led[c][8], 0);
    delay(d);
    initlayer();
    initled();

    digitalWrite(layer[1], 1);
    digitalWrite(led[c][1], 0);
    digitalWrite(led[c][4], 0);
    delay(d);
    initlayer();
    initled();

    digitalWrite(layer[2], 1);
    digitalWrite(led[c][0], 0);
    delay(d);
    initlayer();
    initled();
    }
    //
    for(int i = 0; i < 6; i++){
      inputcheck();
    if(myString == "U"){
      return;
    }
    else if(myString == "1"){
      c = ++c%3;
    }
    digitalWrite(layer[0], 1);
    digitalWrite(led[c][3], 0);
    digitalWrite(led[c][6], 0);
    digitalWrite(led[c][9], 0);
    digitalWrite(led[c][12], 0);
    delay(d);
    initlayer();
    initled();

    digitalWrite(layer[1], 1);
    digitalWrite(led[c][2], 0);
    digitalWrite(led[c][5], 0);
    digitalWrite(led[c][8], 0);
    delay(d);
    initlayer();
    initled();

    digitalWrite(layer[2], 1);
    digitalWrite(led[c][1], 0);
    digitalWrite(led[c][4], 0);
    delay(d);
    initlayer();
    initled();

    digitalWrite(layer[3], 1);
    digitalWrite(led[c][0], 0);
    delay(d);
    initlayer();
    initled();
    }
    //
    for(int i = 0; i < 6; i++){
      inputcheck();
    if(myString == "U"){
      return;
    }
    else if(myString == "1"){
      c = ++c%3;
    }
    digitalWrite(layer[3], 1);
    digitalWrite(led[c][12], 0);
    digitalWrite(led[c][9], 0);
    digitalWrite(led[c][6], 0);
    digitalWrite(led[c][3], 0);
    delay(d);
    initlayer();
    initled();

    digitalWrite(layer[2], 1);
    digitalWrite(led[c][13], 0);
    digitalWrite(led[c][10], 0);
    digitalWrite(led[c][7], 0);
    delay(d);
    initlayer();
    initled();

    digitalWrite(layer[1], 1);
    digitalWrite(led[c][14], 0);
    digitalWrite(led[c][11], 0);
    delay(d);
    initlayer();
    initled();

    digitalWrite(layer[1], 1);
    digitalWrite(led[c][15], 0);
    delay(d);
    initlayer();
    initled();
    }
    //
    for(int i = 0; i < 8; i++){
      inputcheck();
    if(myString == "U"){
      return;
    }
    else if(myString == "1"){
      c = ++c%3;
    }
    digitalWrite(layer[3], 1);
    digitalWrite(led[c][13], 0);
    digitalWrite(led[c][10], 0);
    digitalWrite(led[c][7], 0);
    delay(d);
    initlayer();
    initled();

    digitalWrite(layer[2], 1);
    digitalWrite(led[c][14], 0);
    digitalWrite(led[c][11], 0);
    delay(d);
    initlayer();
    initled();
    
    digitalWrite(layer[1], 1);
    digitalWrite(led[c][15], 0);
    delay(d);
    initlayer();
    initled();
    }
    //
    for(int i = 0; i < 12; i++){
      inputcheck();
    if(myString == "U"){
      return;
    }
    else if(myString == "1"){
      c = ++c%3;
    }
    digitalWrite(layer[3], 1);
    digitalWrite(led[c][14], 0);
    digitalWrite(led[c][11], 0);
    delay(d);
    initlayer();
    initled();

    digitalWrite(layer[2], 1);
    digitalWrite(led[c][15], 0);
    delay(d);
    initlayer();
    initled();
    }
    //
    for(int i = 0; i < 24; i++){
      inputcheck();
    if(myString == "U"){
      return;
    }
    else if(myString == "1"){
      c = ++c%3;
    }
    digitalWrite(layer[3], 1);
    digitalWrite(led[c][15], 0);
    delay(d);
    initlayer();
    initled();
    }
  }
}

void p4(int num, int j){
  initlayer();
  initled();
  digitalWrite(layer[0], 1);
  digitalWrite(layer[1], 1);
  digitalWrite(layer[2], 1);
  digitalWrite(layer[3], 1);
  if(j == 1){
    for(int i = 0; i < 4; i++){
      digitalWrite(led[num][3-i], 0);
      digitalWrite(led[num][7-i], 0);
      digitalWrite(led[num][11-i], 0);
      digitalWrite(led[num][15-i], 0);
      delay(50);
      initled();
    }
  }
  else{
    for(int i = 0; i < 4; i++){
      digitalWrite(led[num][i], 0);
      digitalWrite(led[num][i+4], 0);
      digitalWrite(led[num][i+8], 0);
      digitalWrite(led[num][i+12], 0);
      delay(50);
      initled();
    }
  }
  initlayer();
}

void p4p(int j){
  initlayer();
  initled();
  digitalWrite(layer[0], 1);
  digitalWrite(layer[1], 1);
  digitalWrite(layer[2], 1);
  digitalWrite(layer[3], 1);
  if(j == 1){
    for(int i = 0; i < 4; i++){
      digitalWrite(R[3-i], 0);
      digitalWrite(R[7-i], 0);
      digitalWrite(R[11-i], 0);
      digitalWrite(R[15-i], 0);
      digitalWrite(G[3-i], 0);
      digitalWrite(G[7-i], 0);
      digitalWrite(G[11-i], 0);
      digitalWrite(G[15-i], 0);
      digitalWrite(B[3-i], 0);
      digitalWrite(B[7-i], 0);
      digitalWrite(B[11-i], 0);
      digitalWrite(B[15-i], 0);
      delay(50);
      initled();
    }
  }
  else{
    for(int i = 0; i < 4; i++){
      digitalWrite(R[i], 0);
      digitalWrite(R[i+4], 0);
      digitalWrite(R[i+8], 0);
      digitalWrite(R[i+12], 0);
      digitalWrite(G[i], 0);
      digitalWrite(G[i+4], 0);
      digitalWrite(G[i+8], 0);
      digitalWrite(G[i+12], 0);
      digitalWrite(B[i], 0);
      digitalWrite(B[i+4], 0);
      digitalWrite(B[i+8], 0);
      digitalWrite(B[i+12], 0);
      delay(50);
      initled();
    }
  }
  initlayer();
}

void p5(){
  initlayer();
  initled();
  int counter = 2;
  int d = d4;
  int c = 0;
  do{
    inputcheck();
  }while(myString.equals(""));
  if(myString == "3"){
    while(counter--){
      inputcheck();
      Serial.println("p5 input value: "+myString);
      if(myString == "U"){
        initlayer();
        initled();
        return;
        }
      else if(myString == "3"){
        counter += 5;
        }
      else if(myString == "1"){
        c = ++c % 3;
        }
      if(counter <= 10){
        initlayer();
        digitalWrite(layer[0], 1); 
        d = d4;
        }
      else if(counter <= 20){
        initlayer();
        digitalWrite(layer[1], 1);
        d = d3;
        }
      else if(counter <= 30){
        initlayer();
        digitalWrite(layer[2], 1);
        d = d2;
        }
      else {
        initlayer();
        digitalWrite(layer[3], 1);
        d = d1;
        }
      //for(int i = 0; i < 12; i++){
        digitalWrite(led[c][0], 0);
        delay(d);
        initled();
        digitalWrite(led[c][1], 0);
        delay(d);
        initled();
        digitalWrite(led[c][2], 0);
        delay(d);
        initled();
        digitalWrite(led[c][3], 0);
        delay(d);
        initled();
        digitalWrite(led[c][7], 0);
        delay(d);
        initled();
        digitalWrite(led[c][11], 0);
        delay(d);
        initled();
        digitalWrite(led[c][15], 0);
        delay(d);
        initled();
        digitalWrite(led[c][14], 0);
        delay(d);
        initled();
        digitalWrite(led[c][13], 0);
        delay(d);
        initled();
        digitalWrite(led[c][12], 0);
        delay(d);
        initled();
        digitalWrite(led[c][8], 0);
        delay(d);
        initled();
        digitalWrite(led[c][4], 0);
        delay(d);
        initled();
        //}
      }
    }
    else{
      while(counter--){
        inputcheck();
        Serial.println("p5 input value: "+myString);
        if(myString == "U"){
          initlayer();
          initled();
          return;
          }
        else if(myString == "4"){
          counter += 5;
          }
        else if(myString == "2"){
          c = ++c % 3;
          }
        if(counter <= 10){
          initlayer();
          digitalWrite(layer[0], 1); 
          d = d4;
          }
        else if(counter <= 20){
          initlayer();
          digitalWrite(layer[1], 1);
          d = d3;
          }
        else if(counter <= 30){
          initlayer();
          digitalWrite(layer[2], 1);
          d = d2;
          }
        else {
          initlayer();
          digitalWrite(layer[3], 1);
          d = d1;
          }
        //for(int i = 0; i < 12; i++){
          digitalWrite(led[c][0], 0);
          delay(d);
          initled();
          digitalWrite(led[c][4], 0);
          delay(d);
          initled();
          digitalWrite(led[c][8], 0);
          delay(d);
          initled();
          digitalWrite(led[c][12], 0);
          delay(d);
          initled();
          digitalWrite(led[c][13], 0);
          delay(d);
          initled();
          digitalWrite(led[c][14], 0);
          delay(d);
          initled();
          digitalWrite(led[c][15], 0);
          delay(d);
          initled();
          digitalWrite(led[c][11], 0);
          delay(d);
          initled();
          digitalWrite(led[c][7], 0);
          delay(d);
          initled();
          digitalWrite(led[c][3], 0);
          delay(d);
          initled();
          digitalWrite(led[c][2], 0);
          delay(d);
          initled();
          digitalWrite(led[c][1], 0);
          delay(d);
          initled();
        //}
    }
  }
}
