//macros to set the time on program.
#define SECOND 55
#define MINUTE 14
#define HOUR   17

#define NUMBER_OF_TIMERS 2

int ledPin=13;


typedef struct {
  int gpio;
  int hour_on;
  int hour_off;
}timer_t;

int now=0;
int way_back_when=0;
int millisecond=0,minute=MINUTE,second=SECOND,hour=HOUR;




timer_t timers[2] = {
  {3,7,19},
  {4,5,21}
 };


void toggle_led(){
static int blan;
if(blan%2){
  digitalWrite(ledPin,LOW);
}else{
  digitalWrite(ledPin,HIGH);
}
blan++;
}

void check_timers(int h){
  for(int i=0;i<NUMBER_OF_TIMERS;i++){
    if(h>=timers[i].hour_on && h<timers[i].hour_off)
      digitalWrite(timers[i].gpio,LOW);
     else{
      digitalWrite(timers[i].gpio,HIGH);
     }
  }
}

void setup() {
  
Serial.begin(115200);
  // put your setup code here, to run once:
pinMode(ledPin, OUTPUT);

for(int i=0;i<NUMBER_OF_TIMERS;i++)
  pinMode(timers[i].gpio,OUTPUT);

check_timers(hour);
}
 
void loop() {
  char str[30];
  if(now!=way_back_when){
    way_back_when=now;
    millisecond++;
    if(millisecond>=978){
      second++;
           sprintf(str,"hour: %d, minute: %d, second: %d",hour,minute,second);
      Serial.println(str);

      toggle_led();
      millisecond=0;
      if(second>=59){
       /* for(int i=0;i<42;i++){
          while(now==way_back_when)
            now=millis();
          way_back_when = now;
        }*/
        minute++;
        second=0;
        millisecond=0;
        if(minute>=59){
 
          hour++;
          minute=0;
          check_timers(hour);
        }  
      }
    }
  }
  now=millis();
}
