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
int n,m,h;
int map[31][11];//사다리
int ans = 100;//추가할 최솟값

//입력
void input(){
    cin>>n>>m>>h;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        //사다리 놓기
        map[a][b] = 1;
    }
}

//이동하기(x번이 최종적으로 몇번 사다리로 이동하는가?)
int move(int x){//사다리 번호
    for(int i=1;i<=h;i++){//내려감
        if(map[i][x]==1){//기본 오른쪽
            x++;
        }else if(map[i][x-1]==1){
            x--;
        }
    }
    return x;
}

//모든선이 자신의 위치로 오는지 체크
bool checkline(){
    for(int i=1;i<=n;i++){
        if(move(i)!=i){
            return false;
        }
    }
    return true;
}

//사다리 타기
void ladder(int y,int cnt){//바꾼 지점의 사다리 번호, 사다리 개수
    //사다리 개수 초과
    if(cnt>3){
        return;
    }
    
    //이동하기
    if(checkline()){
        ans = min(ans,cnt);//이동횟수의 최솟값
        return;
    }
    
    //사다리 추가(오른쪽에 추가)
    for(int i=y;i<=h;i++){//행,사다리는 아래로만 내려감
        for(int j=1;j<n;j++){//사다리번호
            //가로선이 연속하면 안됨
            if(map[i][j]==0 && map[i][j+1]==0 && map[i][j-1]==0){
                //추가
                map[i][j] = 1;
                //사다리는 아래로만 내려가므로 i를 넣어줌
                ladder(i,cnt+1); 
                map[i][j] = 0;
            }
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);

    input();//입력
    ladder(1,0);//사다리 타기
    if(ans>3){
        cout<<-1;
    }else{
        cout<<ans;
    }
    return 0;
}
