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
int n,c,m;
const int maxi = 2001;
vector<vector<int>> box;//출발,도착,박스의 수
int cap[maxi];//각 마을에서의 용량
int ans = 0;//결과

//두번째(도착지점)를 기준으로 오름차순 정렬
bool comp(vector<int>&a ,vector<int>&b){
    if(a[1]==b[1]){//두번째가 같다면 첫번째를 오름차순으로
        return a[0] < b[0];
    }else{
        return a[1] < b[1];
    }
}

//입력
void input(){
    cin>>n>>c;
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b,d;
        cin>>a>>b>>d;
        box.push_back({a,b,d});
    }
    //정렬
    sort(box.begin(),box.end(),comp);
}

//택배 배달
void delivery(){
    for(int i=0;i<m;i++){
        //현재 적재량 구하기
        int p = 0;
        for(int j=box[i][0];j<box[i][1];j++){
            p = max(p,cap[j]);
        }
        int val = min(box[i][2],c-p);//남는 용량
        //박스 옮기기
        for(int j=box[i][0];j<box[i][1];j++){
            cap[j] += val;
        }
        ans += val;
    }
    cout<<ans;
}
int main(){
    cin.tie(0);
    cout.tie(0);

    input();//입력
    delivery();//택배 배달
    return 0;
}
