//these macros are here to preset the time to when the device is programmed.
#define SECOND 40
#define MINUTE 51
#define HOUR   17

int ledPin=13;
int pd2=2;
int pd3=3;
int pd4=4;
int pd5=5; 
int pd6=6;
int a6=19;

int now=0;
int way_back_when=0;
int millisecond=0,minute=MINUTE,second=SECOND,hour=HOUR;


void toggle_lights(){
static int blan;
if(blan%2){
  digitalWrite(pd2,LOW);
}else{
  digitalWrite(pd2,HIGH);
}
blan++;
}


void toggle_led(){
static int blan;
if(blan%2){
  digitalWrite(ledPin,LOW);
}else{
  digitalWrite(ledPin,HIGH);
}
blan++;
}


void good_morning(){
  digitalWrite(pd2,LOW);
}

void good_night(){
   digitalWrite(pd2,HIGH);
}

void toggle_water(){
static int blan;
if(blan%2){
  digitalWrite(pd3,HIGH);
}else{
  digitalWrite(pd3,LOW);
}
blan++;
}


void setup() {
  
Serial.begin(9600);
  // put your setup code here, to run once:
pinMode(ledPin, OUTPUT);
pinMode(pd2,OUTPUT);
pinMode(pd3,OUTPUT);

if(hour>=4&&hour<=23){
  good_morning();
}else{
  good_night();
}

digitalWrite(pd3,HIGH);
//toggle_lights();
toggle_water();
//for(int i=0;i<32;i++){
//pinMode(i,OUTPUT);
//}
}
 
void loop() {
  char str[30];
  if(now!=way_back_when){
    way_back_when=now;
    millisecond++;
    if(millisecond>=994){
      sprintf(str,"hour: %d, minute: %d, second: %d",hour,minute,second);
      Serial.println(str);
      second++;
      toggle_led();
      millisecond=0;
      if(second>=59){
       /*comment out following two lines to make the timer operate better*/ 
       //toggle_lights();
       //toggle_water();
        minute++;
        second=0;
        if((minute+1)%15==0){
          toggle_water();
        }
        if(minute>=59){
          hour++;
          minute=0;
          if(hour>=4&&hour<=23){
            good_morning();
          }else{
            good_night();
          }
          if(hour>=23){
            hour=0;
          }
        }

        
      }
    }
  }else{
    delayMicroseconds(200);
  }
  now=millis();

  // put your main code here, to run repeatedly:
  //for(int i=0;i<32;i++){
  //  digitalWrite(pd3,HIGH);
  //}
  //digitalWrite(pd3,HIGH);
 //   digitalWrite(pd2,HIGH);
//  delay(1000);
// digitalWrite(pd3,LOW);
//  digitalWrite(pd2,LOW);
//  delay(1000);

}
