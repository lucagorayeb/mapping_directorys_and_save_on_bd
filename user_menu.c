#include "database.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int menu_action(int);
int user_interact_menu(void);
int second_command(char*);


int display_menu(){
	char *word = "Directory Reader";
	char *first_comand =  "[1] - List directorys          ";
	char *second_comand = "[2] - List files from directory";
	char *second_comand = "[3] - Open file";
	
	do_line(word);
	printf("\n%s\n", word);
	do_line(word);
	printf("\n");
	
	do_line(first_comand);
	printf("\n%s\n", first_comand);
	printf("%s\n", second_comand);
	printf("%s\n", second_comand);
	do_line(first_comand);
	printf("\n");
	user_interact_menu();
	
	return 0;
}

int do_line(char *word){
	int size = strlen(word);
	for(int i = 0; i <= size; i++){
		if(i == 0){
			printf("+");
		}else if(i == size){
			printf("+");
		}else{
			printf("-");
		}
	}
	return 0;
}

int user_interact_menu(){
	int option;
	printf("\nSelect one option: ");
	scanf("%d", &option);
	menu_action(option);
	return 0;
}

int menu_action(int option){
	if(option == 1){
		printf("Listing directorys: \n");
		system("cat /tmp/controle_caminho_dos_subdiretorios.txt");
	}

	if(option == 2){
		char *directory_name = calloc(50, sizeof(char));
		printf("Directory name: ");
		scanf("%s", directory_name);
		listing_directory_files(directory_name);
	}

	if(option == 3){
		char *file_name = calloc(100, sizeof(char));
		printf("File name: ");
		scanf("%s", file_name);
		open_file_from_directory(file_name);
	}

	if(option != 2 && option != 1 && option != 3){
		printf("Command not found.");
		user_interact_menu();
	}

	return 0;
}

// This command creates a shell script file that list files from 
// a directory.
int listing_directory_files(char *directory_name){
	char directory_variable[100] = "DIRECTORY_NAME=";
	strcat(directory_variable, directory_name);

	FILE *arq = fopen("listagem_arquivos.sh", "w");
	fprintf(arq, "%s", "#! /usr/bin/env bash\n");
	fprintf(arq, "%s", directory_variable);
	fprintf(arq, "%s", "\ncat /tmp/controle_caminho_dos_livros.txt | sed s/.*livros// | grep $DIRECTORY_NAME\n");
	fclose(arq);	
	
	system("./listagem_arquivos.sh");
	return 0;
}

int open_file_from_directory(char* file_path){
	system("xdg-open  | grep um_arquivo_muito_especifico.txt)");
}

int main(){
	system("clear");
	display_menu();
	return 0;
}
