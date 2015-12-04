
#include <IRremote.h>

int RECV_PIN = 11;
int rc=0;
int gc=0;
int bc=0;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(5, OUTPUT);//Azul
  pinMode(6, OUTPUT);//Verde
  pinMode(7, OUTPUT);//Rojo
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    Elegirluz();
    irrecv.resume(); // Receive the next value
  }
  delay(500);//jugar con este
}
void setColor(int b,int g ,int r){
digitalWrite(5,b);
digitalWrite(6,g);
digitalWrite(7,r);

}

void aumentarc(){
 rc=rc+1;
 if(rc>=253){rc=0;}
}

void aumentarbc(){
 bc=bc+1;
 if(bc>=253){bc=0;}
}
void aumentargc(){
 gc=gc+1;
 if(gc>=253){gc=0;}
}


void Elegirluz() {

  switch (results.value) {

    case 0xFD08F7:  setColor(255,0,0); break;//blue 1
    case 0xFD8877:setColor(0,255,0);    break;//green
    case 0xFD48B7:  setColor(0,0,255);    break;//red
    case 0xFD28D7: setColor(0,255,255);   break;//
    case 0xFDA857: setColor(255,0,255); break;//purple
    case 0xFD6897: setColor(255,255,255);   break;//white
    case 0xFD00FF: setColor(0,0,0);    break;//off
    case 0xFD9867: setColor(255,255,0);break;//amarillo
    case 0xFD20DF: aumentarc();setColor(bc,gc,rc);break;
    case 0xFDA05F: aumentargc();setColor(bc,gc,rc);break;
    case 0xFD609F: aumentarbc();setColor(bc,gc,rc);break;
    case 0xFD18E7: setColor(255,25,40);    break;
    case 0xFD40BF: rc=0;bc=0;gc=0; break;



    

    default:
      Serial.println(" other button   ");

  }
  delay (500);




}
