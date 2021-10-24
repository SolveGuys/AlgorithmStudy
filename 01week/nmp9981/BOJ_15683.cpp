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
using namespace chrono;
int n,m;
vector<vector<int>> map(8,vector<int>(8,0));//지도원본
vector<pair<int,pair<int,int>>> camera;//감시카메라(번호, 위치)
int cctv_cnt = 0;//카메라 대수
int ans = 65;//사각지대 최솟값

//입력
void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]>=1 && map[i][j]<=5){
                camera.push_back({map[i][j],{i,j}});//번호,위치
                cctv_cnt++;//카메라 대수 증가
            }
        }
    }
}

//사각지대개수 세기
void area_count(){
    int result = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==0){//사각지대
                result++;
            }
        }
    }
    ans = min(result,ans);
}

//방향 탐색
void move(int dir,int x,int y){//x : 행, y: 열
    switch(dir){
        //남,북 => 행, 동,서 => 열이 이동
        //북쪽
        case 0:
            for(int i=x-1;i>=0;i--){
                if(map[i][y]==6){//벽이면 그만탐색
                    break;
                }
                if(map[i][y]==0){
                    map[i][y] = 7;//사각지대 없애기
                }
            }
            break;
        //동쪽
        case 1:
            for(int j=y+1;j<m;j++){
                if(map[x][j]==6){//벽이면 그만탐색
                    break;
                }
                if(map[x][j]==0){
                    map[x][j] = 7;//사각지대 없애기
                }
            }
            break;
        //남쪽
        case 2:
            for(int i=x+1;i<n;i++){
                if(map[i][y]==6){//벽이면 그만탐색
                    break;
                }
                if(map[i][y]==0){
                    map[i][y] = 7;//사각지대 없애기
                }
            }
            break;
        //서쪽
        case 3:
            for(int j=y-1;j>=0;j--){
                if(map[x][j]==6){//벽이면 그만탐색
                    break;
                }
                if(map[x][j]==0){
                    map[x][j] = 7;//사각지대 없애기
                }
            }
            break;
    }
}

//탐색
void dfs(int camera_cnt){
    if(camera_cnt==cctv_cnt){//모든 카메라 탐색 완료
        area_count();//사각지대의 개수 세기
        return;
    }
    
    int cctv = camera[camera_cnt].first;//카메라 번호
    int x = camera[camera_cnt].second.first;//카메라위치
    int y = camera[camera_cnt].second.second;
    
    vector<vector<int>> map_copy = map;//이전 상태값 저장
    
    //카메라 번호
    switch(cctv){
        case 1:
            //북,동,남,서
            for(int dir=0;dir<4;dir++){
                move(dir,x,y);//감시하기
                dfs(camera_cnt+1);//다음 카메라
                map = map_copy;//지도 저장
            }
            break;
        case 2:
            //남북,동서
            for(int dir=0;dir<2;dir++){
                move(dir,x,y);//감시하기
                move(dir+2,x,y);//감시하기
                dfs(camera_cnt+1);//다음 카메라
                map = map_copy;//지도 저장
            }
            break;
        case 3:
            //북동,동남,남서,서북
            for(int dir=0;dir<4;dir++){
                move(dir,x,y);//감시하기
                move((dir+1)%4,x,y);//감시하기
                dfs(camera_cnt+1);//다음 카메라
                map = map_copy;//지도 저장
            }
            break;
        case 4:
            //북동남,동남서,남서북,서북동
            for(int dir=0;dir<4;dir++){
                move(dir,x,y);//감시하기
                move((dir+1)%4,x,y);//감시하기
                move((dir+2)%4,x,y);//감시하기
                dfs(camera_cnt+1);//다음 카메라
                map = map_copy;//지도 저장
            }
            break;
        case 5:
            //모든방향
            move(0,x,y);//감시하기
            move(1,x,y);//감시하기
            move(2,x,y);//감시하기
            move(3,x,y);//감시하기
            dfs(camera_cnt+1);//다음 카메라
            map = map_copy;//지도 저장
            break;
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);

    input();//지도입력
    dfs(0);//카메라 탐색(탐색한 카메라 개수 : 0)
    cout<<ans;
    return 0;
}
