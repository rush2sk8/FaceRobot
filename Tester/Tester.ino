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
      neckX.write(5);
      neckY.attach(3);
      neckY.write(5);
      Serial.flush();
      for(int i=0;i<70;i++)Serial.println();
    }
    
    void loop(){
     
      Serial.println("x = Move Head on X Axis, y = Move Head on Y Axis, e = Move Eyes, m = Move Mouth");
      
      while(Serial.available() == 0);{
        letter = Serial.read();
        while(Serial.available()>0){Serial.read();}
      }
  
      if(letter == 'x'){
          Serial.println("Enter value to move head on X Axis");
          while(Serial.available() == 0);{
            int i = Serial.parseInt();
             
             if(i<NECKXTHRESHHOLD)
                neckX.write(i);
             else
                Serial.println("Not a vaild value");
              
            while(Serial.available()>0){Serial.read();}
          }
      }
      else if(letter == 'y'){
          Serial.println("Enter value to move head on Y Axis");
          while(Serial.available() == 0);{
            int i = Serial.parseInt();
             
             if(i<NECKYTHRESHHOLD)
                neckY.write(i);
             else
                Serial.println("Not a vaild value");
              
            while(Serial.available()>0){Serial.read();}
          }
      }
      else if(letter == 'e'){
          Serial.println("Enter value to move eyes");
          while(Serial.available() == 0);{
            int i = Serial.parseInt();
             
             if(i<EYESTHRESHHOLD)
                eyes.write(i);
             else
                Serial.println("Not a vaild value");
              
            while(Serial.available()>0){Serial.read();}
          }
      }
      else if(letter == 'm'){
          Serial.println("Enter value to move mouth");
          while(Serial.available() == 0);{
            int i = Serial.parseInt();
             
             if(i<MOUTHTHRESHHOLD)
                mouth.write(i);
             else
                Serial.println("Not a vaild value");
              
            while(Serial.available()>0){Serial.read();}
          }
      }     
   
   for(int i=0;i<70;i++)Serial.println();
 
  }
