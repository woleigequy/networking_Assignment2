#include "connectMySQL.h"

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