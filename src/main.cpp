#include <Arduino.h>
#include <wifi_conn.h>
#include <EEPROM.h>

const IPAddress serverIP(192,168,1,108);
uint16_t serverPort = 56050;
WiFiClient client;
C_WiFiHandle wificonn1;
void setup()
{

    wificonn1.wifiScan();
    wificonn1.wifiConnect();
    delay(1000);

// write your initialization code here
}

void loop()
{
// write your code here
    Serial.println("Try to connect to server");
    if(client.connect(serverIP,serverPort))
    {
        Serial.println("Connect success!");
        client.print("Hello World");
        while (client.connected()||client.available())
        {
            if(client.available())
            {
                String line = client.readStringUntil('\n');
                Serial.println("Readed data");
                Serial.println(line);
                client.write(line.c_str());
            }
        }
    }
    else
    {
        Serial.println("Failed to connect");
        client.stop();
    }
    delay(5000);
}