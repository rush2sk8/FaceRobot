  #include <Servo.h>
  /****************/
  Servo eyes;
  Servo mouth;
  Servo neckX;
  Servo neckY;
  /***************/
  const int NECKYTHRESHHOLD = 140; 
  const int NECKXTHRESHHOLD = 180;
  const int MOUTHTHRESHHOLD =  80;
  const int EYESTHRESHHOLD  = 150;
  /***************/
  static int i;
  /*END***********/
 
  void setup(){
    Serial.begin(9600);
    pinMode(0,OUTPUT);
    eyes.attach(9);
    mouth.attach(11);
    neckX.attach(2);
    neckY.attach(3);
    i = 0;
  }
  
  void loop(){
 
  test(mouth,MOUTHTHRESHHOLD);
  test(eyes,EYESTHRESHHOLD);
  test(neckY,NECKYTHRESHHOLD); 
  test(neckX,NECKXTHRESHHOLD);
   
  }
  
 static void test(Servo servo,const int t){   
    i++;
    if(i<t)
      servo.write(i);
    else if(i>=t){
    for(int x=i;i>=0;i--){
      servo.write(x);
      delay(10);
    }
    i = 0;
    }
      
    delay(20);
    Serial.println(i);
  
  }
