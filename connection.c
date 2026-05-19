#include "database.h" 

int connection(char *database, sqlite3 *db){
    sqlite3 *db;
    int rc;
    rc = sqlite3_open(database, &db);
    
    if(rc){
        fprintf(stderr, "Não consegue abrir o banco: %s\n", sqlite3_errmsg(db));
        return (1);
    }
}
