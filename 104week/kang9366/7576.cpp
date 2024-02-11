#include <iostream>
#include <queue>
#include <vector>

#define MAX 1000

using namespace std;

int M, N;
int arr[MAX][MAX];
bool visited[MAX][MAX] = {false,};
queue<pair<int, int>> q;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs() {
    int cnt = 0;

    while(!q.empty()) {
        int size = q.size();

        for(int i = 0; i < size; i++) {
            pair<int, int> cur = q.front();
            q.pop();

            for(int j = 0; j < 4; j++) {
                int nx = cur.first + dx[j];
                int ny = cur.second + dy[j];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                    if(arr[nx][ny] == 0) {
                    arr[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        cnt++;
    }

    int temp = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(arr[i][j] != 0) temp++;
        }
    }
    if(temp != M*N) {
        cout << -1;
    } else {
        cout << --cnt;
    }
}

int main() {
    cin >> M >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                q.push({i, j});
            }
        }
    }
    bfs();
}
