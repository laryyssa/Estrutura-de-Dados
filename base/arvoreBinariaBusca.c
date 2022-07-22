#include <stdio.h>
#include <stdlib.h>

typedef struct ARVB{
    int info;
    struct arvb *fd;
    struct arvb *fe;

}arvb;


// -------------------------------- INICIAR

arvb * inicia(){
    return NULL;
}

// --------------------------------- INSERIR

arvb * inserir(arvb *raiz, int valor) {
    if(raiz == NULL) {
        arvb *novo = (arvb*)malloc(sizeof(arvb));
        novo->info = valor;
        novo->fe = NULL;
        novo->fd = NULL;
        return novo;
    } else {
        if(valor < raiz->info) raiz->fe = inserir(raiz->fe, valor);
        else if(valor > raiz->info) raiz->fd = inserir(raiz->fd, valor);
        else if(valor == raiz->info) 
            printf("Numero ja inserido !\n");
            return raiz;
        return raiz;
    }
}

// --------------------------------- IMPRIMIR

void preOrdem(arvb *no){     
    // Raíz -> FE -> FD
    if (no){
        printf("%d - ", no->info);
        preOrdem(no->fe);
        preOrdem(no->fd);
    }
}    

/* void largura(arvb *no){
    // Imprimir por nível da esq para a dir
    //arvb *comeco = no;
    printf("Em Largura: ");
    printf("%d - ", no-> info);
    if (no){
        largura(no->fe);

    }
} */

void ordemSimetrica(arvb *no){
    // FE - RAIZ - FD
    if (no){
        ordemSimetrica(no->fe);
        printf("%d - ", no->info);
        ordemSimetrica(no->fd);
    }
}

void posOrdem(arvb *no){
    // FE - FD - RAIZ
    if (no){
        posOrdem(no->fe);
        posOrdem(no->fd);
        printf("%d - ", no->info);
    }
}


void imprimir(arvb *no){
    printf("A árvore possui %d elemento(s).\n", tamanho(no));
    printf("Pre-Ordem: ");
    preOrdem(no);
    printf("\n");
    //largura(no);
    printf("Ordem Simetrica: ");
    ordemSimetrica(no);
    printf("\n");
    printf("Pos Ordem: ");
    posOrdem(no);
    printf("\n");

}

// -------------------------------- TAMANHO

int tamanho(arvb *no){
    if(!no) return 0;
    else return 1 + tamanho(no->fe) + tamanho(no->fd);
}

// -------------------------------- BUSCA

arvb * buscar(arvb *no, int valor){
    if (!no) return NULL;
    else if (no -> info == valor) return no;
    /* else if (no -> info < valor) return no->fe = buscar(no->fe, valor);
    else if (no -> info > valor) return no->fd = buscar(no->fd, valor); */
    else if (no -> info < valor) return buscar(no->fe, valor);
    else if (no -> info > valor) return buscar(no->fd, valor);
}

// -------------------------------- REMOVER

arvb * remover(arvb *no, int valor){
    if (!no){
        printf("Valor nao encontrado ! \n");
        return NULL;

    } else {
        if(no->info == valor){
            // RAIZ SEM FILHO
            if (no->fd == NULL && no->fe == NULL) {
                free(no);
                return NULL;
            } 
            // RAIZ COM 1 FILHO
            else if (no->fd == NULL || no->fe == NULL){
                arvb *aux;
                if (no->fd != NULL) 
                    aux = no->fd;
                else 
                    aux = no->fe;
                free(no);
                return aux;
            }
            // RAIZ COM 2 FILHOS; trocar o valor do nó com 2 filhos com um nó folha
            else {
                arvb *aux = no->fe;
                while(aux->fd){
                    aux = aux->fd;
                }
                no->info = aux->info;
                aux->info = valor;
                no->fe = remover(no->fe, valor);
            }
        }
        else if (valor > no->info) no->fd = remover(no->fd, valor);
        else if (valor < no->info) no->fe = remover(no->fe, valor);
        return no;
    }


}

// -------------------------------- MAIN

int main(){
    int resp, num;
    arvb *raiz = inicia();

    do{
        resp=0; num=0;
        printf("-----------------------\n");
        printf(" 1 - Inserir \n 2 - Imprimir \n 3 - Remover \n 0 - Sair \n");
        scanf("%d", &resp);

        switch (resp){
            case 0:
                break;

            case 1:
                printf("Digite um numero para inserir na arvore: ");
                scanf("%d", &num);
                raiz = inserir(raiz, num);
                break;

            case 2:
                imprimir(raiz);
                break;

            case 3:
                printf("Digite o numero que deseja remover da arvore: ");
                scanf("%d", &num);
                raiz = remover(raiz, num);
                break;

            default:
                printf("Numero invalido, tente novamente !\n");
                break;
            
        }

    }while (resp != 0);

    return 0;
}