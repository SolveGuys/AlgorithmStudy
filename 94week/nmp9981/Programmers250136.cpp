#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<vector<int>> state;//상태
const int maxi = 501;
int row,col;//행, 열 크기
int world[maxi][maxi];//지도
int oilAmount[maxi*maxi];//각 덩어리 번호별 석유량
//4방 탐색
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

//max
inline int max(int a,int b){
    return a>b?a:b;
}
//기름 세기
void CountOil(int i,int j, int num){
    queue<pair<int,int>> q;
    q.push({i,j});
    world[i][j] = num;
    int cnt = 1;//석유 양
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        //다음 지점 탐색
        for(int k=0;k<4;k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx<0 || nx>=row || ny<0 || ny>=col) continue;//범위 조건
            if(world[nx][ny]>0) continue;//이미 방문
            if(state[nx][ny]==0) continue;//빈 땅
            
            cnt++;
            world[nx][ny] = num;
            q.push({nx,ny});
        }
    }
    oilAmount[num] = cnt;//석유양 기록
}
//맵 탐색
void MapSearch(){
    row = state.size();//행
    col = state[0].size();//열
    int num = 1;//덩어리 번호
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(world[i][j]==0 && state[i][j]==1) {
                CountOil(i,j,num);//기름 세기
                num++;
            }
        }
    }
}
//석유 추출
int ExtractOil(){
    int maxOil = 0;//최대 석유량
    for(int j=0;j<col;j++){//추출 위치
        int total = 0;//총 석유량
        set<int> oilLump;//석유 덩어리
        for(int i=0;i<row;i++) oilLump.insert(world[i][j]);
        
        for(auto k:oilLump) total+=oilAmount[k];//석유 개수 세기
        maxOil = max(maxOil,total);
    }
    return maxOil;
}
int solution(vector<vector<int>> land) {
    state = land;//맵 복사
    MapSearch();//맵 탐색
    return ExtractOil();//석유 추출
}
