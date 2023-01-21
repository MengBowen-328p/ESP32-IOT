//
// Created by 15216 on 2023/1/10.
//    String ssid = "TP-LINK_8652";
//    String passwd = "410901200307140517";
//

#ifndef ESP32_IOT_WIFI_CONN_H
#define ESP32_IOT_WIFI_CONN_H
#include <Arduino.h>
#include <WiFiMulti.h>
#include <WiFi.h>
#include <esp_wifi.h>

class C_WiFiHandle
{
public:
    String ssid;
    String passwd;
    void wifiScan(void);
    void wifiConnect(void);
    void deleteStorage(void);
};
#endif //ESP32_IOT_WIFI_CONN_H
