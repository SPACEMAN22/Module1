int sensePin = A0;  
int sensorInput;    
double temp;  

void setup()
{
  pinMode(4, OUTPUT);
  Serial.begin(9600);                      
}

void loop()
{
  sensorInput = analogRead(A0);    
  temp = (double)sensorInput / 1024;       
  temp = temp * 5;                 
  temp = temp - 0.5;               
  temp = temp * 100;               
 
  Serial.print("Current Temp:-  ");
  Serial.println(temp);
  
 
  
  if(temp>30){
    digitalWrite(4,HIGH);
    delay(500);
    digitalWrite(4,LOW);
    delay(500);
  }
}