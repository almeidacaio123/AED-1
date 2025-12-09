#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, char data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

void infixa(Node* root, int* first) {
    if (root != NULL) {
        infixa(root->left, first);
        if (*first) {
            printf("%c", root->data);
            *first = 0;
        } else {
            printf(" %c", root->data);
        }
        infixa(root->right, first);
    }
}

void prefixa(Node* root, int* first) {
    if (root != NULL) {
        if (*first) {
            printf("%c", root->data);
            *first = 0;
        } else {
            printf(" %c", root->data);
        }
        prefixa(root->left, first);
        prefixa(root->right, first);
    }
}

void posfixa(Node* root, int* first) {
    if (root != NULL) {
        posfixa(root->left, first);
        posfixa(root->right, first);
        if (*first) {
            printf("%c", root->data);
            *first = 0;
        } else {
            printf(" %c", root->data);
        }
    }
}

int search(Node* root, char data) {
    if (root == NULL) {
        return 0;
    }
    
    if (data == root->data) {
        return 1;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    char line[20];
    char command[10];
    char data;
    
    while (fgets(line, sizeof(line), stdin) != NULL) {
        if (sscanf(line, "%s", command) == 1) {
            if (strcmp(command, "I") == 0) {
                sscanf(line, "%s %c", command, &data);
                root = insert(root, data);
            } else if (strcmp(command, "INFIXA") == 0) {
                int first = 1;
                infixa(root, &first);
                printf("\n");
            } else if (strcmp(command, "PREFIXA") == 0) {
                int first = 1;
                prefixa(root, &first);
                printf("\n");
            } else if (strcmp(command, "POSFIXA") == 0) {
                int first = 1;
                posfixa(root, &first);
                printf("\n");
            } else if (strcmp(command, "P") == 0) {
                sscanf(line, "%s %c", command, &data);
                if (search(root, data)) {
                    printf("%c existe\n", data);
                } else {
                    printf("%c nao existe\n", data);
                }
            }
        }
    }
    
    freeTree(root);
    return 0;
}
