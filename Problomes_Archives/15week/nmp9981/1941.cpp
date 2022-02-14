#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

string maps[5];//자리
bool selected[25];//조합 선택
bool visit[5][5];//방문체크
int ans = 0;//경우의 수
//축이동
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

//입력
void input(){
    for(int i=0;i<5;i++){
        cin>>maps[i];
    }
    memset(selected,false,sizeof(selected));//초기화
}

//연결
bool bfs(){
    //첫원소 넣기
    memset(visit,false,sizeof(visit));//초기화
    queue<pair<int,int>> q;
    for(int i=0;i<25;i++){
        if(selected[i]==true){
            q.push({i/5,i%5});
            visit[i/5][i%5] = true;//방문체크
            break;
        }
    }
    int cnt = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        //다음지점
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            //범위밖
            if(nx<0 || nx>=5 || ny<0 || ny>=5){
                continue;
            }
            //미방문이고 팀 조합에 포함되어 있음
            if(visit[nx][ny]==false && selected[5*nx+ny]==true){
                visit[nx][ny] = true;
                q.push({nx,ny});
                cnt++;
            }
        }
    }
    //팀이 모두 연결되었는가?
    if(cnt==7){
        return true;
    }
    return false;
}

//이다솜파
bool is_som(){
    int yeon = 0;//연파
    for(int i=0;i<25;i++){
        if(selected[i]==true){
            if(maps[i/5][i%5]=='Y'){
                yeon++;
            }
        }
    }
    if(yeon>=4){//연파가 우세한가?
        return false;
    }
    return true;
}

//조합 구하기
void dfs(int idx,int cnt){
    if(cnt==7){
        if(is_som()){//이다솜파
            if(bfs()){//연결
                ans++;
            }
        }
        return;
    }

    //조합 넣기
    for(int i=idx;i<25;i++){
        selected[i] = true;
        dfs(i+1,cnt+1);
        selected[i] = false;
    }
}

int main(){
    input();//입력
    dfs(0,0);//조합구하기
    cout<<ans;
    return 0;
}
