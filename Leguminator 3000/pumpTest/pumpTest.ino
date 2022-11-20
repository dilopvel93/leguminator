#include <SoftwareSerial.h>

SoftwareSerial BT(10,11);   
int incomingConfig[20];
bool print = false;
unsigned short charsNum = 0;
int i;

void setup()
{
  BT.begin(9600);       
  Serial.begin(9600);   
}
 
void loop()
{ 
  int currentConfig = 0;
  charsNum = 0;
  while(BT.available() > 0)    
  {
    print = true;
    currentConfig = BT.parseInt();
    //if ((char)currentConfig != ',')
      incomingConfig[charsNum] =  currentConfig;
    Serial.println(charsNum++);
  }

  if (print) {
    i = 0;
    while(incomingConfig[i] != '\0')
      Serial.print(incomingConfig[i++]);  
    print = false;
    Serial.print("\n");
  }
}