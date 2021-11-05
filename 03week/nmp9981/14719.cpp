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
int h,w;
const int maxi = 501;
int map[maxi][maxi];//사다리
int total = 0;//빗물의 양
int block[maxi];//블록

//입력
void input(){
    cin>>h>>w;
    for(int i=0;i<w;i++){
        cin>>block[i];
    }
    //블록 설치(맨 위부터)
    for(int j=0;j<w;j++){
        for(int i=0;i<block[j];i++){
            map[i][j] = 1;
        }
    }
}

//빗물의 양
void rain(){
    for(int i=0;i<h;i++){
        int water = 0;
        bool flag = false;//채울 수 있는가?
        for(int j=0;j<w;j++){
            //마지막지점
            if(j==w-1 && map[i][j]==0){//채울 수 없음
                water = 0;
                break;
            }
            if(map[i][j]==1){//블록
                total+=water;
                water = 0;
                flag = false;//기본적으로 채울 수 없음
                if(map[i][j+1] == 0){//다음지점
                    flag = true;
                }
            }else{
                if(flag==true){//넣을 수 있다면
                    water++;
                }
            }
        }
    }
    cout<<total;//출력
}
int main(){
    cin.tie(0);
    cout.tie(0);

    input();//입력
    rain();//빗물의 양
    return 0;
}
