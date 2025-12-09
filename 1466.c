#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

// Funções da Árvore
Node* create_node(int val) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert(Node* root, int val) {
    if (root == NULL) return create_node(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void free_tree(Node* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

// Fila para BFS
typedef struct QueueNode {
    Node* tree_node;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} Queue;

void enqueue(Queue* q, Node* t_node) {
    QueueNode* new_node = (QueueNode*) malloc(sizeof(QueueNode));
    new_node->tree_node = t_node;
    new_node->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

Node* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    Node* item = temp->tree_node;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return item;
}

int main() {
    int C, N, val;
    scanf("%d", &C);

    for (int i = 1; i <= C; i++) {
        scanf("%d", &N);
        Node* root = NULL;
        for (int j = 0; j < N; j++) {
            scanf("%d", &val);
            root = insert(root, val);
        }

        printf("Case %d:\n", i);
        
        // BFS
        Queue q = {NULL, NULL};
        enqueue(&q, root);
        int first = 1;

        while (q.front != NULL) {
            Node* current = dequeue(&q);
            if (!first) printf(" ");
            printf("%d", current->val);
            first = 0;

            if (current->left) enqueue(&q, current->left);
            if (current->right) enqueue(&q, current->right);
        }
        printf("\n\n");

        free_tree(root);
    }
    return 0;
}
