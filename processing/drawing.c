import processing.serial.*;

Serial myPort;
int a,b,c,d;
int x,y;
int tmp, tmp2;

float paddlex = 400;
float paddley = 300;

int loopcount=0;
int pwidth = 7;
int pheight = 7;

void setup() 
{
  size(800, 600);
  background(0);
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 115200);
  
}

void draw()
{
  if(myPort.available() > 0) {
    if(myPort.read() == 255){
       tmp = myPort.read();
       tmp2 = myPort.read();
    }
  }
    
    //PROCESSING
    if(tmp>128) tmp -=255; 
    if(tmp2>128) tmp2 -=255; 
    
    println(tmp); println(tmp2); //debug
    if(tmp!= -1) x = tmp*10; 
    if(tmp2!= -1) y = tmp2*10; 
    
    paddlex = 800-(x+400);
    paddley = y+300;  
       
    //DRAWING 
    if(loopcount > 200)
        rect(paddlex, paddley, pwidth, pheight);//paddle
  //  if(loopcount > 5000)
  //      exit();
    
    delay(1);
    loopcount++;
}
