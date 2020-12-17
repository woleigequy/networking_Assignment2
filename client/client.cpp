//#include "stdafx.h"
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <mysql.h>


using namespace std;

MYSQL mysql, * sql_sock;

const char* sql_query;

MYSQL_RES* result;
MYSQL_ROW row;

#define DEFAULT_PORT	5019
#define buffSize 600

int state = 1;
int roomnumber = 0;
char nickName[100] = "";


int strCharProcess(char *str) {
	char charTemp[buffSize];
	switch (state)
	{
	case 1:
		strcpy(nickName, str);

		//create table
		char sql_query[999];

		strcpy(sql_query, "CREATE TABLE IF NOT EXISTS ");
		strcat(sql_query, nickName);
		strcat(sql_query, " (message_id INT NOT NULL AUTO_INCREMENT, sender VARCHAR(50) NOT NULL, room_number INT NOT NULL, msg_date DATE NOT NULL, msg_time TIME NOT NULL, content VARCHAR(666) NOT NULL, PRIMARY KEY(message_id) )ENGINE = InnoDB DEFAULT CHARSET = utf8; ");

		if (mysql_query(&mysql, sql_query) != 0)       //如果连接成功，则开始查询
		{
			fprintf(stderr, "建表失败！\n");
			exit(1);
		}
		else
		{
			printf("Success!!!!!!\n");
		}

		strcpy(charTemp, ").)! 001");
		strcat(charTemp,str);
		strcpy(str ,charTemp);
		state += 2;
		break;
	case 3:
		if (atoi(str)==0|| atoi(str) == -1) {
			printf("please input an positive integer as the roomnumber\n");
			return -1;
		}
		roomnumber = atoi(str);
		strcpy(charTemp, ").)! 003");
		strcat(charTemp, str);
		strcpy(str, charTemp);
		state += 1;
		break;
	case 4:
		strcpy(charTemp, ").)! 004");
		strcat(charTemp, str);
		strcpy(str, charTemp);
		break;
	default:
		break;
	}
	return 0;
}

void searchByName(char* name) {

	char sql_query[999];

	// select sql_query
	strcpy(sql_query, "SELECT * FROM ");
	strcat(sql_query, nickName);
	strcat(sql_query, " WHERE sender = '");
	strcat(sql_query, name);
	strcat(sql_query, "'");
	// print sql_query
	printf(sql_query);
	printf("\n");

	//strcat(sql_query, );
	//sql_query = "INSERT INTO messages (sender, room_number, timestamp, content) VALUES ('1', '1', '1', '1')";

	if (mysql_query(&mysql, sql_query) != 0)       //如果连接成功，则开始查询
	{
		fprintf(stderr, "插入失败！\n");
		exit(1);
	}
	else
	{
		printf("Success!!!!!!\n");
		if ((result = mysql_store_result(&mysql)) == NULL) //保存查询的结果
		{
			fprintf(stderr, "保存结果集失败！\n");
			exit(1);
		}
		else
		{
			while (row = mysql_fetch_row(result)) //读取结果集中的数据，返回的是下一行。因为保存结果集时，当前的游标在第一行【之前】
			{
				for (int t = 0; t < mysql_num_fields(result); t++)
				{
					printf("%s\t", row[t]);
				}
				printf("\n");
			}
		}

		mysql_free_result(result);

	}
}

void searchByContentKeyword(char* keyword) {

	char sql_query[999];

	// select sql_query
	strcpy(sql_query, "SELECT * FROM ");
	strcat(sql_query, nickName);
	strcat(sql_query, " WHERE content LIKE '%");
	strcat(sql_query, keyword);
	strcat(sql_query, "%'");
	// print sql_query
	printf(sql_query);
	printf("\n");

	//strcat(sql_query, );
	//sql_query = "INSERT INTO messages (sender, room_number, timestamp, content) VALUES ('1', '1', '1', '1')";

	if (mysql_query(&mysql, sql_query) != 0)       //如果连接成功，则开始查询
	{
		fprintf(stderr, "插入失败！\n");
		exit(1);
	}
	else
	{
		printf("Success!!!!!!\n");
		if ((result = mysql_store_result(&mysql)) == NULL) //保存查询的结果
		{
			fprintf(stderr, "保存结果集失败！\n");
			exit(1);
		}
		else
		{
			while (row = mysql_fetch_row(result)) //读取结果集中的数据，返回的是下一行。因为保存结果集时，当前的游标在第一行【之前】
			{
				for (int t = 0; t < mysql_num_fields(result); t++)
				{
					printf("%s\t", row[t]);
				}
				printf("\n");
			}
		}

		mysql_free_result(result);

	}
}

