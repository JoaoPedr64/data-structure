#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int val;
    struct no* next;
} ListNode;

// declared functions
ListNode* insert(ListNode* list, int number);
ListNode* reverse(ListNode* list);
ListNode* oddnumbers(ListNode* list);
ListNode* join(ListNode* l1, ListNode* l2);
ListNode* copylist(ListNode* list);
ListNode* intersection(ListNode* l1, ListNode* l2);
ListNode* Interleave(ListNode* l1, ListNode* l2);
ListNode* mergeneatly(ListNode* l1, ListNode* l2);
void printlist(ListNode* list);

int main() {

    ListNode *L1 = NULL, *L2 = NULL, *L3 = NULL;
    int L1size, L2size, numinse, number, answer;

    // filling out the lists
    printf("L1 Size: ");
    scanf("%d", &L1size);
    for (int i = 0; i < L1size; i++) {
        printf("insert %d° element: ", i + 1);
        scanf("%d", &numinse);
        L1 = insert(L1, numinse);
    }

    system("clear");

    printf("L2 Size: ");
    scanf("%d", &L2size);
    for (int i = 0; i < L2size; i++) {
        printf("insert %d° element: ", i + 1);
        scanf("%d", &numinse);
        L2 = insert(L2, numinse);
    }

    system("clear");

    do {
        system("clear");
        printf("L1: ");
        printlist(L1);
        printf("L2: ");
        printlist(L2);
        printf("L3: ");
        printlist(L3);
        printf("[0] sair\t[1] reverse\t[2] odd numbers\t[3] join\t[4] intersection\t[5] Interleave\n-> ");
        scanf("%d", &answer);

        switch (answer) {
        // reverse
        case 1: 
            printf("reverse: [1] L1\t[2] L2\n-> ");
            scanf("%d", &number);
            
            if (number == 1) 
                L3 = reverse(L1);
            else if (number == 2) 
                L3 = reverse(L2);
            else {
                printf("invalid option\n");
            }

            break;

        // odd numbers
        case 2:
            printf("odd numbers: [1] L1\t[2] L2\n-> ");
            scanf("%d", &number);
            if (number == 1)
                L3 = oddnumbers(L1);
            else if (number == 2)
                L3 = oddnumbers(L2);
            else {
                printf("invalid option\n");
            }

            break;

        // join
        case 3: 
            L3 = join(L1, L2);
            break;

        // intersection
        case 4:
            if (L1 == NULL) {
                printf("ERRO: list does not exist\n");
                break;
            } else if (L2 == NULL) {
                printf("ERRO: list does not exist\n");
                break;
            }

            L3 = intersection(L1, L2);
            break;

        case 5:
            if (L1 == NULL) {
                printf("ERRO: list does not exist\n");
                break;
            } else if (L2 == NULL) {
                printf("ERRO: list does not exist\n");
                break;
            }
            printf("[1] normal\t[2] ordered\n-> ");
            scanf("%d", &number);

            if (number == 1)
                L3 = Interleave(L1, L2);
            else {
                L3 = mergeneatly(L1, L2);
            }

            break;

        // stop program
        case 0:
            break;

        default:
            printf("invalid option\n");
            break;
        }
    } while (answer != 0);
        
    // Freeing up memory
    while (L1 != NULL) {
        ListNode* tmp = L1;
        L1 = L1->next;
        free(tmp);
    }

    while (L2 != NULL) {
        ListNode* tmp = L2;
        L2 = L2->next;
        free(tmp);
    }

    while (L3 != NULL) {
        ListNode* tmp = L3;
        L3 = L3->next;
        free(tmp);
    }

    return 0;

}

// functions
ListNode* insert(ListNode* list, int number) {

    ListNode* element = malloc(sizeof(ListNode));
    element->val = number;
    element->next = NULL;

    if (list == NULL || list->val > number) {
        element->next = list;
        return element;
    } else{
        ListNode* aux = list;
        while (aux->next != NULL && aux->next->val < number)
            aux = aux->next;

        element->next = aux->next;
        aux->next = element;
    }
    return list;

}

void printlist(ListNode* list) {

    ListNode* aux = list;
    while (aux != NULL) {
        printf("%d ", aux->val);
        aux = aux->next;
    }
    printf("\n");
    return;

}

ListNode* reverse(ListNode* list) {

    ListNode* copyl = copylist(list); 
    ListNode *reversedlist = NULL, *aux = copyl;

    while (aux != NULL) {
        ListNode* tmp = aux;
        aux = aux->next;
        tmp->next = reversedlist;
        reversedlist = tmp;
    }

    return reversedlist;

}

