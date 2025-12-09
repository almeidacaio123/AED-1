#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

void insert(Node **table, int index, int val) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->val = val;
    new_node->next = NULL;

    if (table[index] == NULL) {
        table[index] = new_node;
    } else {
        Node *temp = table[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_table(Node **table, int m) {
    for (int i = 0; i < m; i++) {
        printf("%d -> ", i);
        Node *temp = table[i];
        while (temp != NULL) {
            printf("%d -> ", temp->val);
            temp = temp->next;
        }
        printf("\\\n");
    }
}

void free_table(Node **table, int m) {
    for (int i = 0; i < m; i++) {
        Node *current = table[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    int n, m, c, val;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &m, &c);
        
        Node **table = (Node**) calloc(m, sizeof(Node*));

        for (int j = 0; j < c; j++) {
            scanf("%d", &val);
            insert(table, val % m, val);
        }

        print_table(table, m);
        
        if (i < n - 1) printf("\n");
        
        free_table(table, m);
        free(table);
    }

    return 0;
}
