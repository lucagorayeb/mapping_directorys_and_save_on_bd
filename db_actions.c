#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int abre_banco(char *database, sqlite3 *db){
    return sqlite3_open(database, &db);
}

int fechar_banco(sqlite3 *db){
    return sqlite3_close(db);
}

int executa_querys_no_banco(char *sql, char *database, char *zErrMsg){
    return sqlite3_exec(database, sql, callback, 0, &zErrMsg);
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;

    for(i = 0; i < argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