ListNode* oddnumbers(ListNode* list) {

    ListNode* oddlist = NULL;
    ListNode* aux = list;

    while (aux) {
        if (aux->val % 2 != 0) {
            oddlist = insert(oddlist, aux->val);
        }
        aux = aux->next;
    }

    return oddlist;

}

ListNode* copylist(ListNode* list) {

    ListNode *originallist = NULL, *aux = list;

    while (aux != NULL) {
        ListNode* tmp = malloc(sizeof(ListNode));
        tmp->val = aux->val;
        tmp->next = NULL;

        if (originallist == NULL)
            originallist = tmp;
        else {
            ListNode* aux2 = originallist;
            while (aux2->next != NULL)
                aux2 = aux2->next;
            aux2->next = tmp;
        }

        aux = aux->next;
    }

    return originallist;

}

ListNode* join(ListNode* l1, ListNode* l2) {

    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;

    ListNode* newlist = NULL;
    ListNode* aux = l1;

    while (aux) {
        newlist = insert(newlist, aux->val);
        aux = aux->next;
    }

    ListNode* aux2 = l2;
    while (aux2) {
        newlist = insert(newlist, aux2->val);
        aux2 = aux2->next;
    } 

    return newlist;

}

ListNode* intersection(ListNode* l1, ListNode* l2) {

    ListNode* newlist = NULL;

    for (ListNode* i = l1; i != NULL; i = i->next) {
        for (ListNode* j = l2; j != NULL; j = j->next) {
            if (i->val == j->val) {
                ListNode* element = malloc(sizeof(ListNode));
                element->val = i->val;
                element->next = NULL;

                if (newlist == NULL)
                    newlist = element;
                else {
                    ListNode* tmp = newlist;
                    while (tmp->next != NULL)
                        tmp = tmp->next;
                    tmp->next = element;
                }
                break;
            }
        }
    }

    return newlist;
}

ListNode* Interleave(ListNode* l1, ListNode* l2) {

    ListNode* newlist = NULL;
    ListNode *l1aux = l1, *l2aux = l2;

    while (l1aux && l2aux) {
        ListNode* elementl1 = malloc(sizeof(ListNode));
        ListNode* elementl2 = malloc(sizeof(ListNode));
        elementl2->val = l2aux->val;
        elementl2->next = NULL;
        elementl1->val = l1aux->val;
        elementl1->next = elementl2;

        if (newlist == NULL)
            newlist = elementl1;
        else {
            ListNode* tmp = newlist;
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = elementl1;
        }

        l2aux = l2aux->next;
        l1aux = l1aux->next;
    }

    // if there is any element left
    while (l1aux) {
        ListNode* element = malloc(sizeof(ListNode));
        element->val = l1aux->val;
        element->next = NULL;

        ListNode* tmp = newlist;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = element;

        l1aux = l1aux->next;
    }

    while (l2aux) {
        ListNode* element = malloc(sizeof(ListNode));
        element->val = l2aux->val;
        element->next = NULL;

        ListNode* tmp = newlist;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = element;

        l2aux = l2aux->next;
    }

    return newlist;

}

ListNode* mergeneatly(ListNode* l1, ListNode* l2) {

    ListNode* newlist = NULL;
    ListNode *l1aux = l1, *l2aux = l2;

    while (l1aux && l2aux) {
        ListNode* elementl1 = malloc(sizeof(ListNode));
        ListNode* elementl2 = malloc(sizeof(ListNode));

        if (l1aux->val <= l2aux->val) {
            elementl2->val = l2aux->val;
            elementl2->next = NULL;
            elementl1->val = l1aux->val;
            elementl1->next = elementl2;
        } else {
            elementl2->val = l1aux->val;
            elementl2->next = NULL;  
            elementl1->val = l2aux->val;
            elementl1->next = elementl2;           
        }

        if (newlist == NULL)
            newlist = elementl1;
        else {
            ListNode* tmp = newlist;
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = elementl1;
        }

        l2aux = l2aux->next;
        l1aux = l1aux->next;
    }

    // if there is any element left
    while (l1aux) {
        ListNode* element = malloc(sizeof(ListNode));
        element->val = l1aux->val;
        element->next = NULL;

        ListNode* tmp = newlist;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = element;

        l1aux = l1aux->next;
    }

    while (l2aux) {
        ListNode* element = malloc(sizeof(ListNode));
        element->val = l2aux->val;
        element->next = NULL;

        ListNode* tmp = newlist;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = element;

        l2aux = l2aux->next;
    }

    return newlist;    

}