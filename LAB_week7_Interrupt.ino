const int MOTORl = 9;
const int MOTORr = 11;
const int Button = 2;
const int EnablePin = 13;
bool BrakeStatus = false;
bool MOTORLeftS = HIGH;
bool MOTORRightS = LOW;
void setup()
{
  pinMode(MOTORl, OUTPUT);
  pinMode(MOTORr, OUTPUT);
  digitalWrite(MOTORl,MOTORLeftS);
  digitalWrite(MOTORr,MOTORRightS);
  digitalWrite(EnablePin,!BrakeStatus);
  attachInterrupt(digitalPinToInterrupt(2), Ebrake, FALLING);
}
void loop()
{
  delay(5000);
  if(!BrakeStatus){
    MOTORLeftS = !MOTORLeftS;
    MOTORRightS = !MOTORRightS;
    digitalWrite(MOTORl,MOTORLeftS);
    digitalWrite(MOTORr,MOTORRightS);
  }
}
void Ebrake(){
	BrakeStatus = !BrakeStatus;
    digitalWrite(EnablePin,!BrakeStatus);
}