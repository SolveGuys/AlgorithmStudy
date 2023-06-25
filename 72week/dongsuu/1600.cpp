#include <iostream>
#include <tuple>
#include <queue>
#include <limits.h>

using namespace std;

int K, W, H;
int map[201][201];
int dx[12] = {0, -1, 0, 1, -1, -2, -2, -1, 1, 2, 2, 1};
int dy[12] = {-1, 0, 1, 0, -2, -1, 1, 2, 2, 1, -1, -2};
int dist[201][201][31]; // x, y, horse run cnt
queue<tuple<int, int, int>> q;
int ans = INT_MAX;

void bfs(int startX, int startY){
    q.push({startX, startY, 0});
    dist[startX][startY][0] = 0;
    
    while(!q.empty()){
        auto [x,y,c] = q.front(); // c: horse run count
        q.pop();
        
        if(x == H-1 && y == W-1){
            if(ans > dist[x][y][c]) ans = dist[x][y][c];
        }
        
        for(int i=0; i<12; i++){ // 0,1,2,3 -> 상하좌우 일반 이동 |  4 ~ 11 -> horse run
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            int nextC = c;
            if(nextC == K && i>3) continue; // horse run 다 쓰면 horse run하는 거는 넘김.
            if(i > 3 && nextC <= K) nextC += 1; // horse run 가능한 경우
            
            // Out of Map
            if(nextX < 0 || nextY < 0 || nextX >= H || nextY >= W) continue;
            
            // bfs
            if(map[nextX][nextY] == 0 && dist[nextX][nextY][nextC] < 0){
                q.push({nextX, nextY, nextC});
                dist[nextX][nextY][nextC] = dist[x][y][c] + 1;
            }
        }
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0; i<201; i++)
        for(int j=0; j<201; j++)
            fill(dist[i][j], dist[i][j] + 31, -1);
    
    cin >> K;
    cin >> W >> H;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> map[i][j];
        }
    }
    
    bfs(0, 0);
    if(ans == INT_MAX) cout << -1;
    else cout << ans;
    
    
    return 0;
}
