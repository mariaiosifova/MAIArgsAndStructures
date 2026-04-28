#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Iterator {
    Node *current;
} Iterator;

void PrintList(Node* head, Iterator* current) {
    if (!head) {
        printf("The List is empty\n");
        return;
    }
    Iterator iterator;
    iterator.current = head;
    while (iterator.current != NULL) {
        if (iterator.current == current->current) {
            printf("[%d]->", iterator.current->data);
        } else {
        printf("%d->", iterator.current->data);
        }
        iterator.current = iterator.current->next;
    }
    printf("NULL\n");
}
void InsertAfter(Iterator* iter, int value) {
    if (iter == NULL || iter->current == NULL) {
        return; 
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = iter->current->next;
    iter->current->next = newNode;
}
int ListLength(Node* head) {
    int listLength = 0;
    if (!head) {
        return listLength;
    }
    Iterator iterator;
    iterator.current = head;
    while(iterator.current != NULL) {
        listLength += 1;
        iterator.current = iterator.current->next;
    }
    return listLength;
}

void InsertEnd(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while(temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void DeleteNode(Node** head, int value) {
    Node* temp = *head;
    Node* prev = NULL;
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);

}

void CycleShift(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    temp->next = *head;
    *head = temp;
}

void ClearList(Node** head) {
    Node* current = *head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}
int main() {
    Node *list = NULL;
    Iterator myPosition;
    myPosition.current = NULL;

    printf("HI, it is interface!\n");
    printf("Choose your mode and start using comfort!\n");

    int mode;
    printf("0-end program\n1-insert element\n2-delete element\n3-get List length\n4-print List\n5-shift List\n6-move next\n7-move prev\n");
    scanf("%d", &mode);
    while(mode != 0) {
        if (mode == 1) {
            int value;
            printf("Enter element for insert\n");
            scanf("%d", &value);
            if (list == NULL) {
                InsertEnd(&list, value);
            } else {
                InsertAfter(&myPosition, value);
            }
            
            if (myPosition.current == NULL) {
                myPosition.current = list;
            }
        } else if (mode == 2) {
            int value;
            printf("Enter element for delete\n");
            scanf("%d", &value);
            DeleteNode(&list, value);
            myPosition.current = list;
        } else if (mode == 3) {
            printf("List length is %d\n", ListLength(list));
        } else if (mode == 4) {
            PrintList(list, &myPosition);
        } else if (mode == 5) {
            CycleShift(&list);
            printf("List had shifted\n");
            myPosition.current = list;
        } else if (mode == 6) {
            if (myPosition.current->next != NULL) {
                myPosition.current = myPosition.current->next;
            }
        } else if (mode == 7) {
            if (myPosition.current != list) {
                Node* temp = list;
                while(temp != NULL && temp->next != myPosition.current) {
                    temp = temp->next;
                }
                myPosition.current = temp;
            }
        } else {
            printf("Bad mode\n");
        }
        printf("0-end program\n1-insert element\n2-delete element\n3-get List length\n4-print List\n5-shift List\n6-move next\n7-move prev\n");
        scanf("%d", &mode);
    }

    ClearList(&list);
    return 0;
}