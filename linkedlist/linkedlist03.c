#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int val;
    struct no* next;
} ListNode;

// function declarations
void printlist(ListNode* l);
ListNode* insert(ListNode* l, int number);
void sortingout(ListNode** l1, ListNode** l2, ListNode** l3);

int main() {

    ListNode *list = NULL, *evenlist = NULL, *oddlist = NULL;
    int listSize, number;

    printf("list size: ");
    scanf("%d", &listSize);

    for (int i = 0; i < listSize; i++) {
        printf("%d° number on the list: ", i + 1);
        scanf("%d", &number);
        list = insert(list, number);
    }

    sortingout(&list, &evenlist, &oddlist);

    system("clear");

    // print lists
    printf("normal list: ");
    printlist(list);
    printf("even list: ");
    printlist(evenlist);
    printf("odd list: ");
    printlist(oddlist);

    // free list
    while (list) {
        ListNode* tmp = list;
        list = list->next;
        free(tmp);
    }

    return 0;

}

// function
void printlist(ListNode* l) {
    for (ListNode* i = l; i != NULL; i = i->next)
        printf("%d ", i->val);
    printf("\n");
}

ListNode* insert(ListNode* l, int number) {

    ListNode* element = malloc(sizeof(ListNode));
    element->val = number;
    element->next = NULL;

    if (!l) {
        l = element;
    } else {
        ListNode* tmp = l;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = element;
    }

    return l;

}

void sortingout(ListNode** l1, ListNode** l2, ListNode** l3) {

    ListNode* l1aux = *l1;
    while (l1aux) {
        if (l1aux->val % 2 == 0)
            *l2 = insert(*l2, l1aux->val);
        else 
            *l3 = insert(*l3, l1aux->val);
        l1aux = l1aux->next;
    }

}