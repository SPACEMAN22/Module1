const uint8_t motion_led_pin = 12;
const uint8_t motion_pin = 2;
volatile byte motion_led_state = LOW;

const uint8_t button_led_pin = 11;
const uint8_t button_pin = 8;
volatile byte button_led_state = LOW;

const uint8_t button2_led_pin = 10;
const uint8_t button2_pin = 0;
volatile byte button2_led_state = LOW;

const uint8_t timer_led_pin = 13;
volatile byte timer_led_state = LOW;

void setup()
{
	Serial.begin(115200); 

	pinMode(motion_led_pin, OUTPUT);
	pinMode(motion_pin, INPUT_PULLUP);
	PCMSK2 = B00000100;

  	pinMode(button_led_pin, OUTPUT);
	pinMode(button_pin, INPUT_PULLUP);
	PCMSK0 = B00000001; 

	pinMode(button2_led_pin, OUTPUT);
	pinMode(A0, INPUT_PULLUP);
	PCMSK1 = B00000001; 

	PCIFR = B00000000; 
	PCICR = B00000111; 

	pinMode(timer_led_pin, OUTPUT);
	TCCR1A = 0;
	TCCR1B = 0; 
	TCCR1B |= (1 << CS12) | (1 << CS10); 
	TIMSK1 |= (1 << TOIE1); 
}


void loop()
{
}


String getState(byte state)
{
	if (state == HIGH) { return "On"; }
	else if (state == LOW) { return "Off"; }
	else { return "Error"; }
}
                    

ISR(PCINT2_vect)
{
	Serial.print("INTERRUPT: Motion Sensor "); 
	motion_led_state = !motion_led_state; 
	Serial.println(" | STATE: " + getState(motion_led_state)); 
	digitalWrite(motion_led_pin, motion_led_state);
}


ISR(PCINT0_vect)
{
	Serial.print("INTERRUPT: Green Button  ");
	button_led_state = !button_led_state;
	Serial.println(" | STATE: " + getState(button_led_state));
	digitalWrite(button_led_pin, button_led_state);	
}


ISR(PCINT1_vect)
{
	Serial.print("INTERRUPT: Blue Button   ");
	button2_led_state = !button2_led_state;
	Serial.println(" | STATE: " + getState(button2_led_state));
	digitalWrite(button2_led_pin, button2_led_state);
}


ISR(TIMER1_OVF_vect)
{
	Serial.print("INTERRUPT: Timer         ");
	timer_led_state = !timer_led_state;
	Serial.println(" | STATE: " + getState(timer_led_state));
	digitalWrite(timer_led_pin, timer_led_state);
}