int tmpx;
float p=1;
float k;
float q=0.001;
float r=0.9;
float statetmpx=400;
float newtmpx;

int tmpx2;
float p2=1;
float k2;
float q2=0.001;
float r2=0.9;
float statetmpx2=400;
float newtmpx2;


void setup()
{
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  digitalWrite(10,LOW); //GS1
  digitalWrite(11,LOW); //GS2
  digitalWrite(12,HIGH); //SLEEP 
  Serial.begin(115200);
}

void loop()
{   
    tmpx = analogRead(1);
    p=p+q;
    k=p/(p+r);
    newtmpx=statetmpx+k*(tmpx-statetmpx);
    p=(1-k)*p;
    statetmpx=newtmpx;
    
    tmpx2 = analogRead(2);
    p2=p2+q;
    k2=p2/(p2+r2);
    newtmpx2=statetmpx2+k2*(tmpx2-statetmpx2);
    p2=(1-k2)*p2;
    statetmpx2=newtmpx2;
    
    Serial.print(255, BYTE);
    Serial.print(((int) statetmpx) - 339, BYTE);
    Serial.print(((int) statetmpx2) - 354, BYTE);
    
    //Serial.println(((int) statetmpx) - 339);
    //Serial.println(((int) statetmpx2) - 339);
    
    delay(50);  
}
