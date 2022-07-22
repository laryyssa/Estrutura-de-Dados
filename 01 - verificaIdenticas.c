// ARVORE BINARIA 

/* Sejam T1 e T2 duas árvores binárias. Escreva uma função em C que verifique se T1 e T2
são idênticas. */

#include <stdio.h>
#include "00 - ABB.c"


int verificaIdenticas(arvb *a, arvb *b){
    if (!a && !b){
        return 0;
    } else if (a && b){
        if (a->info == b->info){
            return verificaIdenticas(a->fd, b->fd);
            return verificaIdenticas(a->fe, b->fe);
            return 0;
        } else {
            return 1;
        }
    } else {
        return 1;
    }
    
}

int main(){
    arvb *array1 = inicia();
    arvb *array2 = inicia();

    for (int i=1; i<11; i++){
        array1 = inserir(array1, i);
        array2 = inserir(array2, i);
        
    }

    if (verificaIdenticas(array1, array2) == 1){
        printf("Arvores diferentes !");
    } else{
        printf("Arvores identicas !");
    }

    return 0;
}