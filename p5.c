// Guilherme Ferreira Silva
//11811EEL038
#include <stdio.h>

typedef
    unsigned long long int
Bytes8;

typedef
    struct LCG {Bytes8 a, c, m, RAND_MAX, atual;}
LCG;

void semente(LCG * r, Bytes8 seed){
    //constantes do POSIX [de]rand48, glibc [de]rand48[_r]
    //ULL transforma a constante 'int' em 'unsigned long long int'
    r->a = 0x5DEECE66DULL;
    r->c = 11ULL;
    r->m = (1ULL << 48);
    r->RAND_MAX = r ->m -1;
    r->atual = seed;
}

Bytes8 lcg_rand(LCG*r){
    r->atual = (r->a * r->atual + r->c)%r->m;
    return r->atual;
}

double lcg_rand_01(LCG*r){
    return ((double)lcg_rand(r))/(r->RAND_MAX);
}

void gera_numeros(float *vetor, int tam, float min, float max, LCG*r){
    int i;
    for(i=0; i<tam; i++){
        vetor[i]=(max-min)*lcg_rand_01(r)+min;
    }
}

float soma(float *vetor, float *fim_vetor){
    float somatorio=0;
    int i=0;

    for(i=0;(&vetor[i])!=(fim_vetor);i++){
        somatorio+=vetor[i];
    }

    return somatorio;
}

float produto(float *vetor, float *fim_vetor){
    float produtorio=1.0;
    int i=0;

    for(i=0;(&vetor[i])!=(fim_vetor);i++){
        produtorio*=vetor[i];
    }

    return produtorio;
}

int main(){
    int opcao;
    float vetor[50], somatorio=0, produtorio=0;
    LCG r;
    semente(&r ,123456);

    gera_numeros(vetor, 50, 0.5, 1.5,&r);

    printf("1 - Somatorio e 2 - Produtorio: ");
    scanf("%d", &opcao);
    getchar();

    if(opcao==1){
        somatorio=soma(&vetor[0], &vetor[50]);
        printf("somatorio=%f",somatorio);
    }
    else if(opcao==2){
        produtorio=produto(&vetor[0], &vetor[50]);
        printf("produtorio=%f",produtorio);
    }

return 0;
}
