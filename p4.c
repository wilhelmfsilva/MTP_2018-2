// Guilherme Ferreira Silva
//11811EEL038
#include <stdio.h>

int A(int, int);

int main(){
    int m, n;

    scanf("%d %d", &m, &n);
    
    n=A(m, n);

    printf("%d\n", n);
    
    return 0;
}

int A(int m ,int n){
    
    if(m==0){
        n++;
}
    else if(m>0 && n==0){
        n=A(m-1,1);
}
    else if(m>0 && n>0){
        n=A(m-1,A(m,n-1));
}

    return n;
}
