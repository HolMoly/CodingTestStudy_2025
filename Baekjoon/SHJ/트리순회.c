/* input
    // 첫번째 줄(N) : 노드의 개수
    // 두번째 줄부터 N개의 줄 : 각 노드와 왼쪽, 오른쪽 자식 노드
    // 노드 이름 알파벳, 자식 없을 시 .
*/


/* output
    // 첫번째 줄에 전위 순회
    // 두번째 줄에 중위 순회
    // 세번째 줄에 후위 순회
*/

/* process
    // 트리 생성 : 부모 노드 기준 왼쪽, 오른쪽 자식 기록
    // 루트의 출력이 언제냐에 따라 전위, 중위, 후위
    // 순회 : 재귀함수 이용 / 출력문만 위치 조정

*/

#include <stdio.h>

#define MAX 26

char left[MAX];   // 왼쪽 자식
char right[MAX];  // 오른쪽 자식

void preorder(char node) {
    if (node == '.') return;
    printf("%c", node);             // 루트
    preorder(left[node - 'A']);     // 왼쪽
    preorder(right[node - 'A']);    // 오른쪽
}

void inorder(char node) {
    if (node == '.') return;
    inorder(left[node - 'A']);      // 왼쪽
    printf("%c", node);             // 루트
    inorder(right[node - 'A']);     // 오른쪽
}

void postorder(char node) {
    if (node == '.') return;
    postorder(left[node - 'A']);    // 왼쪽
    postorder(right[node - 'A']);   // 오른쪽
    printf("%c", node);             // 루트
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char parent, l, r;
        scanf(" %c %c %c", &parent, &l, &r);
        left[parent - 'A'] = l;
        right[parent - 'A'] = r;
    }

    preorder('A');
    printf("\n");
    inorder('A');
    printf("\n");
    postorder('A');
    printf("\n");

    return 0;
}
