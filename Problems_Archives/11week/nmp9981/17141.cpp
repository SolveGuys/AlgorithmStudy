#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n,m;
const int maxi = 51;
const int inf = 100000000;
int maps[maxi][maxi];//연구소 지도
int visit[maxi][maxi];//방문시간
queue<pair<int,int>> q;//큐 생성
vector<pair<int,int>> virus;//초기 바이러스 목록
vector<pair<int,int>> active_virus;//활성화 바이러스 목록
int ans = inf;//정답
//축이동
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

//입력
void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maps[i][j];
            if(maps[i][j]==2){//초기 바이러스 넣기
                virus.push_back({i,j});
            }
        }
    }
}

//바이러스 확산
int bfs(){
    memset(visit,-1,sizeof(visit));//초기화
    //초기 활성화 바이러스 넣기
    for(int k=0;k<m;k++){
        int ax = active_virus[k].first;
        int ay = active_virus[k].second;
        visit[ax][ay] = 0;
        q.push({ax,ay});
    }
    
    int maxi_time = 0;
    while(!q.empty()){
        //현재지점
        int x = q.front().first;
        int y = q.front().second;
        maxi_time = max(visit[x][y],maxi_time);//시간갱신
        q.pop();
        
        //다음지점
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            //범위내에 들고 미방문
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                //벽이 아닐경우
                if(visit[nx][ny]==-1 && maps[nx][ny]!=1){
                    q.push({nx,ny});//다음지점
                    visit[nx][ny] = visit[x][y] + 1;//방문체크
                }
            }
        }
    }
    //검사
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //벽이 아닌데 미방문
            if(visit[i][j]==-1 && maps[i][j]!=1){
                return inf;
            }
        }
    }
    return maxi_time;
}

//바이러스 선택
void select_virus(int idx,int cnt){
    //모두 선택하면 확산
    if(cnt==m){
        ans = min(ans,bfs());
        return;
    }
    for(int i=idx;i<virus.size();i++){//전체바이러스 중 선택
        int vx = virus[i].first;
        int vy = virus[i].second;
        active_virus.push_back({vx,vy});//바이러스 넣기
        select_virus(i+1,cnt+1);//재귀
        active_virus.pop_back();//원래대로
    }
}

int main(){
    input();//입력
    select_virus(0,0);//바이러스 인덱스, 개수
    //출력
    if(ans==inf){
        cout<<-1;
    }else{
        cout<<ans;
    }
    return 0;
}
