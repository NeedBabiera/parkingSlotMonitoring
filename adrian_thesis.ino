#include <SoftwareSerial.h>
SoftwareSerial SIM900(10, 11); //RX = 11 arduino shield (8), TX = 10 arduino shield (7);


int trigPin1 = 22;
//PARKING #1
int echoPin1 = 23;

int trigPin2 = 24;
//PARKING #2
int echoPin2 = 25;

int trigPin3 = 26;
//PARKING #3
int echoPin3 = 27;

int trigPin4 = 28;
//PARKING #4
int echoPin4 = 29;

int trigPin5 = 30;
//PARKING #5
int echoPin5 = 31;

int trigPin6 = 32;
//PARKING #6
int echoPin6 = 33;

int trigPin7 = 34;
//PARKING #7
int echoPin7 = 35;

int trigPin8 = 36;
//PARKING #8
int echoPin8 = 37;

int trigPin9 = 38;
//PARKING #9
int echoPin9 = 39;

int trigPin10 = 40;
//PARKING #10
int echoPin10 = 41;

String rcv;
String PreviousState;
String ContactNumber = "";
int cntSend = 0;

String incomingSMS = "";
String msgContent = "";
String msgContact = "";
String displayMsg = "";
String smsVal = "";
String contactVal = "";
String slotRes = "";

void setup() {

  Serial.begin (9600);

  SIM900.begin(19200);

  delay(1000);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);

  pinMode(trigPin5, OUTPUT);
  pinMode(echoPin5, INPUT);

  pinMode(trigPin6, OUTPUT);
  pinMode(echoPin6, INPUT);

  pinMode(trigPin7, OUTPUT);
  pinMode(echoPin7, INPUT);

  pinMode(trigPin8, OUTPUT);
  pinMode(echoPin8, INPUT);

  pinMode(trigPin9, OUTPUT);
  pinMode(echoPin9, INPUT);

  pinMode(trigPin10, OUTPUT);
  pinMode(echoPin10, INPUT);
}

