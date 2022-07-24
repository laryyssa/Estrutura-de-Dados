#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int pai(int i){
    return (i/2);
}

int esquerda(int i){
    return (i*2);
}

int direita(int i){
    return (i*2+1);
}

void subir(int *heap, int i) {
    int j = pai(i);
    if (j >= 1) {
        if (heap[i] > heap[j]) {
            //faz a subida
            int aux = heap[i];
            heap[i] = heap[j];
            heap[j] = aux;
            subir(heap, j);

        }

    }

}

void descer (int *heap, int i, int tam){
    //descobre quem é o maior filho de i

    int e = esquerda(i);
    int d = direita(i);
    int maior = i;

    if (e <= tam && heap[e] > heap[i]) {
        maior = e;
    }
    if(d <= tam && heap[d] > heap[maior]) {
        maior = d;
    }
    if (maior != i){
    //faz a descida trocando com o maior filho
        int aux = heap[i];
        heap[i] = heap[maior];
        heap[maior] = aux;
        descer(heap, maior, tam);
    }
}

int inserirMais(int *heap, int novo, int tam){
    //aumenta o tamanho do vetor
    heap = (int *) realloc(heap, sizeof(int) * (tam + 2));
    tam += 1;
    heap[tam] = novo;

    subir(heap, tam);
    //retorna o novo valor de n (tamanho do vetor heap)
    return tam;
}

int remover(int *heap, int tam) {
    heap[1] = heap[tam];
    tam -= 1;
    //diminui o tamanho do vetor
    heap = (int *) realloc(heap, sizeof(int) * (tam + 1));

    descer(heap, 1, tam);
    //retorna o novo valor de n (tamanho do vetor heap)
    return tam;

}

// -------------------------------------- IMPRIMIR

void imprimirHeap(int *heap, int tam){
    printf("Imprimir em modo de lista: ");
    for(int i=1; i<=tam; i++){
        printf("%d - ", heap[i]);
    }
    printf("\n");
}


void imprimirPorNivel(int *heap, int nivel, int tam){
    int indice = nivel;
    //printf("oi");
    for(int i=0; i<nivel; i++){
        printf("%d ", heap[indice + i]);
    }
    printf('\n');
}
int quantNiveis(int *heap, int tam, int indice){
    if (indice > tam){
        return 0;
    } else {
        int esq = quantNiveis(heap, tam, esquerda(indice)) + 1;
        int dir = quantNiveis(heap, tam, direita(indice)) + 1;

        if (esq>dir){
            return esq;
        } else {
            return dir;
        }
    }
}
void imprimirArvore(int *heap, int tam){
    int numNiveis = quantNiveis(heap, tam, 1);
    //printf("numero de niveis %d", numNiveis);
    for (int i=0; i<numNiveis; i++){
        int j = pow(2,i);
        printf("j %d\n", j);
        imprimirPorNivel(heap, j, tam);
    }
}


// -----------------------------------------------

int main(void){    
    int r, tam, n;
    //int *heap;
    
        /* printf("Digite o tamanho de vetor Heap: ");
        scanf("%d", &tam);
        heap = (int*)malloc(sizeof(int) * (tam + 1)); */

        /* for (int k=1; k<=tam; k++){
            printf("Digite um numero: ");
            scanf("%d", &heap[k]);
        } */

    tam = 8;
    int heap[8] = {0, 28, 33, 39, 60, 66, 70, 78, 95};

    do {
        printf("\n---------------------\n");
        printf(" Operacoes: \n 1 - Inserir mais um elemento \n 2 - Remover topo da arvore \n 3 - Trocar elemento \n 4 - Imprimir \n 0 - Sair \n");
        scanf("%d", &r);
        switch(r){
            case 0:
                break;
            case 1:
                printf("Digite o numero que deseja inserir: ");
                scanf("%d", &n);
                tam = inserirMais(heap, n, tam);
                break;
            case 2:
                tam = remover(heap, tam);
                break;

            case 3: 
                
                break;

            case 4:
                imprimirHeap(heap, tam);
                imprimirArvore(heap,tam);
                break;

            default:
                printf("Numero invalido !\n");
        }
        
    } while (r != 0);

    
    
    
    /* printf("Imprimir em modelo de arvore: \n");
    imprimirArvore(heap, 1, n);
    */
}