void searchBySenderKeyword(char* keyword) {

	char sql_query[999];

	// select sql_query
	strcpy(sql_query, "SELECT * FROM ");
	strcat(sql_query, nickName);
	strcat(sql_query, " WHERE sender LIKE '%");
	strcat(sql_query, keyword);
	strcat(sql_query, "%'");
	// print sql_query
	printf(sql_query);
	printf("\n");

	//strcat(sql_query, );
	//sql_query = "INSERT INTO messages (sender, room_number, timestamp, content) VALUES ('1', '1', '1', '1')";

	if (mysql_query(&mysql, sql_query) != 0)       //如果连接成功，则开始查询
	{
		fprintf(stderr, "插入失败！\n");
		exit(1);
	}
	else
	{
		printf("Success!!!!!!\n");
		if ((result = mysql_store_result(&mysql)) == NULL) //保存查询的结果
		{
			fprintf(stderr, "保存结果集失败！\n");
			exit(1);
		}
		else
		{
			while (row = mysql_fetch_row(result)) //读取结果集中的数据，返回的是下一行。因为保存结果集时，当前的游标在第一行【之前】
			{
				for (int t = 0; t < mysql_num_fields(result); t++)
				{
					printf("%s\t", row[t]);
				}
				printf("\n");
			}
		}

		mysql_free_result(result);

	}
}

void searchByRoomNumber(int n) {

	char sql_query[999];

	// select sql_query
	strcpy(sql_query, "SELECT * FROM ");
	strcat(sql_query, nickName);
	strcat(sql_query, " WHERE room_number = ");
	string strTmp = to_string(n);
	strcat(sql_query, &strTmp[0]);
	//strcat(sql_query, n);
	//strcat(sql_query, "'");
	// print sql_query
	printf(sql_query);
	printf("\n");

	//strcat(sql_query, );
	//sql_query = "INSERT INTO messages (sender, room_number, timestamp, content) VALUES ('1', '1', '1', '1')";

	if (mysql_query(&mysql, sql_query) != 0)       //如果连接成功，则开始查询
	{
		fprintf(stderr, "插入失败！\n");
		exit(1);
	}
	else
	{
		printf("Success!!!!!!\n");
		if ((result = mysql_store_result(&mysql)) == NULL) //保存查询的结果
		{
			fprintf(stderr, "保存结果集失败！\n");
			exit(1);
		}
		else
		{
			while (row = mysql_fetch_row(result)) //读取结果集中的数据，返回的是下一行。因为保存结果集时，当前的游标在第一行【之前】
			{
				for (int t = 0; t < mysql_num_fields(result); t++)
				{
					printf("%s\t", row[t]);
				}
				printf("\n");
			}
		}

		mysql_free_result(result);

	}
}

