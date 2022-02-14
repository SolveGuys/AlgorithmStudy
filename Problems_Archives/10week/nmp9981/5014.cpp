#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int f,s,g,u,d;//전체 층수, 시작, 목표, up, down
const int maxi = 1000001;
int visit[maxi];//방문 여부

//입력
void input(){
    cin>>f>>s>>g>>u>>d;
}

//엘리베이터 이동
void move_elevator(){
    //시작점
    queue<pair<int,int>> q;
    q.push({s,0});//시작지점 넣기
    visit[s] = 1;//방문체크
    
    //엘리베이터 조작
    while(!q.empty()){
        int x = q.front().first;//현재지점
        int cnt = q.front().second;//횟수
        q.pop();
        
        //목표도달
        if(x==g){
            cout<<cnt;
            return;
        }
        
        //다음지점
        //위버튼
        int up_stair = x+u;
        //범위내에 들고 미방문
        if(up_stair>=1 && up_stair<=f){
            if(visit[up_stair]==0){
                visit[up_stair] = 1;//방문체크
                q.push({up_stair,cnt+1});
            }
        }
        //아래버튼
        int down_stair = x-d;
        //범위내에 들고 미방문
        if(down_stair>=1 && down_stair<=f){
            if(visit[down_stair]==0){
                visit[down_stair] = 1;//방문체크
                q.push({down_stair,cnt+1});
            }
        }
    }
    //이동 불가능할 경우
    cout<<"use the stairs";
}

int main(){
    input();//입력
    move_elevator();//엘리베이터 이동
    return 0;
}
