#! /usr/bin/env bash
DIRECTORY_NAME=a
cat /tmp/controle_caminho_dos_livros.txt | sed s/.*livros// | grep $DIRECTORY_NAME
