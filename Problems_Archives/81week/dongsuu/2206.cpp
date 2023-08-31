#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int N, M;
int map[1005][1005];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int visited[1005][1005][2]; // [x][y][broken_count]
queue<tuple<int, int, int>> q;
int minValue = 987654321;

void bfs(int startX, int startY){
    q.push({startX, startY, 0});
    visited[startX][startY][0] = 1;
    visited[startX][startY][1] = 1;
    
    while(!q.empty()){
        auto [x, y, broken] = q.front();
        q.pop();
        
        if(x == N-1 && y == M-1){
            minValue = std::min(minValue, visited[x][y][broken]);
        }
        
        for(int i=0; i<4; i++){
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if(nextX < 0 || nextY < 0 || nextX>=N || nextY >= M) continue;
            if(visited[nextX][nextY][broken] == 0){
                if(map[nextX][nextY] == 1 && broken == 0){ // 벽 아직 안부순 상태이면서 다음이 벽일 때 -> 부수고 움직임
                    q.push({nextX, nextY, 1});
                    visited[nextX][nextY][1] = visited[x][y][0] + 1;
                } else if(map[nextX][nextY] == 1 && broken == 1){ // 벽 부순 상태인데 다음이 벽일 때 -> 이동 못함
                    continue;
                } else {
                    q.push({nextX, nextY, broken});
                    visited[nextX][nextY][broken] = visited[x][y][broken] + 1;
                }
            }
        }
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string line;
        cin >> line;
        for(int j=0; j<M; j++){
            map[i][j] = line[j] - '0';
        }
    }
    
    bfs(0, 0);
    if(minValue == 987654321) cout << -1 << '\n';
    else cout << minValue << '\n';
    
    
    
    return 0;
}