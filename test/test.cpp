// Server.cpp : create a console application, and include the sources in the project
//
// 1. open the *.c in the Visual C++, then "rebuild all".
// 2. click "yes" to create a project workspace.
// 3. You need to -add the library 'ws2_32.lib' to your project 
//    (Project -> Properties -> Linker -> Input -> Additional Dependencies) 
// 4. recompile the source.

//#include "stdafx.h"
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<Windows.h>
#include<time.h>
#include <conio.h>
#include <iostream>

#define DEFAULT_PORT	5019

struct threadParam {
	SOCKET socket;
	sockaddr_in sockaddr;
};


DWORD WINAPI send(LPVOID param1) {
	struct threadParam param = *(threadParam*)param1;
	sockaddr_in client_addr = param.sockaddr;
	SOCKET msg_sock = param.socket;
	char szBuff[100];
	int msg_len;
	while (true) {
		msg_len = recv(msg_sock, szBuff, sizeof(szBuff), 0);

		if (msg_len == SOCKET_ERROR) {
			fprintf(stderr, "recv() failed with error %d\n", WSAGetLastError());
			WSACleanup();
			return -1;
		}

		if (msg_len == 0) {
			printf("Client closed connection\n");
			closesocket(msg_sock);
			return -1;
		}

		printf("Bytes Received: %d, message: %s from %s\n", msg_len, szBuff, inet_ntoa(client_addr.sin_addr));



		msg_len = send(msg_sock, szBuff, sizeof(szBuff), 0);
		if (msg_len == 0) {
			printf("Client closed connection\n");
			closesocket(msg_sock);
			return -1;
		}
		if (strcmp(szBuff, "exit") == 0)break;
	}
	closesocket(msg_sock);
}

DWORD WINAPI autoSend(LPVOID param1) {
	struct threadParam param = *(threadParam*)param1;
	sockaddr_in client_addr = param.sockaddr;
	SOCKET msg_sock = param.socket;
	char szBuff[100] = "check";
	int msg_len;
	for (int i=0; i < 100; i++) {
		msg_len = send(msg_sock, szBuff, sizeof(szBuff), 0);
		if (msg_len == 0) {
			printf("Client closed connection\n");
			closesocket(msg_sock);
			return -1;
		}
		Sleep(500);
	}
	*szBuff = (char)"exit";
	msg_len = send(msg_sock, szBuff, sizeof(szBuff), 0);
	if (msg_len == 0) {
		printf("Client closed connection\n");
		closesocket(msg_sock);
		return -1;
	}

}



int main(int argc, char** argv) {

	char szBuff[100];
	int msg_len;
	int addr_len;
	struct sockaddr_in local, client_addr;

	SOCKET sock, msg_sock;
	WSADATA wsaData;

	if (WSAStartup(0x202, &wsaData) == SOCKET_ERROR) {
		// stderr: standard error are printed to the screen.
		fprintf(stderr, "WSAStartup failed with error %d\n", WSAGetLastError());
		//WSACleanup function terminates use of the Windows Sockets DLL. 
		WSACleanup();
		return -1;
	}
	// Fill in the address structure
	local.sin_family = AF_INET;
	local.sin_addr.s_addr = INADDR_ANY;
	local.sin_port = htons(DEFAULT_PORT);

	sock = socket(AF_INET, SOCK_STREAM, 0);	//TCp socket


	if (sock == INVALID_SOCKET) {
		fprintf(stderr, "socket() failed with error %d\n", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	if (bind(sock, (struct sockaddr*)&local, sizeof(local)) == SOCKET_ERROR) {
		fprintf(stderr, "bind() failed with error %d\n", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	//waiting for the connections

	while (true) {
		if (listen(sock, 5) == SOCKET_ERROR) {
			fprintf(stderr, "listen() failed with error %d\n", WSAGetLastError());
			WSACleanup();
			return -1;
		}


		printf("Waiting for the connections ........\n");

		addr_len = sizeof(client_addr);
		msg_sock = accept(sock, (struct sockaddr*)&client_addr, &addr_len);
		if (msg_sock == INVALID_SOCKET) {
			fprintf(stderr, "accept() failed with error %d\n", WSAGetLastError());
			WSACleanup();
			return -1;
		}

		printf("accepted connection from %s, port %d\n",
			inet_ntoa(client_addr.sin_addr),
			htons(client_addr.sin_port));

		struct threadParam param;
		param.socket = msg_sock;
		param.sockaddr = client_addr;
		HANDLE sendTid, autoTid;
		sendTid = CreateThread(NULL, 0, send, &param, 0, NULL);
		autoTid = CreateThread(NULL, 0, autoSend, &param, 0, NULL);
		//WaitForSingleObject(sendTid, INFINITE);
		//CloseHandle(sendTid);
		//WaitForSingleObject(autoTid, INFINITE);
		//CloseHandle(autoTid);
	}
	/*
	if (listen(sock, 5) == SOCKET_ERROR) {
		fprintf(stderr, "listen() failed with error %d\n", WSAGetLastError());
		WSACleanup();
		return -1;
	}


	printf("Waiting for the connections ........\n");

	addr_len = sizeof(client_addr);
	msg_sock = accept(sock, (struct sockaddr*)&client_addr, &addr_len);
	if (msg_sock == INVALID_SOCKET) {
		fprintf(stderr, "accept() failed with error %d\n", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	printf("accepted connection from %s, port %d\n",
		inet_ntoa(client_addr.sin_addr),
		htons(client_addr.sin_port));

	struct threadParam param;
	param.socket = msg_sock;
	param.sockaddr = client_addr;
	HANDLE sendTid, autoTid;
	sendTid = CreateThread(NULL, 0, send, &param, 0, NULL);
	autoTid = CreateThread(NULL, 0, autoSend, &param, 0, NULL);
	WaitForSingleObject(sendTid, INFINITE);
	CloseHandle(sendTid);
	WaitForSingleObject(autoTid, INFINITE);
	CloseHandle(autoTid);
	*/
	/*
	while (true) {
		msg_len = recv(msg_sock, szBuff, sizeof(szBuff), 0);

		if (msg_len == SOCKET_ERROR) {
			fprintf(stderr, "recv() failed with error %d\n", WSAGetLastError());
			WSACleanup();
			return -1;
		}

		if (msg_len == 0) {
			printf("Client closed connection\n");
			closesocket(msg_sock);
			return -1;
		}

		printf("Bytes Received: %d, message: %s from %s\n", msg_len, szBuff, inet_ntoa(client_addr.sin_addr));

		

		msg_len = send(msg_sock, szBuff, sizeof(szBuff), 0);
		if (msg_len == 0) {
			printf("Client closed connection\n");
			closesocket(msg_sock);
			return -1;
		}
		if (strcmp(szBuff, "exit") == 0)break;
	}
	*/
	
	
	//EnterCriticalSection();
	//closesocket(msg_sock);
	WSACleanup();
}