void loop() {
  delay(1000);
  if (Serial.available() > 0)
  {
    rcv = Serial.readString();

    PreviousState = rcv.substring(0, 1);
    ContactNumber = rcv.substring(1, 14);
  }
  readSMS();
  //PARKING #1
  long duration1, distance1;
  digitalWrite(trigPin1, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1 / 2) / 29.1;

  //data from vb.net (contact number & PreviousState)
  // Serial.println(distance1);

  if ((distance1 >= 50 || distance1 <= 0) && PreviousState  == "1")
  {
    cntSend += 1;
    Serial.println("S1-off");
    PreviousState = "0";
    slotRes = "S1";
    sendSMS();
  }


  if (distance1 >= 50 || distance1 <= 0) {
    Serial.println("S1-off");
  }

  else if (distance1 <= 50 && distance1 >= 0) {
    Serial.println ("S1-on");

    cntSend = 0;
  }


  delay(500);



  //PARKING #2
  long duration2, distance2;
  digitalWrite(trigPin2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2 / 2) / 29.1;

  if ((distance2 >= 50 || distance2 <= 0) && PreviousState == "1")
  {
    cntSend += 1;
    Serial.println("S2-off");
    PreviousState = "0";
    slotRes = "S2";
    sendSMS();
  }
  if (distance2 >= 50 || distance2 <= 0) {
    Serial.println("S2-off");
  }
  else if (distance2 <= 50 && distance2 >= 0) {
    Serial.println ("S2-on");
    cntSend = 0;
  }
  delay(500);


  //PARKING #3
  long duration3, distance3;
  digitalWrite(trigPin3, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = (duration3 / 2) / 29.1;


  if ((distance3 >= 50 || distance3 <= 0) && PreviousState == "1") {
    cntSend += 1;
    Serial.println("S3-off");
    PreviousState = "0";
    slotRes = "S3";
    sendSMS();
  }

  if (distance3 >= 50 || distance3 <= 0) {

    Serial.println("S3-off");
  }
  else if (distance3 <= 50 && distance3 >= 0) {

    Serial.println ("S3-on");

    cntSend = 0;
  }
  delay(500);



  //PARKING #4
  long duration4, distance4;
  digitalWrite(trigPin4, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin4, LOW);
  duration4 = pulseIn(echoPin4, HIGH);
  distance4 = (duration4 / 2) / 29.1;


  if ((distance4 >= 50 || distance4 <= 0) && PreviousState == "1") {
    cntSend += 1;
    Serial.println("S4-off");
    PreviousState = "0";
    slotRes = "S4";
    sendSMS();

  }

  if (distance4 >= 50 || distance4 <= 0) {

    Serial.println("S4-off");
  }
  else if (distance4 <= 50 && distance4 >= 0) {

    Serial.println ("S4-on");

    cntSend = 0;
  }
  delay(500);


  //PARKING #5
  long duration5, distance5;
  digitalWrite(trigPin5, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin5, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin5, LOW);
  duration5 = pulseIn(echoPin5, HIGH);
  distance5 = (duration5 / 2) / 29.1;


  if ((distance5 >= 50 || distance5 <= 0) && PreviousState == "1") {
    cntSend += 1;
    Serial.println("S5-off");
    PreviousState = "0";
    slotRes = "S5";
    sendSMS();
  }

  if (distance5 >= 50 || distance5 <= 0) {

    Serial.println("S5-off");
  }
  else if (distance5 <= 50 && distance5 >= 0) {

    Serial.println ("S5-on");

    cntSend = 0;
  }
  delay(500);



  //PARKING #6
  long duration6, distance6;
  digitalWrite(trigPin6, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin6, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin6, LOW);
  duration6 = pulseIn(echoPin6, HIGH);
  distance6 = (duration6 / 2) / 29.1;

  if ((distance6 >= 50 || distance6 <= 0) && PreviousState == "1") {
    cntSend += 1;
    Serial.println("S6-off");
    slotRes = "S6";
    PreviousState = "0";
    sendSMS();
  }

  if (distance6 >= 50 || distance6 <= 0) {

    Serial.println("S6-off");
  }
  else if (distance6 <= 50 && distance6 >= 0) {

    Serial.println ("S6-on");

    cntSend = 0;
  }
  delay(500);


  //PARKING #7
  long duration7, distance7;
  digitalWrite(trigPin7, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin7, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin7, LOW);
  duration7 = pulseIn(echoPin7, HIGH);
  distance7 = (duration7 / 2) / 29.1;


  if ((distance7 >= 50 || distance7 <= 0) && PreviousState == "1") {
    cntSend += 1;
    Serial.println("S7-off");
    PreviousState = "0";
    slotRes = "S7";
    sendSMS();
  }

  if (distance7 >= 50 || distance7 <= 0) {

    Serial.println("S7-off");
  }
  else if (distance7 <= 50 && distance7 >= 0) {

    Serial.println ("S7-on");
    cntSend = 0;
  }
  delay(500);



  //PARKING #8
  long duration8, distance8;
  digitalWrite(trigPin8, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin8, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin8, LOW);
  duration8 = pulseIn(echoPin8, HIGH);
  distance8 = (duration8 / 2) / 29.1;

  if ((distance8 >= 50 || distance8 <= 0) && PreviousState == "1") {
    cntSend += 1;
    Serial.println("S8-off");
    PreviousState = "0";
    slotRes = "S8";
    sendSMS();
  }

  if (distance8 >= 50 || distance8 <= 0) {

    Serial.println("S8-off");
  }
  else if (distance8 <= 50 && distance8 >= 0) {

    Serial.println ("S8-on");

    cntSend = 0;
  }
  delay(500);


  //PARKING #9
  long duration9, distance9;
  digitalWrite(trigPin9, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin9, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin9, LOW);
  duration9 = pulseIn(echoPin9, HIGH);
  distance9 = (duration9 / 2) / 29.1;

  if ((distance9 >= 50 || distance9 <= 0) && PreviousState == "1") {
    cntSend += 1;
    Serial.println("S9-off");
    PreviousState = "0";
    slotRes = "S9";
    sendSMS();
  }

  if (distance9 >= 50 || distance9 <= 0) {

    Serial.println("S9-off");
  }
  else if (distance9 <= 50 && distance9 >= 0) {

    Serial.println ("S9-on");

    cntSend = 0;
  }
  delay(500);


  //PARKING #10
  long duration10, distance10;
  digitalWrite(trigPin10, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin10, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin10, LOW);
  duration10 = pulseIn(echoPin10, HIGH);
  distance10 = (duration10 / 2) / 29.1;

  if ((distance10 >= 50 || distance10 <= 0) && PreviousState == "1") {
    cntSend += 1;
    Serial.println("S10-off");
    PreviousState = "0";
    slotRes = "S10";
    sendSMS();
  }

  if (distance10 >= 50 || distance10 <= 0) {
    Serial.println("S10-off");
  }
  else if (distance10 <= 50 && distance10 >= 0) {

    Serial.println ("S10-on");

    cntSend = 0;
  }
  delay(500);

}




void sendSMS() {

  if (cntSend == 1) {
    SIM900.print("AT+CMGF=1\r");
    delay(1000);
    SIM900.print("AT+CMGS=\"");
    SIM900.print(ContactNumber);
    SIM900.println("\"\r");
    delay(1000);
    SIM900.println("You are about to leave the parking premise of PRIMARK. Please respond YES or NO for confirmation of departure.");
    // End AT command with a ^Z, ASCII code 26
    SIM900.println((char)26);
    delay(5000);
    receiveSMS();
  }

}

String getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void receiveSMS() {
  SIM900.println("AT+CNMI=2,2,0,0,0\r"); // alert our GSM shield and now whenever it will receive message
  ShowSerialData();
  delay(1000);
  //  Serial.print("No");
  //  Serial.print("-");
  //  Serial.println(slotRes);
}

void readSMS() {
  if (SIM900.available() > 0) {
    msgContent = "";
    msgContact = "";
    incomingSMS = SIM900.readString();
    //    Serial.println(incomingSMS);
    //message content
    msgContent = getValue(incomingSMS, ',', 3);
    char displaySMS[msgContent.length() - 1];
    msgContent.toCharArray(displaySMS, msgContent.length() - 1);
    for (int x = 14; x < msgContent.length() - 1; x++) {
      displaySMS[x];
      smsVal = String(smsVal + displaySMS[x]);
    }
    // message contact number
    msgContact = getValue(incomingSMS, ',', 0);
    //    char displayContact[msgContact.length() - 1];
    //    msgContact.toCharArray(displayContact, msgContent.length() - 1);
    contactVal = msgContact.substring(9, 22);

    if (smsVal == "" && contactVal == "") {
      Serial.println("SMS receiver ready");
    } else {
      Serial.println(smsVal);
      Serial.println(contactVal);
      //      Serial.println(smsVal + "-" + slotRes);
    }
    smsVal = "";
    contactVal = "";
  }

}

void deleteSMS() {
  SIM900.print("AT+CMGD=1,4\r");
  delay(1000);
}

void ShowSerialData()
{
  while (SIM900.available() != 0)
    Serial.write(SIM900.read());
}
