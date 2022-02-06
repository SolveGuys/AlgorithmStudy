#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int,int>> lecture;

//입력
void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        int p,d;
        cin>>p>>d;
        lecture.push_back({d,p});
    }
    sort(lecture.begin(),lecture.end());
}

//강연 일정짜기
void solve(){
    priority_queue<int,vector<int>,greater<int>> q;//최소힙
    for(int i=0;i<n;i++){
        int day = lecture[i].first;//기한
        int pay = lecture[i].second;//수입
        q.push(pay);
        
        //용량 초과
        if(q.size()>day){
            q.pop();
        }
    }
    //수입의 총합 구하기
    int money = 0;
    while(!q.empty()){
        money+=q.top();
        q.pop();
    }
    cout<<money;
}
int main(){
    input();//입력
    solve();//강연
    return 0;
}
