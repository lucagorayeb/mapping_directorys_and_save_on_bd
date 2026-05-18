#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;

    for(i = 0; i < argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    // Abre a conexão com a tabela

    rc = sqlite3_open("teste.db", &db);

    if(rc){
        fprintf(stderr, "Não consegue abrir o banco: %s\n", sqlite3_errmsg(db));
        return (0);
    }else{
        fprintf(stderr, "Conexão estabelecida com sucesso\n");
    }
    //sqlite3_close(db);

    // Comando SQL 
    //sql = "CREATE TABLE teste(""id INTEGER PRIMARY KEY," "nome TEXT NOT NULL"")";
    //sql = "INSERT INTO teste(nome)" "VALUES ('Luca')";
    sql = "SELECT * FROM teste";
    //sql = "DROP TABLE teste";
    
    //Executa o comando sql 
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        //fprintf(stdout, "Tabela criada com sucesso\n");
        //fprintf(stdout, "Inserção criada com sucesso\n");
        //fprintf(stdout, "Seleção feita com sucesso\n");
        //fprintf(stdout, "Remoção feita com sucesso\n");
    }
    sqlite3_close(db);
    return 0;
}

