#pragma once
#include "home.h"

#define DEFAULT_PORT	5019
#define buffSize 600

int initConnect(char* server_name);
void stateChange(int change);
void closeSocket();
int sendToServer(char szBuff[buffSize], int state);
int recFromServer(char* des ,char* nickName);
void quitRoom();
char* getNickname();
char* getCurrentTime();