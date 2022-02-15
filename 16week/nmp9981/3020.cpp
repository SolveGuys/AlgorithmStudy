#include <iostream>
#include <cstring>
using namespace std;

int n,h;
const int inf = 1e+9;
const int maxi = 500001;
int up[maxi];//석순
int down[maxi];//종유석

//입력
void input(){
    //초기화
    memset(up,0,sizeof(up));
    memset(down,0,sizeof(down));
    //입력
    cin.tie(0);//빠른 입력
    cin>>n>>h;
    for(int i=1;i<=n/2;i++){
        int a,b;
        cin>>a>>b;
        up[a]++;//높이가 a인 석순의 개수
        down[b]++;//높이가 b인 종유석의 개수
    }
}

//장애물 개수 누적
void psum(){
    for(int i=h-1;i>0;i--){
        up[i] += up[i+1];
        down[i] += down[i+1];
    }
}

//장애물 파괴
void destroy(){
    int cnt = 0;int res = inf;
    for(int i=1;i<=h;i++){
        if(up[i]+down[h+1-i]<res){//더 작은것이 오면
            res = up[i]+down[h+1-i];
            cnt = 1;
        }else if(up[i]+down[h+1-i]==res){
            cnt++;
        }
    }
    cout<<res<<" "<<cnt;//출력
}
int main(){
    input();//입력
    psum();//장애물 개수 누적
    destroy();//장애물 파괴
    return 0;
}
