#include <stdio.h>

#define MAX_N 100

int n, l;
int map[MAX_N][MAX_N]; // 맵 크기와 맵 배열 선언

// 경사로 설치 가능 여부 검사
int canInstall(int runway[]) {
    int visited[MAX_N] = {0}; // 방문 여부를 표시할 배열 초기화

    for (int i = 0; i < n - 1; ++i) {
        int diff = runway[i] - runway[i + 1]; // 현재 위치와 다음 위치의 높이 차이 계산

        if (diff == 0) continue; // 높이가 같으면 패스
        if (diff != 1 && diff != -1) return 0; // 차이가 1보다 크면 실패

        if (diff == 1) { // 현재 위치가 더 높은 경우
            for (int j = i + 1; j <= i + l; ++j) { // 경사로 설치 가능 여부 확인
                if (j >= n || runway[i + 1] != runway[j] || visited[j]) return 0; // 범위를 벗어나거나 높이가 다르거나 이미 방문한 경우 실패
                visited[j] = 1; // 방문 표시
            }
        } else { // 다음 위치가 더 높은 경우
            for (int j = i; j > i - l; --j) { // 경사로 설치 가능 여부 확인
                if (j < 0 || runway[i] != runway[j] || visited[j]) return 0; // 범위를 벗어나거나 높이가 다르거나 이미 방문한 경우 실패
                visited[j] = 1; // 방문 표시
            }
        }
    }

    return 1; // 용량 검사 통과
}

int main() {
    scanf("%d %d", &n, &l); // 입력: 맵의 크기와 경사로의 길이
    
    // 맵 입력 받기
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            scanf("%d", &map[y][x]);
        }
    }
    
    int ret = 0; // 결과 값 초기화

    // 행 용량 검사
    for (int y = 0; y < n; ++y) {
        int runway[MAX_N];
        for (int x = 0; x < n; ++x) {
            runway[x] = map[y][x]; // 행 복사
        }
        ret += canInstall(runway); // 경사로 설치 가능 여부 검사 후 결과에 더함
    }

    // 열 용량 검사
    for (int x = 0; x < n; ++x) {
        int runway[MAX_N];
        for (int y = 0; y < n; ++y) {
            runway[y] = map[y][x]; // 열 복사
        }
        ret += canInstall(runway); // 경사로 설치 가능 여부 검사 후 결과에 더함
    }
    
    printf("%d\n", ret); // 결과 출력
    
    return 0;
}
