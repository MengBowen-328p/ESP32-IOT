//
// Created by 15216 on 2023/1/11.
//

#ifndef ESP32_IOT_TCP_TRANS_H
#define ESP32_IOT_TCP_TRANS_H

#include <Arduino.h>

class C_TCPTrans
{
private:
    String server_ip;
    String server_port;
public:
    void initTcp(void);
};
#endif //ESP32_IOT_TCP_TRANS_H
