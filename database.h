#ifndef DATABASE_H 
#define DATABASE_H

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName);
int faz_query(sqlite3 *db, char *zErrMsg, char *sql, char *nome_db);

#endif
