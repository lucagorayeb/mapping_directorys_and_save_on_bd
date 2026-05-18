#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "connection.h" 

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;

    for(i = 0; i < argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int connection(){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    // Abre a conexão com a tabela
    rc = sqlite3_open("teste.db", &db);

    if(rc){
        fprintf(stderr, "Não consegue abrir o banco: %s\n", sqlite3_errmsg(db));
        return (0);
    }/*else{
        //fprintf(stderr, "Conexão estabelecida com sucesso\n");
    }*/
    //sqlite3_close(db);
}

int abre_banco(char database, sqlite3 *db){
    return sqlite3_open(database, &db);
}
