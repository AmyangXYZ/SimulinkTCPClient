#include "tcpclient.h"

int initSocket()
{
    WSADATA wsa;
    struct sockaddr_in server;

    server.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        return 1;
    }

    client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (client_socket == INVALID_SOCKET)
    {
        WSACleanup();
        return 2;
    }

    if (connect(client_socket, (SOCKADDR *)&server, sizeof(server)) < 0)
    {
        WSACleanup();
        return 3;
    }
    initFlag = 1;
    return 0;
}

double TCPSend(double inVal)
{
    if (!initFlag)
        initSocket();

    char sendBuf[DEFAULT_BUFLEN];

    snprintf(sendBuf, DEFAULT_BUFLEN, "%.16f", inVal);
    send(client_socket, sendBuf, (int)strlen(sendBuf), 0);

    Sleep(100);
    return inVal;
}

double TCPRecv()
{
    char recvBuf[DEFAULT_BUFLEN];
    int n;
    
    do
    {
        n = recv(client_socket, recvBuf, DEFAULT_BUFLEN, 0);
        if (n > 0)
        {
            return atof(recvBuf);
        }
    } while (n > 0);

    return 0;
}