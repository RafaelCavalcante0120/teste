#include<stdio.h>
#include<string.h>

struct funcionario {
    char nome[81];
    float valor_hora;
    int horas_mes;
};

typedef struct funcionario Funcionario;

Funcionario* busca(int n, Funcionario** v, char* nome){
    int inicio=0;
    int fim=n-1;
    int meio;
    while (inicio<=fim)
    {
        meio=(inicio+fim)/2;
        if(strcmp(nome, v[meio]->nome)==0){
            return v[meio];
        }
        if(strcmp(nome, v[meio]->nome)>0){
            inicio=meio+1;
        }
        if(strcmp(nome, v[meio]->nome)<0){
            fim=meio-1;
        }
        
    }
    return NULL;
    
}
void ordenar(int n, Funcionario** v);
int main(void){
    int n= 5;
    Funcionario f1, f2, f3, f4, f5;

    Funcionario* v[5];

    scanf("%s", f1.nome);
    scanf("%s", f2.nome);
    scanf("%s", f3.nome);
    scanf("%s", f4.nome);
    scanf("%s", f5.nome);

    v[0] = &f1;
    v[1] = &f2;
    v[2] = &f3;
    v[3] = &f4;
    v[4] = &f5;

    char nome[81];

    printf("Nome para buscar: ");
    scanf("%s", nome);

    ordenar(n, v);

    Funcionario* resultado= busca(n, v, nome);
    if (resultado == NULL){
        printf("Funcionario nao encontrado");
    } else {
        printf("Funcionario encontrado: %s\n", resultado->nome);
    }

    return 0;
}
void ordenar(int n, Funcionario** v){
    int i, j;
    Funcionario* temp;
    for (i=0; i<n-1; i++)
    {   
        for (j=0; j<n-i-1; j++){
            if(strcmp(v[j]->nome, v[j+1]->nome)>0){
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]= temp;
            }

        }
    }
    
}