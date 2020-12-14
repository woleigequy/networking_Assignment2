// Server.cpp : create a console application, and include the sources in the project
//
// 1. open the *.c in the Visual C++, then "rebuild all".
// 2. click "yes" to create a project workspace.
// 3. You need to -add the library 'ws2_32.lib' to your project 
//    (Project -> Properties -> Linker -> Input -> Additional Dependencies) 
// 4. recompile the source.

//#include "stdafx.h"

//#include <winsock.h>
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include<Windows.h>
#include<time.h>
#include <conio.h>
#include <iostream>
#include <mysql.h>

using namespace std;

MYSQL mysql, * sql_sock;

const char* sql_query;

MYSQL_RES* result;
MYSQL_ROW row;

#define DEFAULT_PORT	5019
#define buffSize 600

typedef struct threadInfo {
	SOCKET socket;
	sockaddr_in sockaddr;
	HANDLE weakupSignal;
	HANDLE send;
	HANDLE rec;
	char username[16];
	char msgTemp[buffSize];
	int msgSource;
	int roomNumber;
	int index;
};

threadInfo threadList[100];
int threadCounter = 0;

DWORD WINAPI send(LPVOID param1) {
	struct threadInfo param = *(threadInfo*)param1;
	sockaddr_in client_addr = param.sockaddr;
	SOCKET msg_sock = param.socket;
	char szBuff[buffSize];
	int msg_len;
	strcpy(szBuff,"please input your nickname");
	msg_len = send(msg_sock, szBuff, sizeof(szBuff), 0);
	if (msg_len == 0) {
		printf("Client closed connection\n");
		closesocket(msg_sock);
		return -1;
	}
	while (true) {
		WaitForSingleObject(threadList[param.index].weakupSignal, INFINITE);
		strcpy(szBuff, threadList[threadList[param.index].msgSource].msgTemp);


		msg_len = send(msg_sock, szBuff, sizeof(szBuff), 0);
		if (msg_len == 0) {
			printf("Client closed connection\n");
			closesocket(msg_sock);
			return -1;
		}
		if (strcmp(szBuff, "/exit") == 0)break;
	}
	closesocket(msg_sock);
}


int recvProcess(char* strIn,int index) {
	if (strncmp(strIn,").)! 001",8)==0) {
		string charTemp = strIn;
		charTemp = charTemp.substr(8);
		char *ch = &charTemp[0];
		strcpy(threadList[index].username, ch);

		strcpy(threadList[index].msgTemp,"please input roomnumber");
		threadList[index].msgSource = index;
		SetEvent(threadList[index].weakupSignal);
	}
	else if (strncmp(strIn, ").)! 002", 8)==0) {
		return -1;
	}
	else if (strncmp(strIn, ").)! 003", 8)==0) {
		string charTemp = strIn;
		charTemp = charTemp.substr(8);
		char* ch = &charTemp[0];
		threadList[index].roomNumber = atoi(ch);
		strcpy(threadList[index].msgTemp, "you can chat now and input \"\\exit\" you can leave the room");
		threadList[index].msgSource = index;
		SetEvent(threadList[index].weakupSignal);
	}
	else if (strncmp(strIn, ").)! 004", 8)==0) {
		string charTemp = strIn;
		charTemp = charTemp.substr(8);
		char* ch = &charTemp[0];			// message body
		char resultChar[buffSize];
		time_t t = time(NULL);
		struct tm tblock = *localtime(&t);
		char tchar[26];						// timestamp
		asctime_s(tchar,sizeof(tchar),&tblock);
		strcpy(resultChar, tchar);
		strcat(resultChar,threadList[index].username);
		strcat(resultChar, ": ");
		strcat(resultChar, ch);
		strcpy(threadList[index].msgTemp, resultChar);

		sql_query = "INSERT INTO messages (sender, room_number, timestamp, content) VALUES ('1', '1', '1', '1')";

		if (mysql_query(&mysql, sql_query) != 0)       //������ӳɹ�����ʼ��ѯ
		{
			fprintf(stderr, "��ѯʧ�ܣ�\n");
			exit(1);
		}
		else
		{
			if ((result = mysql_store_result(&mysql)) == NULL) //�����ѯ�Ľ��
			{
				fprintf(stderr, "��������ʧ�ܣ�\n");
				exit(1);
			}
			else
			{
				while ((row = mysql_fetch_row(result)) != NULL) //��ȡ������е����ݣ����ص�����һ�С���Ϊ��������ʱ����ǰ���α��ڵ�һ�С�֮ǰ��
				{
					printf("name is %s\t", row[0]);               //��ӡ��ǰ�еĵ�һ�е�����
					printf("age is %s\t\n", row[1]);              //��ӡ��ǰ�еĵڶ��е�����
				}
			}

		}


		for (int i = 0;i<threadCounter;i++) {
			if (i==index) {
				continue;
			}
			else if (threadList[index].roomNumber == threadList[i].roomNumber) {
				threadList[i].msgSource = index;
				SetEvent(threadList[i].weakupSignal);
			}
			else {
				continue;
			}
		}
	}
	else {
		return -1;
	}
	return 0;
}



