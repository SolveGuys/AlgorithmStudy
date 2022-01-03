#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int maxi = 10001;
int dice[maxi][6];

//입력
void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            cin>>dice[i][j];
        }
    }
}

//다음 밑면 구하기
int base_side(int b){
    if(b==0 || b==5){
        return 5-b;
    }else if(b==1 || b==3){
        return 4-b;
    }else if(b==2 || b==4){
        return 6-b;
    }
    return 0;
}

//옆면의 최댓값
int side_add(int x){
    int total = 0;//옆면 숫자의 총합
    for(int i=0;i<n;i++){
        int next = base_side(x);//다음 밑면의 번호
        int next_base = dice[i][next];//다음 밑면 숫자
        //i번 주사위의 옆면의 최댓값
        int maxi_side = 0;
        for(int j=0;j<6;j++){
            if(j!=x && j!=next){//옆면만 계산
                maxi_side = max(maxi_side,dice[i][j]);
            }
        }
        total+=maxi_side;

        //주사위 모두 탐색
        if(i==n-1){
            break;
        }else{
            //다음밑면의 위치
            for(int j=0;j<6;j++){
                if(dice[i+1][j]==next_base){
                    x = j;
                }
            }
        }
    }
    return total;
}

int main()
{
    input();//입력
    //가장 밑면에 따른 옆면의 최댓값
    int ans = 0;
    for(int k=0;k<6;k++){//밑면의 번호
        ans = max(side_add(k),ans);
    }
    cout<<ans;//출력
    return 0;
}
