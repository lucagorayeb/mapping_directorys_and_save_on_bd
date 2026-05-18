#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "connection.h"

int create(sqlite3 *db,  char *zErrMsg, char *sql){
    int rc;
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout, "Tabela criada com sucesso\n");
    }
    sqlite3_close(db);
    return 0;
}