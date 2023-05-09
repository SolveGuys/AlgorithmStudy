#include <string>
#include <vector>
#include <queue>
using namespace std;

//위치 정보
struct Pos_Info{
    int r,c,dist;
};
const int maxi = 102;
int world[maxi][maxi];//지도
bool visit[maxi][maxi];//방문 여부
//4방 탐색
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

//맵 세팅
void MapSetting(vector<vector<int>> rectangle){
    //채우기
    for(int i=0;i<rectangle.size();i++){
        //시작 지점, 끝지점
        int startX = 2*rectangle[i][0];
        int startY = 2*rectangle[i][1];
        int endX = 2*rectangle[i][2];
        int endY = 2*rectangle[i][3];
        for(int i=startY;i<=endY;i++){
            for(int j=startX;j<=endX;j++) world[i][j] = 1;
        }
    }
    //속 없애기
    for(int i=0;i<rectangle.size();i++){
        //시작 지점, 끝지점
        int startX = 2*rectangle[i][0];
        int startY = 2*rectangle[i][1];
        int endX = 2*rectangle[i][2];
        int endY = 2*rectangle[i][3];
        for(int i=startY+1;i<=endY-1;i++){
            for(int j=startX+1;j<=endX-1;j++) world[i][j] = 0;
        }
    }
}

//아이템 줍기
int GetItem(int characterX, int characterY, int itemX, int itemY){
    queue<Pos_Info> q;
    q.push({2*characterY,2*characterX,0});
    visit[2*characterY][2*characterX] = true;
    
    while(!q.empty()){
        int r = q.front().r;
        int c = q.front().c;
        int dist = q.front().dist;
        q.pop();
        
        //도착
        if(r==2*itemY && c==2*itemX) return dist/2;
        
        //다음 지점
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr<0 || nr>=maxi || nc<0 || nc>=maxi) continue;//범위 조건
            if(visit[nr][nc]) continue;//방문 조건
            if(world[nr][nc]==0) continue;//길이 아님
            
            visit[nr][nc] = true;
            q.push({nr,nc,dist+1});
        }
    }
    return 0;
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    MapSetting(rectangle);//맵 세팅
    return GetItem(characterX,characterY,itemX,itemY);//아이템 줍기
}
