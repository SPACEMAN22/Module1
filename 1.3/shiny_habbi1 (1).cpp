const uint8_t motion_led_pin = 12;
const uint8_t motion_pin = 2;

const uint8_t button_led_pin = 8;
const uint8_t button_pin = 3;


void setup()
{
	Serial.begin(9600);
  
    
	pinMode(motion_pin, INPUT);
  	pinMode(button_pin, INPUT);
  
  	
	pinMode(motion_led_pin, OUTPUT);
  	pinMode(button_led_pin, OUTPUT);
  	
  	
  	attachInterrupt(digitalPinToInterrupt(motion_pin), detectMotion, CHANGE);
	attachInterrupt(digitalPinToInterrupt(button_pin), detectPress, CHANGE);
}


void loop()
{
  	
  	delay(100);
}
                    

void detectMotion()
{
  	
  	if (digitalRead(motion_pin) == HIGH)
  	{
		
    	Serial.print("Motion:- Detected! ");
      
        
     	digitalWrite(motion_led_pin, HIGH);

     	
     	Serial.println("| LED:- ON!");
    }
    
  	
  	else 
    {
    	
    	Serial.print("Motion:- Undetected! ");
      
        
     	digitalWrite(motion_led_pin, LOW);

     	
     	Serial.println("| LED:- OFF!");
    }
}


void detectPress()
{
  	
  	if (digitalRead(button_pin) == HIGH)
  	{
		
    	Serial.print("Button:- Pressed! ");
      
        
     	digitalWrite(button_led_pin, HIGH);

     	
     	Serial.println("| LED:- ON!");
    }
    
  	
  	else 
    {
    	
    	Serial.print("Button:- Released! ");
      
        
     	digitalWrite(button_led_pin, LOW);

     	
     	Serial.println("| LED:- OFF!");
    }
}