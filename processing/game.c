import processing.serial.*;

Serial myPort;
int a,b,c,d;
int x;
int tmp;

int ballx = 0;
int bally = 0;
int prevballx, prevbally, prevpaddlex;
int velx = 3;
int vely = 3;
int paddlex;
int paddley = 570;

int pwidth = 150;
int bwidth = 100;
int bheight = 30;

boolean blockA, blockB, blockC;

int blockAx = 500;
int blockAy = 100;
int blockBx = 400;
int blockBy = 200;
int blockCx = 600;
int blockCy = 300;

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
       if(tmp == 255){
         tmp = myPort.read();
           if(tmp == 255){
             tmp = myPort.read();
           }
       }
    }
  }
    
    //PROCESSING
    if(tmp>128) tmp -=255; 
    println(tmp);//debug
    if(tmp!= -1) x = tmp*10; 
    
 /* if(myPort.available() > 0) {
    tmp = myPort.read();
  }
    
    //PROCESSING
    if(tmp>128) tmp -=255; 
    println(tmp);//debug
    x = tmp*10; */
    ballx += velx;
    bally += vely;
    paddlex = 800-(x+400)-50;
    
    //PADDLE DETECTION
    if(bally < paddley && bally > (paddley-15) && ballx > paddlex && ballx < (paddlex+pwidth))
     vely = -vely; 
    
    //WALL DETECTION
    if(ballx > 790) velx = -velx;  //Right wall
    if(ballx < 0) velx = -velx;  //Left wall
    if(bally < 0) vely = -vely; //Top wall
    if(bally > 600) exit(); //Top wall
    
    
    //BLOCK DETECTION
    if(!blockA) {
    if(bally < (blockAy+3) && bally > (blockAy-3) && ballx > (blockAx) && ballx < (blockAx+bwidth)) {
     vely = -vely; blockA = true;} 
    if(bally < (blockAy+3+bwidth) && bally > (blockAy-3+bwidth) && ballx > (blockAx) && ballx < (blockAx+bwidth)) {
     vely = -vely; blockA = true;}
    if(bally < (blockAy+bwidth) && bally > (blockAy) && ballx > (blockAx-3) && ballx < (blockAx+3)) {
     velx = -velx; blockA = true;}
    if(bally < (blockAy+bwidth) && bally > (blockAy) && ballx > (blockAx-3+bwidth) && ballx < (blockAx+3+bwidth)) {
     velx = -velx; blockA = true;} }
     
     if(!blockB) {
    if(bally < (blockBy+3) && bally > (blockBy-3) && ballx > (blockBx) && ballx < (blockBx+bwidth)) {
     vely = -vely; blockB = true;} 
    if(bally < (blockBy+3+bwidth) && bally > (blockBy-3+bwidth) && ballx > (blockBx) && ballx < (blockBx+bwidth)) {
     vely = -vely; blockB = true;}
    if(bally < (blockBy+bwidth) && bally > (blockBy) && ballx > (blockBx-3) && ballx < (blockBx+3)) {
     velx = -velx; blockB = true;}
    if(bally < (blockBy+bwidth) && bally > (blockBy) && ballx > (blockBx-3+bwidth) && ballx < (blockBx+3+bwidth)) {
     velx = -velx; blockB = true;}}
     
     if(!blockC) {
    if(bally < (blockCy+3) && bally > (blockCy-3) && ballx > (blockCx) && ballx < (blockCx+bwidth)) {
     vely = -vely; blockC = true;} 
    if(bally < (blockCy+3+bwidth) && bally > (blockCy-3+bwidth) && ballx > (blockCx) && ballx < (blockCx+bwidth)) {
     vely = -vely; blockC = true;}
    if(bally < (blockCy+bwidth) && bally > (blockCy) && ballx > (blockCx-3) && ballx < (blockCx+3)) {
     velx = -velx; blockC = true;}
    if(bally < (blockCy+bwidth) && bally > (blockCy) && ballx > (blockCx-3+bwidth) && ballx < (blockCx+3+bwidth)) {
     velx = -velx; blockC = true;} }
       
    //DRAWING 
    
    fill(0);stroke(0);
    
    if(blockA) rect(blockAx, blockAy, bwidth, bheight);//blockA
    if(blockB) rect(blockBx, blockBy, bwidth, bheight);//blockB
    if(blockC) rect(blockCx, blockCy, bwidth, bheight);//blockC
   
    rect(prevpaddlex, paddley, pwidth, 10);//paddle
    rect(prevballx, prevbally, 10, 10);//ball
    
    fill(255);stroke(255);
    
    if(!blockA) rect(blockAx, blockAy, bwidth, bheight);//blockA
    if(!blockB) rect(blockBx, blockBy, bwidth, bheight);//blockB
    if(!blockC) rect(blockCx, blockCy, bwidth, bheight);//blockC
  
    rect(paddlex, paddley, pwidth, 10);//paddle
    rect(ballx, bally, 10, 10);//ball
    
    prevballx = ballx;
    prevbally = bally;
    prevpaddlex = paddlex;
    
    delay(1);
}