void searchByDate(char* date) {

	printf("Please input the date in format yyyy-mm-dd");

	char sql_query[999];

	// select sql_query
	strcpy(sql_query, "SELECT * FROM ");
	strcat(sql_query, nickName);
	strcat(sql_query, " WHERE msg_date = '");
	strcat(sql_query, date);
	strcat(sql_query, "'");
	// print sql_query
	printf(sql_query);
	printf("\n");

	//strcat(sql_query, );
	//sql_query = "INSERT INTO messages (sender, room_number, timestamp, content) VALUES ('1', '1', '1', '1')";

	if (mysql_query(&mysql, sql_query) != 0)       //如果连接成功，则开始查询
	{
		fprintf(stderr, "插入失败！\n");
		exit(1);
	}
	else
	{
		printf("Success!!!!!!\n");
		if ((result = mysql_store_result(&mysql)) == NULL) //保存查询的结果
		{
			fprintf(stderr, "保存结果集失败！\n");
			exit(1);
		}
		else
		{
			while (row = mysql_fetch_row(result)) //读取结果集中的数据，返回的是下一行。因为保存结果集时，当前的游标在第一行【之前】
			{
				for (int t = 0; t < mysql_num_fields(result); t++)
				{
					printf("%s\t", row[t]);
				}
				printf("\n");
			}
		}

		mysql_free_result(result);

	}
}

void searchByDatePeriod(char* startDate, char* endDate) {

	printf("Please input the date in format yyyy-mm-dd");

	char sql_query[999];

	// select sql_query
	strcpy(sql_query, "SELECT * FROM ");
	strcat(sql_query, nickName);
	strcat(sql_query, " WHERE msg_date >= '");
	strcat(sql_query, startDate);
	strcat(sql_query, " and msg_date <= ");
	strcat(sql_query, endDate);
	strcat(sql_query, "'");
	// print sql_query
	printf(sql_query);
	printf("\n");

	//strcat(sql_query, );
	//sql_query = "INSERT INTO messages (sender, room_number, timestamp, content) VALUES ('1', '1', '1', '1')";

	if (mysql_query(&mysql, sql_query) != 0)       //如果连接成功，则开始查询
	{
		fprintf(stderr, "插入失败！\n");
		return;
	}
	else
	{
		printf("Success!!!!!!\n");
		if ((result = mysql_store_result(&mysql)) == NULL) //保存查询的结果
		{
			fprintf(stderr, "保存结果集失败！\n");
			return;
		}
		else
		{
			while (row = mysql_fetch_row(result)) //读取结果集中的数据，返回的是下一行。因为保存结果集时，当前的游标在第一行【之前】
			{
				for (int t = 0; t < mysql_num_fields(result); t++)
				{
					printf("%s\t", row[t]);
				}
				printf("\n");
			}
		}

		mysql_free_result(result);

	}
}


void historySearch() {
	int state = 0;
	char szBuff[buffSize] = "";
	char result[100] = "";
	int rnum = 0;
	char startDate[100], endDate[100];
	while (true) {
		int mode = 0;
		printf("please choose your search method\n\"1\" search by Nickname\n\"2\" search by date\n\"3\" search by roomnumber\n\"4\" search by Nickname keyword\n\"5\" search by content keyword\n\"6\" search by date period\n\"7\" exit\n");
		scanf_s("%d", &mode);
		switch (mode) {
		case 1:
			printf("please input entire nickname:\n");
			while (true) {
				if (kbhit()) {
					gets_s(szBuff);
					break;
				}
			}
			gets_s(szBuff);
			searchByName(szBuff);
			break;
		case 2:
			printf("please input which year:\n");
			while (true) {
				if (kbhit()) {
					gets_s(szBuff);
					break;
				}
			}
			gets_s(result);
			strcat(result, "-");
			printf("please input which month:\n");
			gets_s(szBuff);
			strcat(result, szBuff);
			strcat(result, "-");
			printf("please input which day:\n");
			gets_s(szBuff);
			strcat(result, szBuff);
			searchByDate(result);
			break;
		case 3:
			printf("please input roomnumber:\n");
			while (true) {
				if (kbhit()) {
					gets_s(szBuff);
					break;
				}
			}
			scanf_s("%d", &rnum);
			searchByRoomNumber(rnum);
			break;
		case 4:
			printf("please input nickname keyword:\n");
			while (true) {
				if (kbhit()) {
					gets_s(szBuff);
					break;
				}
			}
			gets_s(szBuff);
			searchBySenderKeyword(szBuff);
			break;
		case 5:
			printf("please input content keyword:\n");
			while (true) {
				if (kbhit()) {
					gets_s(szBuff);
					break;
				}
			}
			gets_s(szBuff);
			searchByContentKeyword(szBuff);
			break;
		case 6:
			printf("from:\nplease input which year:\n");
			while (true) {
				if (kbhit()) {
					gets_s(szBuff);
					break;
				}
			}
			gets_s(result);
			strcat(result, "-");
			printf("please input which month:\n");
			gets_s(szBuff);
			strcat(result, szBuff);
			strcat(result, "-");
			printf("please input which day:\n");
			gets_s(szBuff);
			strcat(result, szBuff);
			strcpy(startDate, result);


			printf("to:\nplease input which year:\n");
			gets_s(result);
			strcat(result, "-");
			printf("please input which month:\n");
			gets_s(szBuff);
			strcat(result, szBuff);
			strcat(result, "-");
			printf("please input which day:\n");
			gets_s(szBuff);
			strcat(result, szBuff);
			strcpy(endDate, result);

			searchByDatePeriod(startDate, endDate);
			break;
		case 7:
			return;
		default:
			break;
		}
	}
}




