#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int val;
   struct no *esq, *dir;
} tree;

tree *insert(tree *raiz, int number);
tree *imprimir(tree *raiz);

int main() {
   
   tree *raiz = NULL;
   int escolha = -1;
   int number;
   
   while (escolha != 0) {
      printf("\n[0] sair\n[1] inserir\n[2] imprimir\n");
      scanf("%d", &escolha);
      
      switch(escolha) {
         case 0:
            return 0;
         case 1:
            printf("inserir: ");
            scanf("%d", &number);
            raiz = insert(raiz, number);
            break;
         case 2:
            printf("\narvore:");
            imprimir(raiz);
            break;
      }
      
   }
   
   return 0;
   
}

tree *insert(tree *raiz, int number) {

   if (raiz == NULL) {
     tree *aux = malloc(sizeof(tree));
     aux->val = number;
     aux->esq = NULL;
     aux->dir = NULL;
     return aux;
   } else {
      if (raiz->val < number)
      	 raiz->esq = insert(raiz->esq, number);
      else
         raiz->dir = insert(raiz->dir, number);
      return raiz;
   }

}

tree *imprimir(tree *raiz) {

   if (raiz) {
      imprimir(raiz->esq);
      printf(" %d ", raiz->val);
      imprimir(raiz->dir);
   }

}
