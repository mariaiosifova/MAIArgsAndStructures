#include "stack.h"
#include <stdio.h>

void StackCreate(Stack *stack) {
    stack->top = -1;
}
bool StackIsEmpty(const Stack *stack) {
    if (stack->top == -1) {
        return true;
    } else {
        return false;
    }
}
size_t StackSize(const Stack *stack) {
    return stack->top + 1;
}

void StackPush(Stack *stack, int key, int value) {
    if (stack->top == 99) {
        printf("Stack overflow\n");
        return;
    } else {
        stack->top += 1;
        stack->arr[stack->top].key = key;
        stack->arr[stack->top].value = value;
    }
}
dataType StackPeek(Stack *stack) {
    if (stack->top == -1) {
        dataType error = {0, 0};
        return error;
    }
    return stack->arr[stack->top];
}
dataType StackPop(Stack *stack) {
    if (stack->top == -1) {
        printf("THE STACK IS EMPTY NOW\n");
        dataType error = {0, 0};
        return error;
    } else {
        dataType buffer = stack->arr[stack->top];
        stack->top -= 1;
        return buffer;
    }
}

void StackPrint(const Stack *stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%d %d\n", stack->arr[i].key, stack->arr[i].value);
    }
}
void StackDelete(Stack *stack) {
    stack->top = -1;
}

void StackMerge(Stack *src1, Stack *src2, Stack *result) {
    Stack tempStack;
    StackCreate(&tempStack);
    while(StackSize(src1) > 0 || StackSize(src2) > 0) {
        if (StackSize(src1) > 0 && StackSize(src2) > 0) {
            if (StackPeek(src1).key <= StackPeek(src2).key) {
                dataType dt = StackPop(src1);
                StackPush(&tempStack, dt.key, dt.value);
            } else {
                dataType dt = StackPop(src2);
                StackPush(&tempStack, dt.key, dt.value);
            }
        } else if (StackSize(src1) > 0) {
            dataType dt = StackPop(src1);
            StackPush(&tempStack, dt.key, dt.value);
        } else if (StackSize(src2) > 0) {
            dataType dt = StackPop(src2);
            StackPush(&tempStack, dt.key, dt.value);
        }
    }
    while (StackSize(&tempStack) > 0) {
        dataType dt = StackPop(&tempStack);
        StackPush(result, dt.key, dt.value);
    }
}

void StackSort(Stack *stack) {
    if (StackSize(stack) <= 1) {
        return;
    }
    
    Stack left;
    Stack right;
    StackCreate(&left);
    StackCreate(&right);

    int halfFirst = StackSize(stack) / 2;
    int halfSecond = StackSize(stack);

    for (int i = 0; i < halfFirst; i++) {
        dataType dt = StackPop(stack);
        StackPush(&left, dt.key, dt.value);
    }
    for (int i = halfFirst; i < halfSecond; i++) {
        dataType dt = StackPop(stack);
        StackPush(&right, dt.key, dt.value);
    }

    StackSort(&left);
    StackSort(&right);

    StackMerge(&right, &left, stack);
}