#include <stdio.h>


int main(){
    char string[256];
    int i, j, k, numero;

    scanf("%s", string);


    for(numero=0; string[numero]; numero++){}

    for(j=0, k=0; j<numero; j++){
        for(i=0; string[i]!='\0'; i++){
            if(string[i]<'0' || string[i]>'9'){
                for(k=i; string[k]!='\0'; k++){
                    string[k]=string[k+1];
                }
            }
        }
    }

    if(string[1]=='0'){
        printf("0");
    }
    else{
        printf("%d", string);
    }
    
    return 0;
}
