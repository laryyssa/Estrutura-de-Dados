/* Escreva uma função em C que verifique se uma árvore é simétrica, isto é, se sua
subárvore direita é uma imagem espelhada da sua subárvore esquerda. */

#include <stdio.h>
#include "00 - ABB.c"

int espelhada(arvb *a, arvb *b){
    if (a && b){
        //printf("a - %d b - %d\n", a->info, b->info);
        if (a->info == b->info){
            if (espelhada(a->fd, b->fe) == 0 && espelhada(a->fe, b->fd) == 0){
                return 0;
            }
        }
    } else if (!a && !b){
        return 0;
    } else {
        return 1;
    }
}

arvb * inserirAoContrario(arvb *raiz, int valor) {
    if(raiz == NULL) {
        arvb *novo = (arvb*)malloc(sizeof(arvb));
        novo->info = valor;
        novo->fe = NULL;
        novo->fd = NULL;
        return novo;
    } else {
        if(valor < raiz->info) raiz->fd = inserirAoContrario(raiz->fd, valor);
        else if(valor > raiz->info) raiz->fe = inserirAoContrario(raiz->fe, valor);
        else if(valor == raiz->info) 
            printf("Numero ja inserido !\n");
            return raiz;
        return raiz;
    }
}

int main(){
    arvb *a = inicia();
    arvb *b = inicia();

    a = inserir(a, 10);
    a = inserir(a, 8);
    a = inserir(a, 15);
    a = inserir(a, 3);
    a = inserir(a, 9);
    a = inserir(a, 12);
    a = inserir(a, 16);


    b = inserirAoContrario(b, 10);
    b = inserirAoContrario(b, 15);
    b = inserirAoContrario(b, 8);
    b = inserirAoContrario(b, 16);
    b = inserirAoContrario(b, 12);
    b = inserirAoContrario(b, 9);
    b = inserirAoContrario(b, 3);
    

    if (espelhada(a,b) == 0){
        printf("Arvore espelhada !");
    } else {
        printf("Arvores diferentes !");
    }

    return 0;
}