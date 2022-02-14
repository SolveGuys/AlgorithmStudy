#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,l,p;
vector<pair<int,int>> gas;//위치, 연료의 양
priority_queue<int> pq;//연료의 양

//입력
void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        gas.push_back({a,b});//위치, 연료의 양
    }
    cin>>l>>p;
    sort(gas.begin(),gas.end());//거리순 정렬
}

//트럭이동
void truck(){
    int idx = 0;
    int cnt = 0;
    while(p<l){
        //지금 남은 연료료 갈 수 있는 최대 주유소
        while(gas[idx].first<=p && idx<n){
            pq.push(gas[idx].second);
            idx++;
        }
        //갈 수 있는 주유소가 없다
        if(pq.empty()){
            cnt = -1;
            break;
        }
        //다음지점
        p += pq.top();
        pq.pop();
        cnt++;
    }
    cout<<cnt;
}

int main()
{
    input();//입력
    truck();//트럭이동
    return 0;
}
