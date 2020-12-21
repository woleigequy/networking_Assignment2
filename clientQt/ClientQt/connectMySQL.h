#pragma once
#include "home.h"




bool connectMySQL();
int mysqlRun(char* sql_query);
void searchBySenderKeyword(char* keyword, char *temp);
void searchByContentKeyword(char* keyword, char* temp);
void searchByName(char* name, char* temp);
void searchByRoomNumber(int n, char* temp);
void searchByDate(char* date, char* temp);
void searchByDatePeriod(char* startDate, char* endDate, char* temp);