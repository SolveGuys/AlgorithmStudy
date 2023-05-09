#include <iostream>
using namespace std;

int n;
const int maxi = 11;
const int inf = 2100000000;
int A[maxi];
int operators[4];//각 연산자의 개수
int maxAns = -inf;
int minAns = inf;

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];//수열
    for (int i = 0; i < 4; i++) cin >> operators[i];//연산자
}
//계산하기
int Calcul(int idx, int result, int sign) {
    int res;
    switch (sign) {
    case 0:
        res = result + A[idx];
        break;
    case 1:
        res = result - A[idx];
        break;
    case 2:
        res = result * A[idx];
        break;
    case 3:
        res = result / A[idx];
        break;
    }
    return res;
}
//연산
void Cal(int idx,int result) {
    if (idx == n) {
        maxAns = max(maxAns, result);
        minAns = min(minAns, result);
        return;
    }
    //다음 연산하기
    for (int i = 0; i < 4; i++) {
        if (operators[i] > 0) {//연산횟수가 남아 있다.
            operators[i]--;
            int next = Calcul(idx,result,i);
            Cal(idx + 1, next);
            operators[i]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Cal(1,A[0]);//연산
    //출력
    cout << maxAns << "\n";
    cout << minAns;
    return 0;
}
