#include<stdio.h>
void roda_string(char* str);
int main(void){
    char c[100];
    scanf("%s", c);
    roda_string(c);
    printf ("%s ", c);
    return 0;
}
void roda_string(char* str){
    int tam;
    char ult;
    for(tam=0; str[tam]!='\0'; tam++){
        
    }
    ult=str[tam-1];
    for(tam=tam-1; tam>0; tam--){
        str[tam]= str[tam-1];
    }
    str[0]=ult;
}