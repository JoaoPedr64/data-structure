#include <stdio.h>
#include <stdlib.h>

struct no {
	int info;
	struct no* next;
};
typedef struct no ListNode;

// function
ListNode* insert(ListNode* list, int number);
ListNode* removelist(ListNode **list, int number);
ListNode* removeall(ListNode **list, int number);
void printlist(ListNode* list);
int sizelist(ListNode* list);
int searchlist(ListNode* list, int number);
int mediasimples(ListNode* list);

int main () {
	ListNode *remover, *head = NULL;
	int resp, number, headSize, busca, media;

	do {
		printf("\n0- exit\t6- media\n1- insert\t7-remove all occurrences\n2- remove\n3- search\n4- size\n5- imprimir\n-> ");
		scanf("%d", &resp);

		switch(resp) {
			case 1:
				printf("insert: ");
				scanf("%d", &number);
				head = insert(head, number);
				break;
			case 2:
				printf("remove: ");
				scanf("%d", &number);
				remover = removelist(&head, number);
				if (remover)
					free(remover);
				break;
			case 3:
				printf("search: ");
				scanf("%d", &number);
				busca = searchlist(head, number);
				if (busca == 0)
					printf("Numero %d esta na lista\n", number);
				else
					printf("numero %d nao esta na lista\n", number);
				break;
			case 4:
				headSize = sizelist(head);
				printf("List Size: %d", headSize);
				break;
			case 5:
				printf("List: ");
				printlist(head);
				break;
			case 6:
				media = mediasimples(head);
				printf("Media: %d\n", media);
				break;
			case 7:
				printf("remove: ");
				scanf("%d", &number);
				remover = removeall(&head, number);
				break;
			case 0:
				break;	
		}
	} while (resp != 0);

	return 0;
}

ListNode* insert(ListNode* list, int number) {

	ListNode *aux = malloc(sizeof(ListNode));
	aux->info = number;
	aux->next = NULL;	

	if (list == NULL) {
		list = aux;
	} else {
		ListNode* aux2 = list;
		while (aux2->next != NULL) 
			aux2 = aux2->next;
		aux2->next = aux;
	}

	return list;
}

void printlist(ListNode* list) {	
	for (ListNode* i = list; i != NULL; i = i->next)
		printf("%d ", i->info);
	printf("\n");
}

ListNode* removelist(ListNode **list, int number) {
	ListNode *aux, *remove = NULL;

	if (*list) {
		if ((*list)->info == number){
			remove = *list;
			*list = remove->next;
		} else {
			aux = *list;
			while (aux->next && aux->next->info != number)
				aux = aux->next;
			if (aux->next) {
				remove = aux->next;
				aux->next = remove->next;
			}
		}
	}

	return remove;
}

int sizelist(ListNode* list) {
	
	if (list) {
		int tam = 0;
		for (ListNode* i = list; i != NULL; i = i->next)
			tam++;
	
		return tam;
	}

	return 0;
}

int searchlist(ListNode* list, int number) {
	
	if (list) {
		if (list->info == number) {
			return 0;		
		} else {
			ListNode* aux = list;
			while (aux->next && aux->info != number)
				aux = aux->next;
			if (aux->info == number)
				return 0;
		}
	}

	return 1;
}

int mediasimples(ListNode* list) {
	int media = 0, soma = 0, tamanho = 0;
	if (list) {
		for (ListNode* i = list; i != NULL; i = i->next) {
			tamanho++;
			soma += i->info;
		}	
		media = soma / tamanho;
	}
	return media;
}

ListNode* removeall(ListNode **list, int number) {
	ListNode *aux, *remove;
	remove = NULL;
	aux = *list;
	if (*list) {
		while (aux) {	
			if (aux->info == number) {
				if (remove == NULL)
					*list = aux->next;
				else 
					remove->next = aux->next;
				aux = aux->next;
			} else {
				remove = aux;
				aux = aux->next;
			}
		}
	}
	return remove;
}
