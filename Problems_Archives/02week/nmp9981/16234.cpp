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
int n,l,r;
int map[51][51];//세계지도
int visit[51][51];//방문여부
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

//입력
void input(){
    cin>>n>>l>>r;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
}

//국경선 열고 이동
bool bfs(int a,int b){
    bool flag = false;//이동이 일어났는가?
    queue<pair<int,int>> q;//큐
    queue<pair<int,int>> uni;//연합
    q.push({a,b});
    uni.push({a,b});
    visit[a][b] = 1;//방문체크
    int cnt = 1;//연합개수
    int total = map[a][b];//연합의 합
    
    while(!q.empty()){
        //현재위치
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        //다음지점 탐색
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            //미방문이고 범위내에 있으면
            if(visit[nx][ny]==0 && nx>=0 && nx<n && ny>=0 && ny<n){
                int diff = abs(map[nx][ny] - map[x][y]);
                //차이가 범위내에 있으면
                if(diff>=l && diff<=r){
                    visit[nx][ny] = 1;//방문체크
                    q.push({nx,ny});
                    uni.push({nx,ny});//연합추가
                    cnt++;//연합개수 증가
                    total+=map[nx][ny];//연합의 합 증가
                    flag = true;//이동이 일어났음
                }
            }
        }
    }
    //맵갱신
    int new_people = total/cnt;//이동후 결과
    while(!uni.empty()){
        map[uni.front().first][uni.front().second] = new_people;
        uni.pop();
    }
    return flag;
}

//인구이동
void people(){
    int day = 0;
    while(true){
        bool move_flag = false;//이동이 일어났는가?
        bool day_flag = false;//하루 더 필요한가?
        //방문기록 초기화
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visit[i][j] = 0;
            }
        }
        //국경선열기
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visit[i][j]==0){
                    move_flag = bfs(i,j);
                    if(move_flag == true){//이동이 일어났음
                        day_flag = true;//하루 더 필요함
                    }
                }
            }
        }
        //더 진행해야 하는가?
        if(day_flag==true){
            day++;
        }else{
            break;
        }
    }
    cout<<day;//답
}

int main(){
    cin.tie(0);
    cout.tie(0);

    input();//입력
    people();//인구 이동
    return 0;
}
