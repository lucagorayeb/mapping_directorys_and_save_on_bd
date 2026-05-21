#include "database.h"

int main(){
    sqlite3 *db;
    char *zErrMsg = 0;
    //char *sql = calloc(100, sizeof(char));
    //char *nome_db = calloc(20, sizeof(char));
    char *sql = "CREATE TABLE user (""id INTEGER PRIMARY KEY," "nome VARCHAR(10) NOT NULL," "idade INT NOT NULL"");";
    char *nome_db = "teste.sqlite3";
     
    //printf("Digite o nome da database: ");
    //scanf("%s", nome_db);
    
    //printf("Digite o sql que deseja executar: ");
    //scanf("%s", sql);
    faz_query(db, zErrMsg, sql, nome_db);
}
