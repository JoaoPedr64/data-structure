#include <stdio.h>

void mergeSort(int *vet, int *aux, int inicio, int final);
void merge(int *vet, int *aux, int inicio, int final);

int main() {
	
	int TAM = 10;
	int list[10] = {0,4,5,2,6,7,8,9,1,3};
	int aux[TAM];
	
	for (int i = 0; i < TAM; i++) {
		aux[i] = list[i];
	}
		
	printf("lista bagunçada: ");
	for (int i = 0; i < TAM; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
	
	mergeSort(list, aux, 0, TAM - 1);
	
	printf("lista ordenada: ");
	for (int i = 0; i < TAM; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
	
	return 0;
}

void mergeSort(int *vet, int *aux, int inicio, int final) {
	
	if (inicio < final) {
		int meio = (inicio + final) / 2;
		
		mergeSort(vet, aux, inicio, meio);
		mergeSort(vet, aux, meio + 1, final);
		merge(vet, aux, inicio, final);
	}	
	
}

void merge(int *vet, int *aux, int inicio, int final) {
	
	int meio = (inicio + final) / 2;
	int esq = inicio;
	int dir = meio + 1;
	int k = inicio;
	
	while (esq <= meio && dir <= final) {
		if (aux[esq] <= aux[dir]) {
			vet[k] = aux[esq];
			esq++;
		}
		else {
			vet[k] = aux[dir];
			dir++;
		}
		k++;
	}
	while (esq <= meio) {
		vet[k] = aux[esq];
		k++;
		esq++;
	}
	while (dir <= final) {
		vet[k] = aux[dir];
		k++;
		dir++;
	}
	
	for (int i = inicio; i <= final; i++) {
		aux[i] = vet[i];
	}
	
}

