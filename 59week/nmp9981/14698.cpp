#include <iostream>
#include <queue>
using namespace std;
typedef unsigned long long ull;

int n;
const ull mod = 1000000007;
priority_queue<ull,vector<ull>,greater<ull>> pq;//최소힙

//입력
void input() {
    //초기화
    while (!pq.empty()) pq.pop();
    //입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        ull x;cin >> x;
        pq.push(x);
    }
}
//에너지 구하기
void Energe() {
    ull total = 1;
    while (true) {
        //합성 완료
        if (pq.size() == 1) {
            cout << total%mod<<"\n";//출력
            break;
        }

        //가장 작은 두 에너지
        ull first = pq.top(); pq.pop();
        ull second = pq.top(); pq.pop();
        ull newEnerge = first * second;//새로운 에너지
        pq.push(newEnerge);
        total *= (newEnerge%mod);//비용
        total %= mod;
    }
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        input();//입력
        Energe();//에너지 구하기
    }
    return 0;
}
