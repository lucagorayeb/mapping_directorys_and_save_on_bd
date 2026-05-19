#ifndef DATABASE_H
#define DATABASE_H
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int connection(char *database, sqlite3 *db);
int callback(void *NotUsed, int argc, char **argv, char **azColName);
int create(sqlite3 *db, char *zErrMsg, char *sql, char *nome_db);
int read(sqlite3 *db, char *zErrMsg, char *sql, char *nome_db);
int update(sqlite3 *db, char *zErrMsg, char *sql, char *nome_db);
int drop(sqlite3 *db, char *zErrMsg, char *sql, char *nome_db);

#endif