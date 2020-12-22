#pragma once
#include "home.h"
#include <string>

using namespace std;

#define DEFAULT_PORT	5019
#define buffSize 600

int initConnect(char* server_name);
void stateChange(int change);
void closeSocket();
int sendToServer(char szBuff[buffSize], int state);
int recFromServer(char* des ,char* nickName);
void quitRoom();
//char* getNickname();
string getNickname();
string getCurrentTime();