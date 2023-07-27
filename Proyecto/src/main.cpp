#include <StarterKitNB.h>
#include <Arduino.h>
#include "SparkFunLIS3DH.h" 
#include <Wire.h>
pio test --verbose
// Battery measurement parameters
#define PIN_VBAT WB_A0
#define REAL_VBAT_MV_PER_LSB (VBAT_DIVIDER_COMP * VBAT_MV_PER_LSB)
#define VBAT_DIVIDER (0.6F)
#define VBAT_DIVIDER_COMP (1.45F)
#define VBAT_MV_PER_LSB (0.73242188F)
#define NO_OF_SAMPLES 256

uint32_t vbat_pin = PIN_VBAT;

//Sensor

float accelX;
float accelY;
float accelZ;

//Definición de funciones y variables
StarterKitNB sk;
String msg;

LIS3DH SensorTwo(I2C_MODE, 0x18);
//APN

String apn = "m2m.entel.cl";
String user = "entelpcs";
String pw = "entelpcs";

//ThingsBoard

String clientID = "grupo9";
String userName= "99999";
String password = "99999";

void lis3dh_read_data()
{
  // Leer el valor del sensor
  uint8_t cnt = 0;

  Serial.print(" X(g) = ");
  accelX = SensorTwo.readFloatAccelX(); // Asigna el valor del eje X al variable accelX
  Serial.println(accelX, 4);

  Serial.print(" Y(g) = ");
  accelY = SensorTwo.readFloatAccelY(); // Asigna el valor del eje Y al variable accelY
  Serial.println(accelY, 4);

  Serial.print(" Z(g) = ");
  accelZ = SensorTwo.readFloatAccelZ(); // Asigna el valor del eje Z al variable accelZ
  Serial.println(accelZ, 4);
  

  
  float EjeX = accelX; // guarda un float que tiene el valor del eje X

  if (Serial.println(SensorTwo.readFloatAccelY(), 4)>9.8)

  {
    //Prende LED 

  }
}

//Mensaje
String aceleration = "10";

void setup()
{
  sk.Setup(true);
  delay(500);
  sk.UserAPN(apn, user, pw);
  delay(500);
  sk.Connect(apn);
  delay(1000);
  sk.DeviceCheck();   // Consulta sobre las caracteristicas actuales del dispositivo
  delay(1000);
  time_t timeout = millis();
  Serial.begin(115200);
  Wire.begin();
  Serial.println("init");
  while (!Serial)
  {
    if ((millis() - timeout) < 5000)
    {
      delay(100);
    }
    else
    {
      break;
    }
  }
}


void loop() {
  if(!sk.ConnectionStatus())
  {
    sk.Reconnect(apn);
    delay(2000);    // Si se desconecta de NB, se reconecta
  }

  if (!sk.LastMessageStatus)
  {
    sk.ConnectBroker(clientID, userName, password);
    delay(2000);
  }
  
 lis3dh_read_data();
 msg = "{\"accelX\": " + String(accelX, 4) + ", \"accelY\": " + String(accelY, 4) + ", \"accelZ\": " + String(accelZ, 4) + "}";
 Serial.println(msg);
 sk.SendMessage(msg);
 delay(2000);
}