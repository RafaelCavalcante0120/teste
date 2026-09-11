#include<stdio.h>
#include<string.h>
struct contato{
    char nome[81];
    char telefone[21];
    int dia;
    int mes;
    int ano;
};
typedef struct contato Contato;

void ordena(int n, Contato** v);
int main(void){
    int n;
    
    printf("Digite a quantidade de contatos: ");
    scanf("%d", &n);

    Contato c[n];
    Contato* v[n];

    for (int i=0; i<n; i++){
        v[i]= &c[i];
        printf("Digite o nome:");
        scanf("%s", c[i].nome);

        printf("Digite o telefone:");
        scanf("%s", c[i].telefone);

        printf("Digite o dia:");
        scanf("%d", &c[i].dia);
        
        printf("Digite o mes:");
        scanf("%d", &c[i].mes);

        printf("Digite o ano:");
        scanf("%d", &c[i].ano);    
    }
    ordena(n, v);

    for(int j=0; j<n; j++){
        printf("%s %s %d/%d/%d\n", v[j]->nome, v[j]->telefone,
        v[j]->dia, v[j]->mes, v[j]->ano);
    }
    return 0;

}
void ordena(int n, Contato** v){

    int i, j;
    Contato* temp;

    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if((v[j]->ano > v[j+1]->ano)){
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
            else if((v[j]->ano == v[j+1]->ano && v[j]->mes > v[j+1]->mes)){
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
            else if(v[j]->ano == v[j+1]->ano && v[j]->mes == v[j+1]->mes &&
            v[j]->dia > v[j+1]->dia){
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
}