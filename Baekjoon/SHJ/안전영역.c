/* input
// 첫 번째 줄(N) : 지역의 크기 (행, 열의 개수) — 2 이상 100 이하
    // 두 번째 줄부터 N개의 줄 : 각 지역의 높이 정보를 나타내는 자연수 N개
    // 높이는 1 이상 100 이하의 자연수
*/


/* output
    // 물에 잠기지 않는 안전한 영역의 최대 개수
*/


/* process
    // 1. 입력된 높이 정보를 2차원 배열 저장
    // 2. 전체 높이 중에서 최솟값 ~ 최댓값까지 모든 비의 높이에 대해 반복
    // 3. 해당 높이보다 높은 지점만 탐색 대상 :  DFS로 영역을 탐색
    // 4. 방문하지 않았고, 현재 높이보다 높은 지점일 때 -> 안전 영역 개수 증가 및 DFS 수행
    // 5. 매 높이마다 안전 영역 개수를 계산 -> 최대값 갱신
*/


#include <stdio.h>

#define MAX 100

int N;
int map[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {0, 0, -1, 1};   // 상하좌우
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y, int rainLevel) {
    visited[x][y] = 1;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
            if (!visited[nx][ny] && map[nx][ny] > rainLevel) {
                dfs(nx, ny, rainLevel);
            }
        }
    }
}

int main() {
    scanf("%d", &N);

    int maxHeight = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] > maxHeight) {
                maxHeight = map[i][j];
            }
        }
    }

    int maxSafeZone = 0;

    for (int h = 0; h <= maxHeight; h++) {
        // visited 초기화
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                visited[i][j] = 0;

        int safeCount = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && map[i][j] > h) {
                    dfs(i, j, h);
                    safeCount++;
                }
            }
        }

        if (safeCount > maxSafeZone)
            maxSafeZone = safeCount;
    }

    printf("%d\n", maxSafeZone);
    return 0;
}
