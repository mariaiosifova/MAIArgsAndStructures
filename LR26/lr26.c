#include <stdio.h>
#include "stack.h"

int main() {
    int n = -1;
    Stack myStack;
    StackCreate(&myStack);
    printf("ENTER THE NUMBER TYPE OF OPERATION: [0] - EXIT, [1] - ADD ELEM, [2] - REMOVE TOP ELEM, [3] - CLEAR STACK, [4] - EMPTY/NOT EMPTY STACK, [5] - PRINT STACK, [6] - SORT STACK\n");
    while(scanf("%d", &n) == 1 && n != 0) {
        printf("--------------------------------------------------------------------------\n");
        if (n == 1) {
            printf("ENTER YOUR KEY AND VALUE: ");
            int key = 0;
            int value = 0;
            scanf("%d %d", &key, &value);
            StackPush(&myStack, key, value);
        } else if (n == 2) {
            dataType dt = StackPop(&myStack);
            printf("THE TOP ELEM WAS REMOVED\n");
        } else if (n == 3) {
            StackDelete(&myStack);
            printf("ALL STACK WAS DELETED\n");
        } else if (n == 4) {
            if (StackIsEmpty(&myStack)) {
                printf("STACK IS EMPTY\n");
            } else {
                printf("STACK IS NOT EMPTY\n");
            }
        } else if (n == 5) {
            printf("YOUR STACK IS:\n");
            StackPrint(&myStack);
        } else if (n == 6) {
            printf("YOUR STACK WAS SORTED\n");
            printf("BEFORE\n");
            StackPrint(&myStack);
            printf("AFTER\n");
            StackSort(&myStack);
            StackPrint(&myStack);
        }
        printf("--------------------------------------------------------------------------\n");
        printf("ENTER THE NUMBER TYPE OF OPERATION: [0] - EXIT, [1] - ADD ELEM, [2] - REMOVE TOP ELEM, [3] - CLEAR STACK, [4] - EMPTY/NOT EMPTY STACK, [5] - PRINT STACK, [6] - SORT STACK\n");
    }

}