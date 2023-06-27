#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n;
const int maxi = 4000001;
const int primeCnt = 283150;//400만까지의 소수 개수
bool isNotPrime[maxi];//소수가 아닌가?
int primeSize;
vector<ll> prime;//소수
ll primeSum[primeCnt];//소수 누적합(int범위 넘어감)

//아리스토텔레스의 체
void Aristotle(){
    prime.push_back(2);
    int rootMaxi = 2000;
    for (int i = 3; i < rootMaxi; i += 2) {
        if (!isNotPrime[i]) {//소수이면
            for (int j = i * i; j < maxi; j+=i) isNotPrime[j] = true;
        }
    }
    //소수 목록
    for (int i = 3; i < maxi; i += 2) {
        if (!isNotPrime[i]) prime.push_back(i);
    }
    //소수 누적합
    primeSize = prime.size();
    for (int i = 1; i <= primeSize; i++) {
        primeSum[i] = primeSum[i-1]+prime[i-1];
    }
}
//입력
void input() {
    cin >> n;
}
//소수의 합
void PrimeSum() {
    int left = 0;
    int right = 1;
    int caseNum = 0;

    while (left < right && right <= primeSize) {
        ll sum = primeSum[right] - primeSum[left];
        if (sum >= n) {//줄여야함
            left++;
            if (sum == n) caseNum++;//일치
        }
        else right++;//늘려야함
    }
    cout << caseNum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Aristotle();//아리스토텔레스의 체
    input();//입력
    PrimeSum();//소수의 합
    return 0;
}
