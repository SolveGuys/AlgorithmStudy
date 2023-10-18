#include <iostream>
using namespace std;
typedef long long ll;

int n;
const int maxi = 100001;
ll bee1, bee2;//벌1,2가 얻는 양
ll honey[maxi];//꿀의 양
ll sumHoney[maxi];//꿀 누적량

//max
inline ll max(ll x, ll y) {
    return x > y ? x : y;
}

//입력
void input() {
    cin >>n;
    for (int i = 1; i <= n; i++) {
        cin >> honey[i];
        sumHoney[i] = sumHoney[i - 1] + honey[i];//누적량
    }
}

//꿀 얻기
void GetHoney() {
    ll result[3] = { 0,0,0 };//각 경우에서의 결과
    //case1 : 벌-꿀통-벌
    ll maxHoney = 0;
    for (int i = 2; i < n; i++) maxHoney = max(maxHoney, honey[i]);
    result[0] = maxHoney + sumHoney[n]-honey[1]-honey[n];

    //case2 : 벌-벌-꿀통
    //case2,3 모두 가운데 벌만 옮겨가면서 최댓값을 찾음
    for (int i = 2; i < n; i++) {
        bee2 = sumHoney[n]-sumHoney[i];
        bee1 = sumHoney[n] - honey[1]-honey[i];//맨 왼쪽 위치 고정
        result[1] = max(result[1], bee1 + bee2);
    }
    
    //case3 : 꿀통-벌-벌
    for (int i = 2; i < n; i++) {
        bee2 = sumHoney[n] - honey[n]-honey[i];//맨 오른쪽 위치 고정
        bee1 = sumHoney[i-1];
        result[2] = max(result[2],bee1 + bee2);
    }
    cout << max(result[0], max(result[1], result[2]));//출력
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    GetHoney();//꿀 얻기
    return 0;
}
