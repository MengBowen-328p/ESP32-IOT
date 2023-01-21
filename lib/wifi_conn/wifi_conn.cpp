//
// Created by 15216 on 2023/1/10.
//

#include "wifi_conn.h"
#include <FreeRTOS/FreeRTOS.h>

void C_WiFiHandle::wifiScan(void)
{
//    Init WiFi
    Serial.begin(9600);
    Serial.println("Wifi Init...");
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

//    Scan WiFi around device.
    Serial.println("Start Scan...");
    int wifi_available = WiFi.scanNetworks();
    if (wifi_available == 0)       //No WiFi Found.
    {
        Serial.println("No WiFi Found!");
    }
    else                        //Found available WiFi & Print WiFi list
    {
        Serial.printf("Scanned %d Wifi\n", wifi_available);
        for (int i = 0; i < wifi_available; ++i)
        {
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
        }
    }
}

void C_WiFiHandle::wifiConnect()
{
    //Get SSID & PASSWORD
    Serial.println("Please enter the SSID\n");
    delay(10000);
    if (Serial.available() > 0)
    {
        ssid = Serial.readString();
    }
    Serial.println("Please enter the password\n");
    delay(10000);
    if (Serial.available() > 0)
    {
        passwd = Serial.readString();
    }
    Serial.println("Connecting...\n");
    Serial.printf("Connecting to %s\n", &ssid);
    if (ssid != "")
    {
        WiFi.begin(ssid.c_str(), passwd.c_str());
        while (WiFi.status() != WL_CONNECTED)
        {
            delay(500);
            Serial.print(".");
        }
        Serial.println("");
        Serial.println("WiFi successfully connected\n");
        Serial.println("IP address: \n");
        Serial.println(WiFi.localIP());
    }
    else
    {
        WiFi.begin();
        while (WiFi.status() != WL_CONNECTED)
        {
            delay(500);
            Serial.print(".");
        }
        Serial.println("");
        Serial.println("WiFi successfully connected\n");
        Serial.println("IP address: \n");
        Serial.println(WiFi.localIP());
    }
}

void C_WiFiHandle::deleteStorage()
{
    esp_err_t status;
    delay(500);
    status = esp_wifi_restore();
    if (status == ESP_OK)
    {
        Serial.println("Successfully deleted storage wifi");
    }
    else
    {
        Serial.println("Failed to delete storage wifi");
    }
}



