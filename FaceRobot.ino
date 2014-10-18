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
      Genotronex.println("hellow world");
      pinMode(0,OUTPUT);
      eyes.attach(9);
      mouth.attach(11);
      neckX.attach(2);
      neckX.write(30);
      neckY.attach(3);
      neckY.write(10);
      i = 0;

    }
    
    void loop(){
   
      if(Genotronex.available()>0){
     
       data = Genotronex.read();
       Serial.println(data);
   Genotronex.println("hellow world");
    
       delay(100);  
}
    }
