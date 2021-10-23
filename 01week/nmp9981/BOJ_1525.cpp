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
#include <set>

using namespace std;//이름공간 선언
using namespace chrono;
string puzzle;//퍼즐판
int dx[] = {-1,1,-0,0};//x축이동
int dy[] = {0,0,-1,1};//y축이동
set<string> visit;//중복된것이 들어가지 않게

//정답 결과
bool success(string puz){
    if(puz=="123456780"){
        return true;
    }
    return false;
}

//퍼즐입력
void input(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            char a;
            cin>>a;
            puzzle = puzzle + a;
        }
    }
}

//bfs로 퍼즐 풀이
void bfs(){
    queue<pair<string,int>> q;
    //퍼즐을 큐,셋에 넣기
    q.push({puzzle,0});
    visit.insert(puzzle);
    
    while(!q.empty()){
        //현재좌표
        string p = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        //0인지점 좌표 찾기
        int x,y;
        for(int i=0;i<9;i++){
            if(p[i]=='0'){
                x = i/3;//행
                y = i%3;//열
            }
        }
        int xy = 3*x+y;//1차원 배열 좌표
        
        //정답코드이면 종료
        if(success(p)==true){
            cout<<cnt;
            return;
        }
        
        //빈칸 4방향 이동
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            //범위내에 있고 중복되지 않은 케이스
            if(nx>=0 && nx<3 && ny>=0 && ny<3){
                int nxy = 3*nx+ny;//다음지점의 1차원 배열 좌표
                string next_p = p;
                //퍼즐자리 바꾸기
                next_p[xy] = p[nxy];
                next_p[nxy] = p[xy];
                if(visit.count(next_p)==0){//중복되지 않았다면
                    visit.insert(next_p);
                    q.push({next_p,cnt+1});
                }
            }
        }
    }
    //정답이 없는 경우
    cout<<-1;
}

int main(){
    cin.tie(0);
    cout.tie(0);

    input();
    bfs();
    return 0;
}
