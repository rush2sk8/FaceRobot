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
    char letter;
    /******END******/
   
    void setup(){
      Serial.begin(9600);
      pinMode(0,OUTPUT);
      eyes.attach(9);
      mouth.attach(11);
      neckX.attach(2);
      neckX.write(10);
      neckY.attach(3);
      neckY.write(10);
      Serial.flush();
      for(int i=0;i<70;i++)Serial.println();
    }
    
    void loop(){
     
      Serial.println("x = Move Head on X Axis, y = Move Head on Y Axis, e = Move Eyes, m = Move Mouth");
      
      while(Serial.available() == 0);{
        letter = Serial.read();
        while(Serial.available()>0){Serial.read();}
      }
  
      if(letter == 'x')
         moveServo("Enter value to move head on X Axis",NECKXTHRESHHOLD,neckX);  
        
      else if(letter == 'y')
         moveServo("Enter value to move head on Y Axis",NECKYTHRESHHOLD,neckY);
       
      else if(letter == 'e')
         moveServo("Enter value to move eyes",EYESTHRESHHOLD, eyes);
 
      else if(letter == 'm')
         moveServo("Enter value to move mouth",MOUTHTHRESHHOLD,mouth);
    
     for(int i=0;i<70;i++)Serial.println();
 
  }
  
  void moveServo(String data, const int num, Servo servo){
    
      Serial.println(data);
          while(Serial.available() == 0);{
            int i = Serial.parseInt();
             
             if(i<num)
                servo.write(i);
             else{
                Serial.println("Not a vaild value");
                delay(1000); 
           }
            while(Serial.available()>0){Serial.read();}
          }
        
  }
