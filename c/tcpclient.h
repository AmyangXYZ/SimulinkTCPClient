#ifndef _FOO_H
#define _FOO_H

#include "stdio.h"
#include "winsock2.h"
#include "windows.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"
#pragma comment(lib, "ws2_32")

#define SERVER_ADDR "192.168.1.10"
#define SERVER_PORT 10001
#define BUF_LEN 4096
#define DATA_LEN 64

struct Msg {
    char sender[4];
    char receiver[4];
    char type[4];
    char size_row;
    char size_col;
    char data[4082];
} msg_t;

SOCKET client_socket;
int initFlag;

int initSocket();
void TCPSend(double *data, double dataLen, double row, double col);
double TCPRecv();

#endif