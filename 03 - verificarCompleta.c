/* Escreva uma função em C que verifique se uma árvore binária é completa. */

#include <stdio.h>
#include "00 - ABB.c"

// se N é um no e tem filho vazio ele só pode ser o último ou penúltimo

int verifica(arvb *raiz){
    if (raiz){
        if (raiz->fd && raiz->fe){
           /*  return verifica(raiz->fe);
            return verifica(raiz->fd); */
            if (verifica(raiz->fd) == 1 || verifica(raiz->fe) == 1){
                return 1;
            } else {
                return 0;
            }

        } else if (raiz->fe || raiz ->fd){
            arvb *aux;
            if (raiz->fe) aux = raiz->fe;
            else aux = raiz->fd; 

            if (!aux->fe && !aux->fd) return 0;
            else return 1;
        } else {
            return 0;
        }
    }
}

int main(){
    arvb *b = inicia();
    b = inserir(b, 76);
    b = inserir(b, 50);
    b = inserir(b, 80);
    b = inserir(b, 10);
    b = inserir(b, 70);
    b = inserir(b, 98);
    b = inserir(b, 2);
    b = inserir(b, 45);
    b = inserir(b, 82);

    if (verifica(b) == 1){
        printf("Arvore incompleta !");
    } else {
        printf("Arvore completa !");
    }
}