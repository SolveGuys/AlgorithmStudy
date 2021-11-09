#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <chrono>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

using namespace std;//이름공간 선언
int n,m;
const int maxi = 50;
const int inf = 10000000;
int map[maxi][maxi];//연구소
int visit[maxi][maxi];//방문배열
vector<pair<int,int>> virus;//바이러스
vector<pair<int,int>> active_virus;//활성 바이러스
int dx[] = {-1,1,0,0};//축이동
int dy[] = {0,0,-1,1};
int ans = inf;//결과

//입력
void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
            if(map[i][j]==2){//비활성 바이러스 넣기
                virus.push_back({i,j});
            }
        }
    }
}

//bfs
int bfs(){
    //방문 배열 초기화
    memset(visit,-1,sizeof(visit));
    
    //활성화 바이러스를 모두 큐에 넣기
    queue<pair<int,int>> q;//시간, 위치
    for(int j=0;j<active_virus.size();j++){
        int ax = active_virus[j].first;
        int ay = active_virus[j].second;
        visit[ax][ay] = 0;//처음 지점
        q.push({ax,ay});
    }
    
    int times = 0;//시간
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        //다음지점
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            //범위내에 있고 빈공간
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                //비활성 바이러스를 만나면 활성으로
                if(visit[nx][ny]==-1 && map[nx][ny]!=1){
                    visit[nx][ny] = visit[x][y] + 1;//시간증가
                    q.push({nx,ny});
                    //빈공간이었다면
                    if(map[nx][ny]==0){
                        times = visit[nx][ny];
                    }
                }
            }
        }
    }
    //빈칸 확인
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j]==-1 && map[i][j]!=1){//빈공간이 남았으면
                return inf;
            }
        }
    }
    return times;//빈공간이 없으면
}

//바이러스 조합선택
void select_virus(int idx,int cnt){
    if(cnt==m){//m개 조합
        ans = min(ans,bfs());
        return;
    }
    
    //바이러스 고르기
    for(int i=idx;i<virus.size();i++){
        int vx = virus[i].first;//바이러스 위치
        int vy = virus[i].second;
        active_virus.push_back({vx,vy});//활성화 바이러스 넣기
        select_virus(i+1,cnt+1);//재귀
        active_virus.pop_back();//원래대로
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);

    input();//입력
    select_virus(0,0);//시작위치, 활성화 바이러스 개수
    //결과
    if(ans<inf){//빈칸없이 퍼뜨리기 가능
        cout<<ans;
    }else{//불가능
        cout<<-1;
    }
    return 0;
}
