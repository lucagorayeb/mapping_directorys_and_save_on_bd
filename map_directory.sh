#! /usr/bin/env bash
DIRECTORY='/home/luca/documents/livros'
PATH_FILE="$DIRECTORY/caminho_dos_livros.txt"
function children_directorys(){
    echo $(ls $DIRECTORY | wc -l)
}

function list_subdirectorys(){
    SUB_DIRECTORY=/home/luca/documents/livros/$1/
    for FILE in $(ls $SUB_DIRECTORY); do
        echo "$(ls -d  $SUB_DIRECTORY)$FILE" >> $PATH_FILE
    done
}

function map_book_directory(){
    contador=1
    while [[ $contador -le $(children_directorys) ]]; do
        teste=$(ls $DIRECTORY | head -n $((contador)) | tail -n 1)
        list_subdirectorys $teste
        contador=$((contador + 1))
    done
}

map_book_directory