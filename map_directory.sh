#! /usr/bin/env bash
DIRECTORY='/home/luca/documents/livros'
PATH_FILE='/tmp/caminho_dos_livros.txt'
PATH_DIRECTORY='/tmp/caminho_dos_diretorios.txt'
function children_directorys(){
    echo $(ls $DIRECTORY | wc -l)
}

function save_subdirectorys(){
    SUB_DIRECTORY="$DIRECTORY/$1/"
    for FILE in $(ls $SUB_DIRECTORY); do
        echo "$(ls -d  $SUB_DIRECTORY)$FILE" >> $PATH_FILE
    done
}

function map_files_directory(){
    contador=1
    while [[ $contador -le $(children_directorys) ]]; do
        sub_directorys=$(ls $DIRECTORY | head -n $((contador)) | tail -n 1)
        save_subdirectorys $sub_directorys
        contador=$((contador + 1))
    done
}

function map_directorys(){
    contador=1
    while [[ $contador -le $(children_directorys) ]]; do
        directorys=$(ls $DIRECTORY | head -n $((contador)) | tail -n 1)
        save_directorys $directorys
        contador=$((contador + 1))
    done
}

function save_directorys(){
    #SUB_DIRECTORY="$DIRECTORY/$1/"
    echo $1 >> $PATH_DIRECTORY
    
}

map_directorys
map_files_directory
