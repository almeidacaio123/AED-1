#include <stdio.h>
#include <string.h>

#define MAX 10005

int visited[MAX];
int dist[MAX];
int queue[MAX * 2];

int reverse(int n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

int bfs(int start, int target) {
    int front = 0, rear = 0;
    
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));

    queue[rear++] = start;
    visited[start] = 1;
    dist[start] = 0;

    while (front < rear) {
        int u = queue[front++];

        if (u == target) return dist[u];

        int v1 = u + 1;
        if (v1 < MAX && !visited[v1]) {
            visited[v1] = 1;
            dist[v1] = dist[u] + 1;
            queue[rear++] = v1;
        }

        int v2 = reverse(u);
        if (v2 < MAX && !visited[v2]) {
            visited[v2] = 1;
            dist[v2] = dist[u] + 1;
            queue[rear++] = v2;
        }
    }
    return -1;
}

int main() {
    int T, A, B;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &A, &B);
        printf("%d\n", bfs(A, B));
    }
    return 0;
}
