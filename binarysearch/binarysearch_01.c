#include <stdio.h>

int binarysearch(int *list, int chave, int inicio, int fim);

int main() {
	
    int list[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,};
    int fim = 11;
    int inicio = 0;
	
    int resp = 1;
    while (resp != 0) {
	printf("0- Sair\n1- Busca\n-> ");
	scanf("%d ", &resp);
		
	int busca;
	scanf("%d", &busca);
	   
	int chave = binarysearch(list, busca, inicio, fim);
	if (chave != -1) {   
	    printf("O numero %d se encontra na posiçao: %d\n\n", busca, chave);
	} else {
	    printf("O numero %d nao esta na lista\n\n", busca);
	}
    }
		
    return 0;
	
}

int binarysearch(int *list, int chave, int inicio, int fim){

    if (inicio <= fim) {
    	int meio = (inicio + fim) / 2;
    	
    	if (chave == list[meio])
    	    return meio;
    	else {
    	    if (chave < list[meio])
    	    	return binarysearch(list, chave, inicio, meio - 1);
    	    else 
    	    	return binarysearch(list, chave, meio + 1, fim);
    	}
    }
    
    return -1;

} 

