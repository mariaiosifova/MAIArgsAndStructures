#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Iterator {
    Node *current;
} Iterator;

void PrintList(Node* head) {
    if (!head) {
        printf("The List is empty\n");
        return;
    }
    Iterator iterator;
    iterator.current = head;
    while (iterator.current != NULL) {
        printf("%d->", iterator.current->data);
        iterator.current = iterator.current->next;
    }
    printf("\n");
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

int main() {
    Node *list = NULL;

    printf("HI, it is interface!\n");
    printf("Choose your mode and start using comfort!\n");

    int mode;
    printf("0-end program\n1-insert element\n2-delete element\n3-get List length\n4-print List\n5-shift List\n");
    scanf("%d", &mode);
    while(mode != 0) {
        if (mode == 1) {
            int value;
            printf("Enter element for insert\n");
            scanf("%d", &value);
            InsertEnd(&list, value);
        } else if (mode == 2) {
            int value;
            printf("Enter element for delete\n");
            scanf("%d", &value);
            DeleteNode(&list, value);
        } else if (mode == 3) {
            printf("List length is %d\n", ListLength(list));
        } else if (mode == 4) {
            PrintList(list);
        } else if (mode == 5) {
            CycleShift(&list);
            printf("List had shifted\n");
        } else {
            printf("Bad mode\n");
        }
        printf("0-end program\n1-insert element\n2-delete element\n3-get List length\n4-print List\n5-shift List\n");

        scanf("%d", &mode);
    }
    free(list);
    return 0;
}