DWORD WINAPI send(LPVOID param) {
	SOCKET connect_sock = *(SOCKET*)param;
	char szBuff[buffSize]="";
	int msg_len;
	while (true) {
		if (kbhit()) {
			gets_s(szBuff);
			if (strcmp(szBuff, "\\exit") == 0) {
				if (state == 1) {
					break;
				}
				else if (state == 3) {
					state -= 2;
					printf("please input your nickname\n");
					continue;
				}
				else if (state == 4) {
					msg_len = send(connect_sock, ").)! 0030", sizeof(szBuff), 0);
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
					state -= 1;
					printf("please input roomnumber\n");
					continue;
				}
			}
			if (strcmp(szBuff,"\\history")==0) {
				if (state==1) {
					printf("please input your nickname first, then search the history\n");
					continue;
				}
				msg_len = send(connect_sock, ").)! 0030", sizeof(szBuff), 0);
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
				if (state==4)
					state -= 1;
				historySearch();
				printf("please input roomnumber:\n");
				continue;
			}
			if (state==4) { 

				// INSERT
				char sql_query[999];

				time_t t = time(NULL);
				struct tm tblock = *localtime(&t);

				// insert sql_query
				strcpy(sql_query, "INSERT INTO ");
				strcat(sql_query, nickName);
				strcat(sql_query, " (sender, room_number, msg_date, msg_time, content) VALUES (");
				strcat(sql_query, "'");
				//username
				strcat(sql_query, nickName);
				strcat(sql_query, "', '");
				//room number
				string strTmp = to_string(roomnumber);
				strcat(sql_query, &strTmp[0]);
				strcat(sql_query, "', '");
				//date
				strTmp = to_string(tblock.tm_year + 1900);
				strcat(sql_query, &strTmp[0]);
				strcat(sql_query, "-");
				strTmp = to_string(tblock.tm_mon + 1);
				strcat(sql_query, &strTmp[0]);
				strcat(sql_query, "-");
				strTmp = to_string(tblock.tm_mday);
				strcat(sql_query, &strTmp[0]);
				strcat(sql_query, "', '");
				//time
				strTmp = to_string(tblock.tm_hour);
				strcat(sql_query, &strTmp[0]);
				strcat(sql_query, ":");
				strTmp = to_string(tblock.tm_min);
				strcat(sql_query, &strTmp[0]);
				strcat(sql_query, ":");
				strTmp = to_string(tblock.tm_sec);
				strcat(sql_query, &strTmp[0]);

				//content
				strcat(sql_query, "', '");
				strcat(sql_query, szBuff);
				strcat(sql_query, "')");

				// print sql_query
				printf(sql_query);
				printf("\n");

				if (mysql_query(&mysql, sql_query) != 0)       //如果连接成功，则开始查询
				{
					fprintf(stderr, "插入失败！\n");
					exit(1);
				}
				else
				{
					printf("Success!!!!!!\n");
				}

			}

			if (strCharProcess(szBuff)==-1) {
				continue;
			}
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
			
				
		}
	}
	//printf("1");
	closesocket(connect_sock);
	return 0;
}

