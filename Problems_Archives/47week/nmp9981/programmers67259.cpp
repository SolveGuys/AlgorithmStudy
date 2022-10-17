#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int maxi = 26;
const int inf = 500000000;
int boardSize;
queue<pair<pair<int,int>,int>> q;//위치, 방향
int cost[maxi][maxi][4];//가격
//동남서북
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

//min
inline int min(int x,int y){
    return x>y?y:x;
}
//초기화
void init(vector<vector<int>> board){
    boardSize = board.size();
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            for(int k=0;k<4;k++) cost[i][j][k] = inf;
        }
    }
    for(int i=0;i<4;i++){//초기 방향 정보
        q.push({{0,0},i});
        cost[0][0][i] = 0;
    }
}
//길 설치
void roadInstall(vector<vector<int>> board){
    while(!q.empty()){
        int x = q.front().first.first;//현재 위치
        int y = q.front().first.second;
        int dir = q.front().second;//현재 방향
        q.pop();
        
        //다음 지점
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 || nx>=boardSize || ny<0 || ny>=boardSize) continue;//범위 조건
            if(board[nx][ny]==1) continue;//벽
            
            if((dir-i+4)%2==1){//코너
                if(cost[nx][ny][i]>cost[x][y][dir]+600){//갱신
                    cost[nx][ny][i] = cost[x][y][dir]+600;
                    q.push({{nx,ny},i});
                }
            }else{//직선
                if(cost[nx][ny][i]>cost[x][y][dir]+100){//갱신
                    cost[nx][ny][i] = cost[x][y][dir]+100;
                    q.push({{nx,ny},i});
                }
            }
        }
    }
}
int solution(vector<vector<int>> board) {
    init(board);//초기화
    roadInstall(board);//길 설치
    
    int answer = inf;
    for(int i=0;i<4;i++) answer = min(cost[boardSize-1][boardSize-1][i],answer);//최솟값
    return answer;
}
