/* 2) Implemente em C, para um grafo não direcionado, representado por uma lista de
adjacências, os algoritmos de:
a) busca por um vértice
b) busca por uma aresta
c) inserção de um vértice
d) inserção de uma aresta
e) remoção de uma aresta. */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id_vizinho;
    struct vizinho *prox;
} vizinho;

typedef struct {
    int id_vertice; // origem
    struct grafo *prox_vertice;
    struct vizinho *primeiro_vizinho;

} grafo;

grafo *inicializa(){
    return NULL;
}

/* grafo * insereVetorVertices(int array[], int tam, grafo *g){
    for (int i=0; i<tam; i++){
        g = insereVertice(g, array[i]);
    }
    return g;
}

void insereVetorArestas(int array[], size_t tam, grafo *g){
    for (int i=0; i<tam; i+=2){
        insereAresta(g, array[i], array[i+1]);
    }
} */

// --------------------------------------

grafo *buscaVertice(grafo *g, int x){
    while (g && g->id_vertice != x){
        g = g->prox_vertice;
    }
    return g;
}

grafo *insereVertice(grafo *g, int v){
    grafo *b = buscaVertice(g,v);
    if (b == NULL){
        b = (grafo*)malloc(sizeof(grafo));
        b->id_vertice = v;
        b->prox_vertice = g;
        b->primeiro_vizinho = NULL;
        g = b;
    }
    return g;
}

vizinho *buscaAresta(grafo *g, int v1, int v2){
    grafo *bv1 = buscaVertice(g, v1);
    grafo *bv2 = buscaVertice(g, v2);
    vizinho *r = NULL;
    if (bv1 && bv2){
        r = bv1->primeiro_vizinho;
        while(r && r->id_vizinho != v2){
            r = r->prox;
        }
    }
    return r;
}

void insereAresta_umSentido(grafo *g, int v1, int v2){
    //printf("oi ");
    grafo *b = buscaVertice(g, v1);
    vizinho *novo = (vizinho*)malloc(sizeof(vizinho));
    novo->id_vizinho = v2;
    novo->prox = b->primeiro_vizinho;
    b->primeiro_vizinho = novo;
}

void insereAresta(grafo *g, int v1, int v2){
    vizinho *p = buscaAresta(g, v1, v2);
    if (p==NULL){
        insereAresta_umSentido(g, v1, v2);
        insereAresta_umSentido(g, v2, v1);
    }
}

void exclusao_uma_aresta(grafo *g, int v1, int v2){
    grafo *v = buscaVertice(g, v1);
    if (v){
        vizinho *anterior = NULL;
        vizinho *aux = v->primeiro_vizinho;
        while(aux && aux->id_vizinho != v2){
            anterior = aux;
            aux = aux->prox;
        }
        if (anterior == NULL){
            v->primeiro_vizinho = aux->prox;
        } else {
            anterior->prox = aux->prox;
        }
        free(aux);
    }
}

void exclusao_duas_arestas(grafo *g, int v1, int v2){
    vizinho *b = buscaAresta(g, v1, v2);
    if (b){
        exclusao_uma_aresta(g, v1, v2);
        exclusao_uma_aresta(g, v2, v1);
    }
}

void imprimir(grafo *g){
    if (g){
        grafo *aux = g;
        vizinho *v;
        while (aux){
            printf("vertice %d => ", aux->id_vertice);
            v = aux->primeiro_vizinho;
            while(v){
                printf("%d - ", v->id_vizinho);
                v = v->prox;
            }
            printf("\n");
            aux = aux->prox_vertice; 
        }
        printf("\n");
    }
}


// --------------------------------------

int main(){ 
    grafo *g = inicializa();
    
    int vertices[] = {1,2,3,4};
    for (int i=0; i<sizeof(vertices)/sizeof(vertices[0]); i++){
        g = insereVertice(g,vertices[i]);
    }
   
    int arestas[] = {1,2, 1,3, 2,3, 2,4, 3,4};
    int j=0;
    while (j<sizeof(arestas)/sizeof(arestas[0])){
        printf("%d e %d\n", arestas[j], arestas[j+1]);
        insereAresta(g, arestas[j], arestas[j+1]);
        j+=2;
    }

    imprimir(g);

    printf("Depois da exlusao da aresta 1-2 e 3-4: ");
    exclusao_duas_arestas(g, 1, 2);
    exclusao_duas_arestas(g, 3, 4);

    imprimir(g);
}