    #include <Servo.h>
    #include <SoftwareSerial.h>
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
    SoftwareSerial Genotronex(6,5);
    char data;
    
    void setup(){
      Genotronex.begin(9600);
      Genotronex.println("Bluetooth On please press 1 or 0 blink LED ..");
      pinMode(0,OUTPUT);
      eyes.attach(9);
      mouth.attach(11);
      neckX.attach(2);
      neckX.write(10);
      neckY.attach(3);
      neckY.write(10);
      i = 0;
      data = -1;
    }
    
    void loop(){
   
      if(Genotronex.available()>0){
     
       data = Genotronex.read();
 
       if(data == '0')
         neckX.write(100);
       else if(data == '1')
         neckY.write(100);
      }
    
    delay(100);  
}

