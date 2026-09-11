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
    int n;
    printf("Digite o numero de funcionarios: ");
    scanf("%d", &n);

    Funcionario f[n];
    

    Funcionario* v[n];

    for(int i=0; i<n; i++){
        scanf("%s", f[i].nome);
        v[i]= &f[i];
    }

    char nome[81];

    printf("Nome para buscar: ");
    scanf("%s", nome);

    ordenar(n, v);
    printf("\nFuncionarios ordenados:\n");

    for(int i=0; i<n; i++){
        printf ("%s\n", v[i]->nome);
    }

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