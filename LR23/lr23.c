#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

int FindNode(TreeNode *node, int value);
TreeNode *InsertNode(TreeNode *node, int value);
void PrintNode(TreeNode *node, int level);
TreeNode *DeleteNode(TreeNode *node, int value);
int ListCounter(TreeNode *node);
TreeNode *CleanNode(TreeNode *node);

int main() {

    TreeNode *tree = NULL;
    int operation = -1;
    printf("ENTER : [0] - break program, [1] - Insert node, [2] - Delete node, [3] - Count leaves, [4] - Clean tree, [5] - Find element, [6] - Print tree\n");
    while (scanf("%d", &operation) == 1 && operation != 0) {
        if (operation == 1) {
            printf("-------------------------------------------------------------------------------------\n");
            printf("ENTER NUMBER FOR INNSERT\n");
            int node = 0;
            scanf("%d", &node);
            if (FindNode(tree, node) != 1) {
                tree = InsertNode(tree, node);
                printf("THE NUMBER WAS INSERT TO TREE\n");
            } else {
                printf("THIS NUMBER ALMOST IN TREE\n");
            }
            printf("-------------------------------------------------------------------------------------\n");
            
        } else if(operation == 2) {
            printf("-------------------------------------------------------------------------------------\n");
            printf("ENTER NUMBER FOR DELETE\n");
            int delNode = 0;
            scanf("%d", &delNode);
            if (FindNode(tree, delNode) == 1) {
                tree = DeleteNode(tree, delNode);
                printf("THE NUMBER WAS DELETED FROM TREE\n");
            } else {
                printf("THIS NUMBER IS NOT IN TREE\n");
            }
            printf("-------------------------------------------------------------------------------------\n");
        } else if (operation == 3) {
            printf("-------------------------------------------------------------------------------------\n");
            printf("THERE IS %d LEAVES IN TREE\n", ListCounter(tree));
            printf("-------------------------------------------------------------------------------------\n");
        } else if (operation == 4) {
            printf("-------------------------------------------------------------------------------------\n");
            tree = CleanNode(tree);
            printf("THE TREE IS EMPTY NOW\n");
            printf("-------------------------------------------------------------------------------------\n");
        } else if (operation == 5) {
            printf("-------------------------------------------------------------------------------------\n");
            printf("ENTER NUMBER FOR FOUND: ");
            int foundNumber = 0;
            scanf("%d", &foundNumber);
            if (FindNode(tree, foundNumber) == 1) {
                printf("NUMBER FOUND WAS SUCCESED\n");
            } else {
                printf("NUMBER FOUND WAS DICLINED\n");
            }
            printf("-------------------------------------------------------------------------------------\n");
        } else if (operation == 6) {
            printf("-------------------------------------------------------------------------------------\n");
            PrintNode(tree, 0);
            printf("-------------------------------------------------------------------------------------\n");
        }
        printf("ENTER : [0] - break program, [1] - Insert node, [2] - Delete node, [3] - Count leaves, [4] - Clean tree, [5] - Find element, [6] - Print tree\n");
    }
    tree = CleanNode(tree);
    return 0;
    

}

int FindNode(TreeNode *node, int value) { //возвращаем 1 или 0 (0 если нет элемента, 1 - если есть)
    if (node == NULL) {
        return 0;
    }
    if (node->data == value) {
        return 1;
    } else if (value < node->data) {
        return FindNode(node->left, value);
    } else if (value > node->data) {
        return FindNode(node->right, value);
    }
    return -1;
}

TreeNode *InsertNode(TreeNode *node, int value) {
    if (FindNode(node, value) != 1) {
        if (node == NULL) {
            TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }
        if (value < node->data) {
            node->left = InsertNode(node->left, value);
        } else if (value > node->data) {
            node->right = InsertNode(node->right, value);
        } 
        return node;
    }
    return node;
}

TreeNode *FindMinimal(TreeNode *node) {
    if (node == NULL) {
        return NULL;
    } else {
        while(node->left != NULL) {
        node = node->left;
        }
    }
    return node;
}

TreeNode *DeleteNode(TreeNode *node, int value) {
    if (node == NULL) {
        return NULL;
    }
    if (value < node->data) {
        node->left = DeleteNode(node->left, value);
    } else if (value > node->data) {
        node->right = DeleteNode(node->right, value);
    } else {
        if (node->left == NULL) {
            TreeNode *successor = node->right;
            free(node);
            return successor;
        } else if (node->right == NULL) {
            TreeNode *successor = node->left;
            free(node);
            return successor;
        } else {
            TreeNode *successor = FindMinimal(node->right);
            node->data = successor->data;
            node->right = DeleteNode(node->right, successor->data);
            return node;
        }
    }
    return node;
}

int ListCounter(TreeNode *node) {
    if (node == NULL) {
        return 0;
    }
    if (node->left == NULL && node->right == NULL) {
        return 1;
    }
    int leftCounter = ListCounter(node->left);
    int rightCounter = ListCounter(node->right);

    return leftCounter + rightCounter;
}

TreeNode *CleanNode(TreeNode *node) {
    if (node == NULL) {
        return NULL;
    }
    CleanNode(node->left);
    CleanNode(node->right);
    free(node);
    return NULL;
}

void PrintNode(TreeNode *node, int level) {
    if (node == NULL) {
        return;
    }
    PrintNode(node->right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("   ");
    }
    printf("%d\n", node->data);
    PrintNode(node->left, level + 1);
}