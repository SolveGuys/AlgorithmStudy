#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int w,h,res;
const int maxi = 20;
const int inf = 1e+8;
char room[maxi][maxi];//방의 지도
bool visit[maxi][maxi];//방문여부
vector<pair<int,int>> graph;//먼지 모음
int dp[maxi][maxi];//i->j로 가는 최단거리
int dist[maxi][maxi];//bfs 최단거리
bool selected[maxi];//조합선택
//축이동
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

//입력
void input(int w,int h){
    //초기화
    res = inf;
    memset(dp,0,sizeof(dp));
    memset(selected,false,sizeof(selected));
    graph.clear();
    //입력
    for(int i=0;i<h;i++){
        scanf("%s",room[i]);
    }
    //시작지점
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(room[i][j]=='o'){
                graph.push_back({i,j});
            }
        }
    }
    //먼지넣기
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(room[i][j]=='*'){
                graph.push_back({i,j});
            }
        }
    }
}

//청소하기
void bfs(int start_x,int start_y){
    //초기위치
    queue<pair<int,int>> q;
    q.push({start_x,start_y});
    memset(visit,false,sizeof(visit));//초기화
    memset(dist,-1,sizeof(dist));//초기화
    visit[start_x][start_y] = true;
    dist[start_x][start_y] = 0;
    //탐색하기
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        //다음지점
        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            //범위내에 드는가?
            if(nx<0 || nx>=h || ny<0 || ny>=w){
                continue;
            }
            //가구가 아니고 미방문
            if(room[nx][ny]!='x' && visit[nx][ny]==false){
                visit[nx][ny] = true;
                q.push({nx,ny});
                dist[nx][ny] = dist[x][y]+1;
            }
        }
    }
}

//조합선택
void dfs(int start,int cnt,int sum){
    if(cnt==graph.size()-1){
        res = min(res,sum);//거리 갱신
        return;
    }
    //다음 번호
    for(int i=1;i<graph.size();i++){
        if(selected[i]==true) continue;
        selected[i] = true;
        int next = sum+dp[start][i];
        dfs(i,cnt+1,next);
        selected[i] = false;
    }
}

//로봇 탐색
void robot(){
    //각 지점을 시작지점으로 하여 bfs탐색
    for(int i=0;i<graph.size();i++){
        bfs(graph[i].first,graph[i].second);
        //i->j까지의 거리
        for(int j=0;j<graph.size();j++){
            dp[i][j] = dist[graph[j].first][graph[j].second];
            if(dp[i][j]==-1){//도달 불가
                cout<<-1<<"\n";
                return;
            }
        }
    }
    dfs(0,0,0);//조합선택
    cout<<res<<"\n";
}

int main(){
    while(1){
        cin>>w>>h;
        if(w==0 && h==0){//종료
            break;
        }else{
            input(w,h);//입력
            robot();//탐색시작
        }
    }
    return 0;
}