DWORD WINAPI rec(LPVOID param) {
	SOCKET connect_sock = *(SOCKET*)param;
	char szBuff[buffSize];
	int msg_len;
	while (szBuff != "\\exit") {
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

		printf("%s\n", szBuff);
		if (strcmp(szBuff, "\\exit") == 0)break;
		if (state==4&&strcmp(szBuff,"you can chat now and input \"\\exit\" you can leave the room")!=0) {
			char nickname[16];
			string strTemp = szBuff;
			strTemp = strTemp.substr(25);
			char* ch = &strTemp[0];
			puts(ch);
			int i = 0;
			for (i;i<sizeof(ch);i++) {
				if (ch[i] == ':')
					break;
			}
			strncpy(nickname,ch,i);
			strTemp = ch;
			strTemp = strTemp.substr(i + 3);
			ch = &strTemp[0];
			puts(ch);

			// INSERT

			char sql_query[999];

			time_t t = time(NULL);
			struct tm tblock = *localtime(&t);

			// insert sql_query
			strcpy(sql_query, "INSERT INTO ");
			strcat(sql_query, nickName);
			strcat(sql_query, " (sender, room_number, msg_date, msg_time, content) VALUES (");
			strcat(sql_query, "'");
			//username
			strcat(sql_query, nickname);
			strcat(sql_query, "', '");
			//room number
			string strTmp = to_string(roomnumber);
			strcat(sql_query, &strTmp[0]);
			strcat(sql_query, "', '");
			//date
			strTmp = to_string(tblock.tm_year + 1900);
			strcat(sql_query, &strTmp[0]);
			strcat(sql_query, "-");
			strTmp = to_string(tblock.tm_mon + 1);
			strcat(sql_query, &strTmp[0]);
			strcat(sql_query, "-");
			strTmp = to_string(tblock.tm_mday);
			strcat(sql_query, &strTmp[0]);
			strcat(sql_query, "', '");
			//time
			strTmp = to_string(tblock.tm_hour);
			strcat(sql_query, &strTmp[0]);
			strcat(sql_query, ":");
			strTmp = to_string(tblock.tm_min);
			strcat(sql_query, &strTmp[0]);
			strcat(sql_query, ":");
			strTmp = to_string(tblock.tm_sec);
			strcat(sql_query, &strTmp[0]);

			//content
			strcat(sql_query, "', '");
			strcat(sql_query, ch);
			strcat(sql_query, "')");

			// print sql_query
			printf(sql_query);
			printf("\n");

			if (mysql_query(&mysql, sql_query) != 0)       //如果连接成功，则开始查询
			{
				fprintf(stderr, "插入失败！\n");
				exit(1);
			}
			else
			{
				printf("Success!!!!!!\n");
			}

		}
		
	}
	//printf("2");
	return 0;
}




// int argc, char** argv
int main(int argc, char** argv) {

	const char* host = "127.0.0.1";
	const char* user = "root";
	const char* passwd = "0826";
	const char* db = "networking";
	unsigned int sqlport = 3306;
	const char* unix_socket = NULL;
	unsigned long client_flag = 0;

	mysql_init(&mysql);

	if ((sql_sock = mysql_real_connect(&mysql, host, user, passwd, db, sqlport, unix_socket, client_flag)) == NULL) //连接MySQL
	{
		printf("连接失败，原因是: \n");
		fprintf(stderr, " %s\n", mysql_error(&mysql));
		exit(1);
	}
	else
	{
		fprintf(stderr, "连接MySQL成功！！\n");
	}


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

	/*
	if (argc != 3) {
		printf("echoscln [server name] [port number]\n");
		return -1;
	}
	else {
		server_name = argv[1];
		port = atoi(argv[2]);
	}
	*/
	
	
	server_name = "127.0.0.1";
	port = 5019;
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




