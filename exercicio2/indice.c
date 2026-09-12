#include<stdio.h>
#include <stdlib.h>
int indice(int n, int* v, int x);
void intercala(int p, int q, int r, int v[]);
void maquiavel(int p, int r, int v[]);
int main(void)
{
    int n;
    scanf("%d", &n);
    int v[n];

    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

    maquiavel(0, n, v);

    

    int x;
    scanf("%d", &x);
    for(int i=0; i<n; i++){
        printf("%d ", v[i]);
    }
    printf("\n%d\n", indice(n, v, x));

    return 0;
}
int indice(int n, int* v, int x){

    int inicio= 0;
    int fim= n-1;
    int meio;

    while (inicio<=fim)
    {
        meio=(inicio+fim)/2;
        if(x<v[meio]){
            fim=meio-1;
        }
        else{
            inicio=meio+1;
        }
    
    }
    return inicio;
    
    
}
void intercala(int p, int q, int r, int v[]){
    int i=p;
    int j=q;
    int k=0;

    int *temp = malloc((r-p) * sizeof(int));

    while(i<q&& j<r){
        if(v[i]<=v[j]){
            temp[k]=v[i];
            k++; i++;
        }
        else{
            temp[k]=v[j];
            k++; j++;
        }
    }
    while(i<q){
        temp[k]=v[i];
        k++; i++;
    }
    while(j<r){
        temp[k]=v[j];
        k++; j++;
    }
    for(i=p; i<r; i++){
        v[i]= temp[i-p];
    }
    free(temp);
}
void maquiavel(int p, int r, int v[]){
    if(p<r-1){
        int q= (p+r)/2;

        maquiavel(p, q, v);
        maquiavel(q, r, v);

        intercala(p, q, r, v);
    }
}