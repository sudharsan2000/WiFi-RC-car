#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
int in1 =5;  // 1
int in2 =4; //2
int in3 =12; //6
int in4 =13; //7

int led=LED_BUILTIN;
void idle();
void forward();
void left();
void right();
void back();
String sendhtml();
 ESP8266WebServer server(80);
void setup() 
{
  pinMode( in1 , OUTPUT);
  pinMode( in2 , OUTPUT);
  pinMode( in3 , OUTPUT);
  pinMode( in4 , OUTPUT);
  char* ssid="HP";
  char* pass="";
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,pass);
  while( WiFi.status() != WL_CONNECTED)
  {
    Serial.println('.');
    delay(1000);
  }
  Serial.println("Connected. IP:"); Serial.print( WiFi.localIP() );

  
  server.on("/",idle);
  server.on("/forward" ,forward);
  server.on("/back" ,back);                 // domains
  server.on("/left" ,left);
  server.on("/right" ,right);
  server.begin();
    server.onNotFound([](){
    server.send(404, "text/plain", "404: Not found");
    
    } );
//    server.println("Welcome to LED toogle");
}

void loop() 
{
  
server.handleClient();
}
void idle()
{
  Serial.println( "idle" );
   server.send( 200,"text/html", sendhtml_idle() );     ///////////////sendig to code server
    digitalWrite(in1,LOW);//IDLE
      digitalWrite(in1,LOW);  
      digitalWrite(in3,LOW);
      digitalWrite(in3,LOW);
       digitalWrite(led,LOW);
}
void forward()
{
  Serial.println("forward");
  server.send(200,"text/html", sendhtml_fwd() );
    digitalWrite(in1,HIGH);   //FORWARD
      digitalWrite(in2,LOW);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
      digitalWrite(led,HIGH);
}
void left()
{
  Serial.println ( " left" );
  server.send(200,"text/html",sendhtml_left() );
    digitalWrite(in1,HIGH);//LEFT
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,LOW);
      digitalWrite(led,HIGH);
}
void right()
{
  Serial.println ( " right " );
  server.send(200,"text/html",sendhtml_right() );
   digitalWrite(in1,LOW);//RIGHT 
      digitalWrite(in2,LOW);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
      digitalWrite(led,HIGH);
}
void back()
{
  Serial.println ( " back" );
  server.send(200,"text/html",sendhtml_back() );
      digitalWrite(in1,LOW);//BACK 
      digitalWrite(in2,HIGH);  
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      digitalWrite(led,HIGH);
}
String sendhtml_idle( )
{
  String vtr;
 
   vtr= "<html>\n";
  vtr  +=     " <body> <H1> Press button to toogle </H1>\n";
  vtr  +=     " <H1> IDLE </H1> \n";
  vtr  +=     " </body>";
  vtr  +=     "</html>";
  return vtr;
}
String sendhtml_fwd( )
{
  String vtr;
 
   vtr= "<html>\n";
  vtr  +=     " <body> <H1> Press button to toogle </H1>\n";
  vtr  +=     " <H1> FORWWARD </H1> \n";
  vtr  +=     " </body>";
  vtr  +=     "</html>";
  return vtr;
}
String sendhtml_left( )
{
  String vtr;
 
   vtr= "<html>\n";
  vtr  +=     " <body> <H1> Press button to toogle </H1>\n";
  vtr  +=     " <H1> LEFT </H1> \n";
  vtr  +=     " </body>";
  vtr  +=     "</html>";
  return vtr;
}
String sendhtml_right( )
{
  String vtr;
 
   vtr= "<html>\n";
  vtr  +=     " <body> <H1> Press button to toogle </H1>\n";
  vtr  +=     " <H1> RIGHT</H1> \n";
  vtr  +=     " </body>";
  vtr  +=     "</html>";
  return vtr;
}
String sendhtml_back( )
{
  String vtr;
 
   vtr= "<html>\n";
  vtr  +=     " <body> <H1> Press button to toogle </H1>\n";
  vtr  +=     " <H1> BACK </H1> \n";
  vtr  +=     " </body>";
  vtr  +=     "</html>";
  return vtr;
}
