//#include "stdafx.h"
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <iostream>
#include <windows.h>


#define DEFAULT_PORT	5019





DWORD WINAPI send(LPVOID param) {
	SOCKET connect_sock = *(SOCKET*)param;
	char szBuff[100]="";
	int msg_len;
	while (strcmp(szBuff, "exit")!=0) {
		if (kbhit()) {
			gets_s(szBuff);
			msg_len = send(connect_sock, szBuff, sizeof(szBuff), 0);
			if (msg_len == SOCKET_ERROR) {
				fprintf(stderr, "send() failed with error %d\n", WSAGetLastError());
				WSACleanup();
				return -1;
			}

			if (msg_len == 0) {
				printf("server closed connection\n");
				closesocket(connect_sock);
				WSACleanup();
				return -1;
			}
			if (strcmp(szBuff, "exit") == 0)break;
		}
	}
	printf("1");
	return 0;
}

DWORD WINAPI rec(LPVOID param) {
	SOCKET connect_sock = *(SOCKET*)param;
	char szBuff[100];
	int msg_len;
	while (szBuff != "exit") {
		msg_len = recv(connect_sock, szBuff, sizeof(szBuff), 0);
		if (msg_len == SOCKET_ERROR) {
			fprintf(stderr, "send() failed with error %d\n", WSAGetLastError());
			closesocket(connect_sock);
			WSACleanup();
			return -1;
		}

		if (msg_len == 0) {
			printf("server closed connection\n");
			closesocket(connect_sock);
			WSACleanup();
			return -1;
		}

		printf("Echo from the server %s.\n", szBuff);
		if (strcmp(szBuff, "exit") == 0)break;
	}
	printf("2");
	return 0;
}





int main(int argc, char** argv) {

	char szBuff[100];
	int msg_len;
	//int addr_len;
	struct sockaddr_in server_addr;
	struct hostent* hp;
	SOCKET connect_sock;
	WSADATA wsaData;

	char* server_name = "localhost";
	unsigned short	port = DEFAULT_PORT;
	unsigned int	addr;

	if (argc != 3) {
		printf("echoscln [server name] [port number]\n");
		return -1;
	}
	else {
		server_name = argv[1];
		port = atoi(argv[2]);
	}

	if (WSAStartup(0x202, &wsaData) == SOCKET_ERROR) {
		// stderr: standard error are printed to the screen.
		fprintf(stderr, "WSAStartup failed with error %d\n", WSAGetLastError());
		//WSACleanup function terminates use of the Windows Sockets DLL. 
		WSACleanup();
		return -1;
	}

	if (isalpha(server_name[0]))
		hp = gethostbyname(server_name);
	else {
		addr = inet_addr(server_name);
		hp = gethostbyaddr((char*)&addr, 4, AF_INET);
	}

	if (hp == NULL)
	{
		fprintf(stderr, "Cannot resolve address: %d\n", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	//copy the resolved information into the sockaddr_in structure
	memset(&server_addr, 0, sizeof(server_addr));
	memcpy(&(server_addr.sin_addr), hp->h_addr, hp->h_length);
	server_addr.sin_family = hp->h_addrtype;
	server_addr.sin_port = htons(port);


	connect_sock = socket(AF_INET, SOCK_STREAM, 0);	//TCp socket


	if (connect_sock == INVALID_SOCKET) {
		fprintf(stderr, "socket() failed with error %d\n", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	printf("Client connecting to: %s\n", hp->h_name);

	if (connect(connect_sock, (struct sockaddr*)&server_addr, sizeof(server_addr))
		== SOCKET_ERROR) {
		fprintf(stderr, "connect() failed with error %d\n", WSAGetLastError());
		WSACleanup();
		return -1;
	}
	HANDLE sendTid, recTid;
	sendTid = CreateThread(NULL, 0, send, &connect_sock, 0, NULL);
	recTid = CreateThread(NULL, 0, rec, &connect_sock, 0, NULL);
	WaitForSingleObject(sendTid,INFINITE);
	CloseHandle(sendTid);
	WaitForSingleObject(recTid, INFINITE);
	CloseHandle(recTid);
	/*while (true) {
		printf("input character string:\n");
		gets_s(szBuff);

		msg_len = send(connect_sock, szBuff, sizeof(szBuff), 0);

		if (msg_len == SOCKET_ERROR) {
			fprintf(stderr, "send() failed with error %d\n", WSAGetLastError());
			WSACleanup();
			return -1;
		}

		if (msg_len == 0) {
			printf("server closed connection\n");
			closesocket(connect_sock);
			WSACleanup();
			return -1;
		}

		msg_len = recv(connect_sock, szBuff, sizeof(szBuff), 0);

		if (msg_len == SOCKET_ERROR) {
			fprintf(stderr, "send() failed with error %d\n", WSAGetLastError());
			closesocket(connect_sock);
			WSACleanup();
			return -1;
		}

		if (msg_len == 0) {
			printf("server closed connection\n");
			closesocket(connect_sock);
			WSACleanup();
			return -1;
		}

		printf("Echo from the server %s.\n", szBuff);
		if (strcmp(szBuff,"exit")==0)break;
	}*/
	

	closesocket(connect_sock);
	WSACleanup();
}




