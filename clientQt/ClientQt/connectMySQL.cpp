#include "connectMySQL.h"
#include "lib_static.h"
#include "serverConnect.h"

using namespace std;
MYSQL mysql, * sql_sock;

const char* sql_query;

MYSQL_RES* result;
MYSQL_ROW row;


bool connectMySQL() {
	const char* host = "127.0.0.1";
	const char* user = "root";
	const char* passwd = "0826";
	const char* db = "networking";
	unsigned int sqlport = 3306;
	const char* unix_socket = NULL;
	unsigned long client_flag = 0;

	mysql_init(&mysql);
	if ((sql_sock = mysql_real_connect(&mysql, host, user, passwd, db, sqlport, unix_socket, client_flag)) == NULL)
	{
		return false;
		/*printf("connect failure: \n");
		fprintf(stderr, " %s\n", mysql_error(&mysql));
		exit(1);*/
	}
	else
	{
		return true;
		//fprintf(stderr, "MySQL connect£¡succeed£¡\n");
	}
}

int mysqlRun(char* sql_query) {
	if (mysql_query(&mysql, sql_query) != 0)
	{
		return -1;
		//fprintf(stderr, "insert failure£¡\n");
		//exit(1);
	}
	else
	{
		return 0;
	}
}



void searchByName(char* name, char* temp) {
	string resultS = "<table border = '1'><tr><th></th><th>nick name</th><th>room number</th><th>date</th><th>time</th><th>content</th></tr>";
	string tempS = "";
	char sql_query[999];
	string nickNameS = getNickname();
	char nickName[16];
	strcpy(nickName, &nickNameS[0]);
	// select sql_query
	strcpy(sql_query, "SELECT * FROM ");
	strcat(sql_query, nickName);
	strcat(sql_query, " WHERE sender = '");
	strcat(sql_query, name);
	strcat(sql_query, "'");
	// print sql_query
	//printf(sql_query);
	//printf("\n");



	if (mysql_query(&mysql, sql_query) != 0)
	{
		fprintf(stderr, "insert failure£¡\n");
		exit(1);
	}
	else
	{
		//printf("Success!!!!!!\n");
		if ((result = mysql_store_result(&mysql)) == NULL)
		{
			fprintf(stderr, "save result set failure£¡\n");
			exit(1);
		}
		else
		{
			while (row = mysql_fetch_row(result))
			{
				resultS += "<tr>";
				for (int t = 0; t < mysql_num_fields(result); t++)
				{
					tempS = row[t];
					resultS += "<td>" + tempS + "</td>";
					//printf("%s\t", row[t]);
				}
				resultS += "</tr>";
				//printf("\n");
			}
			resultS += "</table>";
		}

		mysql_free_result(result);
		//stemp = &resultS[0];
		strcpy(temp, &resultS[0]);

	}
}

void searchByContentKeyword(char* keyword, char* temp) {
	string resultS = "<table border = '1'><tr><th></th><th>nick name</th><th>room number</th><th>date</th><th>time</th><th>content</th></tr>";
	string tempS = "";
	char sql_query[999];
	string nickNameS = getNickname();
	char nickName[16];
	strcpy(nickName, &nickNameS[0]);
	// select sql_query
	strcpy(sql_query, "SELECT * FROM ");
	strcat(sql_query, nickName);
	strcat(sql_query, " WHERE content LIKE '%");
	strcat(sql_query, keyword);
	strcat(sql_query, "%'");
	// print sql_query
	//printf(sql_query);
	//printf("\n");

	//strcat(sql_query, );
	//sql_query = "INSERT INTO messages (sender, room_number, timestamp, content) VALUES ('1', '1', '1', '1')";

	if (mysql_query(&mysql, sql_query) != 0)
	{
		fprintf(stderr, "insert failure£¡\n");
		exit(1);
	}
	else
	{
		//printf("Success!!!!!!\n");
		if ((result = mysql_store_result(&mysql)) == NULL)
		{
			fprintf(stderr, "save result set failure£¡\n");
			exit(1);
		}
		else
		{
			while (row = mysql_fetch_row(result))
			{
				resultS += "<tr>";
				for (int t = 0; t < mysql_num_fields(result); t++)
				{
					tempS = row[t];
					resultS += "<td>" + tempS + "</td>";
					//printf("%s\t", row[t]);
				}
				resultS += "</tr>";
				//printf("\n");
			}
			resultS += "</table>";
		}

		mysql_free_result(result);
		//stemp = &resultS[0];
		strcpy(temp, &resultS[0]);

	}
}

void searchBySenderKeyword(char* keyword, char* temp) {
	string resultS = "<table border = '1'><tr><th></th><th>nick name</th><th>room number</th><th>date</th><th>time</th><th>content</th></tr>";
	string tempS = "";
	char sql_query[999];
	string nickNameS = getNickname();
	char nickName[16];
	strcpy(nickName, &nickNameS[0]);
	// select sql_query
	strcpy(sql_query, "SELECT * FROM ");
	strcat(sql_query, nickName);
	strcat(sql_query, " WHERE sender LIKE '%");
	strcat(sql_query, keyword);
	strcat(sql_query, "%'");
	// print sql_query
	//printf(sql_query);
	//printf("\n");

	//strcat(sql_query, );
	//sql_query = "INSERT INTO messages (sender, room_number, timestamp, content) VALUES ('1', '1', '1', '1')";

	if (mysql_query(&mysql, sql_query) != 0)
	{
		fprintf(stderr, "insert failure£¡\n");
		exit(1);
	}
	else
	{
		//printf("Success!!!!!!\n");
		if ((result = mysql_store_result(&mysql)) == NULL)
		{
			fprintf(stderr, "save result set failure£¡\n");
			exit(1);
		}
		else
		{
			while (row = mysql_fetch_row(result))
			{
				resultS += "<tr>";
				for (int t = 0; t < mysql_num_fields(result); t++)
				{
					tempS = row[t];
					resultS += "<td>"+tempS+"</td>";
					//printf("%s\t", row[t]);
				}
				resultS += "</tr>";
				//printf("\n");
			}
			resultS += "</table>";
		}

		mysql_free_result(result);
		//stemp = &resultS[0];
		strcpy(temp,&resultS[0]);

	}
}

