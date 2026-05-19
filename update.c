#include "database.h"

int update(sqlite3 *db, char *zErrMsg, char *sql, char *nome_db){
    int rc;
    connection(nome_db, db);

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout, "Tabela atualizada com sucesso\n");
    }
    sqlite3_close(db);
    return 0;
}