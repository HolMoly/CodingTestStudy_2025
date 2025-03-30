
/* input
   // 첫번째 줄 (N) : 노드의 개수
   // 두번째 ~ N-1 : 트리 상의 연결된 두 정점
*/


/* output
   // 각 노드의 부모 노드 번호를 출력 (2번 노드부터, 루트는 제외)
*/


/* process
   // 루트는 1
   // 부모 노드를 찾으려면, 트리를 완성해야 함.
   // 1과 연결된 노드들이 루트를 부모노드로 가진 노드들, 따라서, 1부터 BFS하면서 기록.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* adjList[MAX];  // 각 노드의 인접 노드 리스트
int parent[MAX];     // 부모 저장 배열
int visited[MAX];    // 방문 여부


void addEdge(int a, int b) {
    Node* newNodeA = (Node*)malloc(sizeof(Node));
    newNodeA->val = b;
    newNodeA->next = adjList[a];
    adjList[a] = newNodeA;

    Node* newNodeB = (Node*)malloc(sizeof(Node));
    newNodeB->val = a;
    newNodeB->next = adjList[b];
    adjList[b] = newNodeB;
}

int queue[MAX];
int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void bfs(int start) {
    visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        int curr = dequeue();
        Node* temp = adjList[curr];

        while (temp != NULL) {
            int next = temp->val;
            if (!visited[next]) {
                visited[next] = 1;
                parent[next] = curr;
                enqueue(next);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(a, b);
    }

    bfs(1);  // 루트는 1

    for (int i = 2; i <= N; i++) {
        printf("%d\n", parent[i]);
    }

    return 0;
}
