 #ifndef DB_ACTIONS_H
 #define DB_ACTIONS_H

 #include <sqlite3.h>

 int abre_banco(char *database, sqlite3 *db);
 int fechar_banco(sqlite3 *db);
 int executa_querys_no_banco(char *sql, char *database, char *zErrMsg);
 int callback(void *NotUsed, int argc, char **argv, char **azColName);

 #endif