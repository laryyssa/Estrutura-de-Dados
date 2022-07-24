#include <stdio.h>

// defina o tamanho do tabela -> 10 
// 10 * 2 = 20 -> primo mais próximo 19
// if matricula == -1 => não há essa matricula no sistema

#define M 19

typedef struct ALUNO{
    int matricula;
    char nome[50];
} aluno;

// tabela como variável global => vetorde tamanho M do tipo aluno
aluno tabelaHash[M];

void inicializarTabela(){
    for (int i = 0; i<M; i++){
        tabelaHash[i].matricula = -1;
    }
}

// gera codigo hash
int funcaoHash(int chave){ 
    return chave % M;
}

//ler e retornar um aluno
aluno lerAluno(){
    aluno a;
    printf("Digite a matrícula: ");
    scanf("%d", &a.matricula);
    scanf("%*c");
    printf("Digite um nome: ");
    fgets(a.nome, 50, stdin);
    return a;
}

// inserir um aluno na tabela
void inserir(){
    aluno p = lerAluno();
    int indice = funcaoHash(p.matricula);
    while(tabelaHash[indice].matricula != -1) {
        indice = funcaoHash(indice + 1);
    }
    tabelaHash[indice] = p;
}

aluno* busca(int m){
    int indice = funcaoHash(m);
    while(tabelaHash[indice].matricula != -1){
        if(tabelaHash[indice].matricula == m){
            return &tabelaHash[indice];
        } else {
            indice = funcaoHash(indice + 1);
        }
    }
    return NULL;
}

void imprimir(){
    printf("\n------------------------------ TABELA\n");
    for (int i = 0; i<M; i++){
        if(tabelaHash[i].matricula != -1){
            printf("%d = %d \t %s", i, tabelaHash[i].matricula, tabelaHash[i].nome);
        } else {
            printf("%d = \n", i);
        }
        
    }
    printf("\n-------------------------------------\n");
}

int main() {
    int op, chave;
    aluno *p;

    inicializarTabela();

    do{
        printf("1 - Inserir\n2 - Buscar\n3 - Imprimir\n0 - Sair\n");
        scanf("%d", &op);

        switch(op){
        case 0:
            printf("Saindo...\n");
            break;
        case 1:
            inserir();
            break;
        case 2:
            printf("Digite a matricula a ser buscada: ");
            scanf("%d", &chave);
            p = busca(chave);

            if(p)
                printf("\n\tMatricula: %d \tNome: %s\n", p->matricula, p->nome);
            else
                printf("\nMatricula nao encontrada!\n");
            break;
        case 3:
            imprimir();
            break;
        default:
            printf("Opcao invalida!\n");
        }

    }while(op != 0);

    return 0;
}