DWORD WINAPI recv(LPVOID param1) {
	struct threadInfo param = *(threadInfo*)param1;
	sockaddr_in client_addr = param.sockaddr;
	SOCKET msg_sock = param.socket;
	char szBuff[buffSize];
	int msg_len;
	while (true) {
		msg_len = recv(msg_sock, szBuff, sizeof(szBuff), 0);

		if (msg_len == SOCKET_ERROR) {
			fprintf(stderr, "recv() failed with error %d\n", WSAGetLastError());
			return -1;
		}
		if (msg_len == 0) {
			printf("Client closed connection\n");
			closesocket(msg_sock);
			return -1;
		}
		recvProcess(szBuff, param.index);
		printf("Bytes Received: %d, message: %s from %s\n", msg_len, szBuff, inet_ntoa(client_addr.sin_addr));
	}
	closesocket(msg_sock);
}






/*
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

*/



int main(int argc, char** argv) {

	const char* host = "127.0.0.1";  //��Ϊ����Ϊ�������ԣ�������д���Ǳ���IP
	const char* user = "root";		  //�����Ϊ����û�����������MySQL���û���
	const char* passwd = "0826"; //�����Ϊ����û�����
	const char* db = "networking";      //�����Ϊ��Ҫ���ӵ����ݿ������
	unsigned int port = 3306;           //����MySQL�ķ������Ķ˿ڣ������û���޸Ĺ��Ļ�����3306��
	const char* unix_socket = NULL;    //unix_socket����unix�µģ�����Windows�£����ԾͰ�������ΪNULL
	unsigned long client_flag = 0;      //�������һ��Ϊ0

	//const char* sql_query = "select * from test"; //��ѯ���

	//MYSQL_RES* result;                          //����������
	//MYSQL_ROW row;                               //������ǽ�����е�һ��

	mysql_init(&mysql);                          //����֮ǰ����ʹ�������������ʼ��

	if ((sql_sock = mysql_real_connect(&mysql, host, user, passwd, db, port, unix_socket, client_flag)) == NULL) //����MySQL
	{
		printf("����ʧ�ܣ�ԭ����: \n");
		fprintf(stderr, " %s\n", mysql_error(&mysql));
		exit(1);
	}
	else
	{
		fprintf(stderr, "����MySQL�ɹ�����\n");
	}

	if (mysql_query(&mysql, sql_query) != 0)       //������ӳɹ�����ʼ��ѯ
	{
		fprintf(stderr, "��ѯʧ�ܣ�\n");
		exit(1);
	}
	else
	{
		if ((result = mysql_store_result(&mysql)) == NULL) //�����ѯ�Ľ��
		{
			fprintf(stderr, "��������ʧ�ܣ�\n");
			exit(1);
		}
		else
		{
			while ((row = mysql_fetch_row(result)) != NULL) //��ȡ������е����ݣ����ص�����һ�С���Ϊ��������ʱ����ǰ���α��ڵ�һ�С�֮ǰ��
			{
				printf("name is %s\t", row[0]);               //��ӡ��ǰ�еĵ�һ�е�����
				printf("age is %s\t\n", row[1]);              //��ӡ��ǰ�еĵڶ��е�����
			}
		}

	}
	

	char szBuff[buffSize];
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

		threadList[threadCounter].socket = msg_sock;
		threadList[threadCounter].sockaddr = client_addr;
		HANDLE sendTid, autoTid;
		threadList[threadCounter].send = CreateThread(NULL, 0, send, &threadList[threadCounter], 0, NULL);
		threadList[threadCounter].rec = CreateThread(NULL, 0, recv, &threadList[threadCounter], 0, NULL);
		threadList[threadCounter].weakupSignal = CreateEvent(NULL,FALSE,FALSE,NULL);
		threadList[threadCounter].index = threadCounter;

		threadCounter++;
		//autoTid = CreateThread(NULL, 0, autoSend, &param, 0, NULL);
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
	
	mysql_free_result(result);                                //�ͷŽ����
	mysql_close(sql_sock);	                                      //�ر�����
	system("pause");
	exit(EXIT_SUCCESS);
	//EnterCriticalSection();
	//closesocket(msg_sock);
	WSACleanup();
}






