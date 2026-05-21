#include "database.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;

    for(i = 0; i < argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int faz_query(sqlite3 *db, char *zErrMsg, char *sql, char *nome_db){
    int rc;
    sqlite3_open(nome_db, &db);

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout, "Operação feita com sucesso.\n");
    }
    sqlite3_close(db);
    return 0;
}
