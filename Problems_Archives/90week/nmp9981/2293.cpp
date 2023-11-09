#include <iostream>
using namespace std;

int n,k;
const int maxi = 10001;
int coin[101];//동전
int caseNum[maxi];//경우의 수

//입력
void input() {
    cin >>n>>k;
    for (int i = 0; i < n; i++) cin >> coin[i];
}
//코인 얻기
void CoinGet() {
    caseNum[0] = 1;//0원일때 경우의 수
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j >= coin[i]) caseNum[j] += caseNum[j - coin[i]];//돈이 충분
        }
    }
    cout << caseNum[k];//출력
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    CoinGet();//코인 얻기
    return 0;
}
