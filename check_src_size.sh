#! /usr/bin/env bash
source .env 
TAMANHO_ATUAL=$(du -csk /home/luca/documents/livros/ | tail -n 1 | sed s/t.*//)

function compare_src_size(){
    if [[ $1 != $TAMANHO ]]; then
        ./map_directory.sh
        sleep 1
        sed -i "s/TAMANHO=$TAMANHO/TAMANHO=$TAMANHO_ATUAL/" .env
    fi
}

function search_last_change(){
    find $DIRETORIO -mtime 0
}

compare_src_size $TAMANHO_ATUAL
