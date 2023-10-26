#include <iostream>
using namespace std;

string a, b;
int aSize, bSize;
int maxLen = 0;
const int maxi = 4001;
int len[maxi][maxi];//a[i]~b[i]의 공통 부분 문자열 길이
//max
inline int max(int x, int y) {
    return x > y ? x : y;
}

//입력
void input() {
    cin >> a;
    cin >> b;
}
//같은 문자 처리
void CommonString() {
    aSize = a.size();
    bSize = b.size();
    for (int i = 0; i < aSize; i++) {
        for (int j = 0; j < bSize; j++) {
            if (a[i] == b[j]) len[i][j] = 1;//같은 문자
        }
    }
}
//공통 부분 문자열
void LCS() {
    for (int i = 1; i < aSize; i++) {
        for (int j = 1; j < bSize; j++) {
            if (a[i] == b[j]) {//같은 문자일 경우
                len[i][j] = len[i - 1][j - 1] + 1;
                maxLen = max(maxLen, len[i][j]);
            }
        }
    }
    cout << maxLen;//출력
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    CommonString();//같은 문자 처리
    LCS();//공통 부분 문자열
    return 0;
}
