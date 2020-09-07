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

void TCPSend(double *data, double dataLen, double row, double col)
{
    if (!initFlag)
        initSocket();

    char sendBuf[BUF_LEN]="", tmpStr[16]="";
    
    for(int i=0;i<dataLen;i++)
    {
        snprintf(tmpStr, 16, "%.4f,", data[i]);
        strcat(sendBuf,tmpStr);
    }
    send(client_socket, sendBuf, (int)strlen(sendBuf), 0);

    Sleep(50);
}

double TCPRecv()
{
    char recvBuf[BUF_LEN];
    int n;
    
    do
    {
        n = recv(client_socket, recvBuf, BUF_LEN, 0);
        if (n > 0)
        {
            return atof(recvBuf);
        }
    } while (n > 0);

    return 0;
}