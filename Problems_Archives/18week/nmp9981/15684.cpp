#include <iostream>
#include <algorithm>
using namespace std;

int n,m,h;
const int maxi = 31;
const int inf = 1e+7;
int res = inf;
bool world[maxi][11];//사다리

//입력
void input(){
    cin>>n>>m>>h;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        world[a][b] = true;
    }
}
//사다리 타기
bool play(){
    for(int j=1;j<=n;j++){//시작 번호
        int idx = j;//시작지점
        //내려가기
        for(int i=1;i<=h;i++){
            //사다리 발견
            if(world[i][idx]==true){
                idx++;
            }else if(world[i][idx-1]==true){
                idx--;
            }
        }
        //시작번호와 위치가 같은가?
        if(idx!=j) return false;
    }
    return true;
}
//사다리 설치
void install(int cnt,int y){
    //3개가 넘는가?
    if(cnt>3) return;
    //사다리 타기
    if(play()){
        res = min(res,cnt);
        return;
    }
    //탐색
    for(int i=y;i<=h;i++){
        for(int j=1;j<n;j++){
            if(world[i][j]==false){
                //옆 사다리가 있는 경우
                if(world[i][j-1]==true || world[i][j+1]==true){
                    continue;
                }
                world[i][j] = true;//설치
                install(cnt+1,i);
                world[i][j] = false;//해제
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);//빠른 입력
    cin.tie(0);
    
    input();//입력
    install(0,1);//사다리 설치
    //출력
    if(res>=inf) cout<<-1;
    else cout<<res;
    return 0;
}
