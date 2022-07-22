/* Seja T uma árvore binária. Escreva uma função em C que gere e retorne uma cópia de
T. */

#include <stdio.h>
#include "00 - ABB.c"

arvb *copia (arvb *raiz){
    if (raiz){
        arvb *novo = (arvb*)malloc(sizeof(arvb));
        novo->info = raiz->info;
        novo->fe = copia(raiz->fe);
        novo->fd = copia(raiz->fd);
    } else {
        return NULL;
    }
}


int main(){
    arvb *b = inicia();
    b = inserir(b, 10);
    b = inserir(b, 5);
    b = inserir(b, 15);
    b = inserir(b, 3);

    arvb *c;
    c = copia(b);

    printf("Arvore b\n");
    imprimir(b);
    printf("Arvore c\n");
    imprimir(c);

}