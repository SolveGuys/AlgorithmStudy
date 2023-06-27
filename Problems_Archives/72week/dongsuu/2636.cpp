#include <iostream>
#include <queue>

using namespace std;

int H, W;
int map[101][101]; // 0: 치즈X, 1:치즈O, 2:Melting Cheese
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
queue<pair<int, int>> cq;
int pieces;

int getCheeseCnt(){
    int cnt = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(map[i][j] >= 1) cnt++;
        }
    }
    return cnt;
}

bool isMeltingCheese(int i, int j){
    // 상하좌우 탐색해서 공기랑 닿아있는지 판단. -> bfs로 회색 부분 닿으면 공기와 닿아있다고 판단 가능
    int visited[101][101];
    queue<pair<int, int>> q;
    
    for(int i=0; i<101; i++){
        fill(visited[i], visited[i] + 101, 0);
    }
    q.push({i, j});
    visited[i][j] = 1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            
            if(nextX <= 0 || nextY <= 0 || nextX >= H-1 || nextY >= W-1) return true;
            if(map[nextX][nextY] == 1) continue;
            if(map[nextX][nextY] == 0 && visited[nextX][nextY] == 0){
                visited[nextX][nextY] = 1;
                q.push({nextX, nextY});
            }
        }
    }
    
    return false;
    
}

bool isDone(){
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(map[i][j] >= 1) return false;
        }
    }
    return true;
}

void printMap(){
    cout << "-------------------------" << endl;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "-------------------------" << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> H >> W;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> map[i][j];
        }
    }
    
    int time = 0;
    while(1){
        // init
        while(!cq.empty()) cq.pop();
        
        // Check all cheese are melted
        if(isDone()){
            break;
        }
        
        // set Melting Cheese
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                if(map[i][j] == 1){
                    if(isMeltingCheese(i, j)){
                        map[i][j] = 2;
                    }
                }
            }
        }
        
        // get pieces of Cheese
        int cnt = 0;
        cnt = getCheeseCnt();
        if(cnt != 0) pieces = cnt;
        
        
        // Melting
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                if(map[i][j] == 2) map[i][j] = 0;
            }
        }
        
        time++;
    }
    
    cout << time << '\n';
    cout << pieces << '\n';
    
    
    return 0;
}
