#include "serverConnect.h"
#include "lib_static.h"
#include "connectMySQL.h"


using namespace std;

//int state = 0;
int roomnumber;
char nickName[100];
SOCKET connect_sock;

int initConnect(char* server_name) {
	roomnumber = 0;
	strcpy(nickName, "");
	struct sockaddr_in server_addr;
	struct hostent* hp;
	//SOCKET connect_sock;
	WSADATA wsaData;

	unsigned short	port = DEFAULT_PORT;
	unsigned int	addr;
	if (WSAStartup(0x202, &wsaData) == SOCKET_ERROR) {
		// stderr: standard error are printed to the screen.
		fprintf(stderr, "WSAStartup failed with error %d\n", WSAGetLastError());
		//WSACleanup function terminates use of the Windows Sockets DLL. 
		WSACleanup();
		return -2;
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
	return 0;
}


int strCharProcess(char* str, int state) {
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

		if (mysqlRun(sql_query) != 0)
		{
			return -1;
			//fprintf(stderr, "create table failure\n");
			//exit(1);
		}
		else
		{
			//printf("Success!!!!!!\n");
		}

		strcpy(charTemp, ").)! 001");
		strcat(charTemp, str);
		strcpy(str, charTemp);
		//state += 2;
		break;
	case 3:
		//roomnumber = atoi(str);
		strcpy(charTemp, ").)! 003");
		strcat(charTemp, str);
		strcpy(str, charTemp);
		//state += 1;
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

int sendToServer(char *szBuff,int state) {
	int msg_len = 0;
	bool flag = true;
	if (state == 5) {
		flag = false;
		state -= 2;
	}
			
			if (state == 4) {

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
				//printf(sql_query);
				//printf("\n");

				if (mysqlRun(sql_query) != 0)
				{
					//fprintf(stderr, "insert failure£¡\n");
					//exit(1);
					return -1;
				}
				else
				{
					//printf("Success!!!!!!\n");
				}

			}

			if (strCharProcess(szBuff,state) != -1) {
				msg_len = send(connect_sock, szBuff, buffSize, 0);
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
			if (state != 4&& flag) {
				char temp[buffSize];
				recv(connect_sock,temp,buffSize,0);
				strcpy(temp,"");
			}
	return 0;
}


int recFromServer(char* des, char* nickNameDes) {
	
		char szBuff[buffSize];
		int msg_len;
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
		if (strcmp(szBuff, "you can chat now and input \"\\exit\" you can leave the room") == 0)
			return 0;
			char nickname[16];
			string strTemp = szBuff;
			strTemp = strTemp.substr(25);
			char* ch = &strTemp[0];
			//puts(ch);
			int i = 0;
			for (i; i < sizeof(ch); i++) {
				if (ch[i] == ':')
					break;
			}
			strncpy(nickname, ch, i+1);
			nickname[i+1] = '\0';
			strTemp = ch;
			strTemp = strTemp.substr(i + 3);
			ch = &strTemp[0];
			strcpy(des, ch);
			strcpy(nickNameDes, nickname);
			//puts(ch);

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
			//printf(sql_query);
			//printf("\n");

			if (mysqlRun(sql_query) != 0)
			{
				//fprintf(stderr, "insert failure\n");
				//exit(1);
				return -1;
			}
			

		
		return 0;
	
}



void closeSocket() {
	closesocket(connect_sock);
}


void stateChange(int change) {
	//state = change;
}

string getNickname() {
	string result = nickName;
	return result;
}

string getCurrentTime() {
	time_t t = time(NULL);
	struct tm tblock = *localtime(&t);
	char tchar[26];						// timestamp
	asctime_s(tchar, sizeof(tchar), &tblock);
	strncpy(tchar,tchar,25);
	string tcharS = tchar;
	return tcharS;
}