void searchByRoomNumber(int n, char* temp) {
	string resultS = "<table border = '1'><tr><th></th><th>nick name</th><th>room number</th><th>date</th><th>time</th><th>content</th></tr>";
	string tempS = "";
	char sql_query[999];
	string nickNameS = getNickname();
	char nickName[16];
	strcpy(nickName, &nickNameS[0]);
	strcpy(sql_query, "SELECT * FROM ");
	strcat(sql_query, nickName);
	strcat(sql_query, " WHERE room_number = ");
	string strTmp = to_string(n);
	strcat(sql_query, &strTmp[0]);
	//printf(sql_query);
	//printf("\n");



	if (mysql_query(&mysql, sql_query) != 0)
	{
		fprintf(stderr, "insert failure£¡\n");
		exit(1);
	}
	else
	{
		//printf("Success!!!!!!\n");
		if ((result = mysql_store_result(&mysql)) == NULL)
		{
			fprintf(stderr, "insert failure£¡\n");
			exit(1);
		}
		else
		{
			while (row = mysql_fetch_row(result))
			{
				resultS += "<tr>";
				for (int t = 0; t < mysql_num_fields(result); t++)
				{
					tempS = row[t];
					resultS += "<td>" + tempS + "</td>";
					//printf("%s\t", row[t]);
				}
				resultS += "</tr>";
				//printf("\n");
			}
			resultS += "</table>";
		}

		mysql_free_result(result);
		//stemp = &resultS[0];
		strcpy(temp, &resultS[0]);

	}
}

void searchByDate(char* date, char* temp) {
	string resultS = "<table border = '1'><tr><th></th><th>nick name</th><th>room number</th><th>date</th><th>time</th><th>content</th></tr>";
	string tempS = "";
	printf("Please input the date in format yyyy-mm-dd");

	char sql_query[999];
	string nickNameS = getNickname();
	char nickName[16];
	strcpy(nickName, &nickNameS[0]);
	// select sql_query
	strcpy(sql_query, "SELECT * FROM ");
	strcat(sql_query, nickName);
	strcat(sql_query, " WHERE msg_date = '");
	strcat(sql_query, date);
	strcat(sql_query, "'");
	// print sql_query
	//printf(sql_query);
	//printf("\n");

	//strcat(sql_query, );
	//sql_query = "INSERT INTO messages (sender, room_number, timestamp, content) VALUES ('1', '1', '1', '1')";

	if (mysql_query(&mysql, sql_query) != 0)
	{
		fprintf(stderr, "insert failure£¡\n");
		exit(1);
	}
	else
	{
		//printf("Success!!!!!!\n");
		if ((result = mysql_store_result(&mysql)) == NULL)
		{
			fprintf(stderr, "save result set failure£¡\n");
			exit(1);
		}
		else
		{
			while (row = mysql_fetch_row(result))
			{
				resultS += "<tr>";
				for (int t = 0; t < mysql_num_fields(result); t++)
				{
					tempS = row[t];
					resultS += "<td>" + tempS + "</td>";
					//printf("%s\t", row[t]);
				}
				resultS += "</tr>";
				//printf("\n");
			}
			resultS += "</table>";
		}

		mysql_free_result(result);
		//stemp = &resultS[0];
		strcpy(temp, &resultS[0]);

	}
}

void searchByDatePeriod(char* startDate, char* endDate, char* temp) {
	string resultS = "<table border = '1'><tr><th></th><th>nick name</th><th>room number</th><th>date</th><th>time</th><th>content</th></tr>";
	string tempS = "";
	printf("Please input the date in format yyyy-mm-dd");

	char sql_query[999];
	string nickNameS = getNickname();
	char nickName[16];
	strcpy(nickName, &nickNameS[0]);
	// select sql_query
	strcpy(sql_query, "SELECT * FROM ");
	strcat(sql_query, nickName);
	strcat(sql_query, " WHERE msg_date >= '");
	strcat(sql_query, startDate);
	strcat(sql_query, "' and msg_date <= '");
	strcat(sql_query, endDate);
	strcat(sql_query, "'");
	// print sql_query
	//printf(sql_query);
	//printf("\n");


	if (mysql_query(&mysql, sql_query) != 0)
	{
		fprintf(stderr, "insert failure£¡\n");
		return;
	}
	else
	{
		//printf("Success!!!!!!\n");
		if ((result = mysql_store_result(&mysql)) == NULL)
		{
			fprintf(stderr, "save result set failure£¡\n");
			return;
		}
		else
		{
			while (row = mysql_fetch_row(result))
			{
				resultS += "<tr>";
				for (int t = 0; t < mysql_num_fields(result); t++)
				{
					tempS = row[t];
					resultS += "<td>" + tempS + "</td>";
					//printf("%s\t", row[t]);
				}
				resultS += "</tr>";
				//printf("\n");
			}
			resultS += "</table>";
		}

		mysql_free_result(result);
		//stemp = &resultS[0];
		strcpy(temp, &resultS[0]);

	}
}