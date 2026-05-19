#! /usr/bin/env bash

DIRECTORY='/home/luca/documents/livros'
PATH_FILE='/tmp/caminho_dos_livros.txt'
PATH_DIRECTORY='/tmp/caminho_dos_subdiretorios.txt'
CONTROLL_FILE='/tmp/controle_caminho_dos_livros.txt'
CONTROLL_DIRECTORY='/tmp/controle_caminho_dos_subdiretorios.txt'

function children_directorys(){
    echo $(ls $DIRECTORY | wc -l)
}

function map_files_directory(){
    contador=1
    while [[ $contador -le $(children_directorys) ]]; do
        sub_directorys=$(ls $DIRECTORY | head -n $((contador)) | tail -n 1)
        save_subdirectorys $sub_directorys
        contador=$((contador + 1))
    done
    controll_file $PATH_FILE $CONTROLL_FILE
    echo "Salvando no banco..."
    sleep 1
    remove_data_from_file $PATH_FILE
}

function map_directorys(){
    contador=1
    while [[ $contador -le $(children_directorys) ]]; do
        directorys=$(ls $DIRECTORY | head -n $((contador)) | tail -n 1)
        save_directorys $directorys
        contador=$((contador + 1))
    done
    controll_file $PATH_DIRECTORY $CONTROLL_DIRECTORY 
    echo "Salvando no banco..."
    sleep 1
    remove_data_from_file $PATH_DIRECTORY 
}

function save_subdirectorys(){
    SUB_DIRECTORY="$DIRECTORY/$1/"
    for FILE in $(ls $SUB_DIRECTORY); do
        echo "$(ls -d  $SUB_DIRECTORY)$FILE" >> $PATH_FILE
    done
}

function save_directorys(){
    echo $1 >> $PATH_DIRECTORY   
}

function controll_file(){
    diff $1 $2 | sed s/2,3d1// | sed s/'<'// | sed s/" "// | tail -n +2 >> $2
}

function remove_data_from_file(){
    > $1
}

map_directorys
map_files_directory
