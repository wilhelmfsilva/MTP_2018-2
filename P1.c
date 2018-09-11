// Guilherme Ferreira Silva
//11811EEL038
#include <stdio.h>

int main(){
  int estado = 0, i=0;
  char bits[256];
    
  scanf("%s", bits);
  
  while(bits[i] != '\0'){
    if(estado == 0 && bits[i] == '0'){          //primeiro estado
    estado = 0;
    }
    else if(estado == 0 && bits[i] == '1'){     //primeiro estado
    estado = 1;
    }
    else if(estado == 1 && bits[i] == '1'){
    estado = 0;
    }
    else if(estado == 1 && bits[i] == '0'){
    estado = 2;
    }
    else if(estado == 2 && bits[i] == '0'){
    estado = 1;
    }
    else if(estado == 2 && bits[i] == '0'){
    estado = 2;
    }
    i++;
  }
       
  printf("\n\"%s\" ", bits);
       
if(estado == 0) {
  printf("e multiplo de 3\n");
}
else {
  printf("nao e\n");
}
  return 0;
}
