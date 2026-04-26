#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} dataType;

typedef struct Stack{
    dataType arr[100];
    int top;
} Stack;

void StackCreate(Stack *stack);
bool StackIsEmpty(const Stack *stack);
void StackPush(Stack *stack, int key, int value);
dataType StackPeek(Stack *stack);
dataType StackPop(Stack *stack);
void StackPrint(const Stack *stack);
void StackDelete(Stack *stack);
size_t StackSize(const Stack *stack);
void StackMerge(Stack *src1, Stack *src2, Stack *result);
void StackSort(Stack *stack);

#endif