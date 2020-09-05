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
#define DEFAULT_BUFLEN 512

SOCKET client_socket;
int initFlag;
int initSocket();
double TCPSend(double);
double TCPRecv();

#endif