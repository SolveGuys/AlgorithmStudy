#include <iostream>
using namespace std;
typedef unsigned int uint;

uint n,l,k;
const int maxi = 32;
uint csum[maxi][maxi];//i자리에서 j개만큼 1을 가지고 있는 이진수의 개수

//min
inline uint min(uint a, uint b) {
    return a > b ? b : a;
}
//입력
void input() {
    cin >> n>>l>>k;
}
//조합
void nCr() {
    csum[1][0] = 1; csum[1][1] = 1;
    for (int i = 2; i < maxi; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) csum[i][j] = 1;
            else csum[i][j] = csum[i - 1][j - 1] + csum[i - 1][j];
        }
    }
}
//수 찾기
void NumSearch(uint x) {
    for (int i = n - 1; i >= 1; i--) {
        uint stand = 0;//기준
        for (int j = 0; j <= min(l,i); j++) stand += csum[i][j];
        
        if (stand < x) {
            cout << 1;//1
            x -= stand;
            l--;//1을 1개 사용
        }else cout << 0;//0
    }
    //마지막 자리
    if (x == 1) cout << 0;
    else if (x == 2) cout << 1;
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    nCr();//i자리 j개이하 개수
    NumSearch(k);//수 찾기
    return 0;
}
