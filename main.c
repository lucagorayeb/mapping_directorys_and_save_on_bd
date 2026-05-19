#include "database.h"

int main(){
    sqlite3 *db;
    char *zErrMsg = 0;
    char *sql;
    char nome_db = "teste.db";

    create(db, zErrMsg, sql, nome_db);
    
}