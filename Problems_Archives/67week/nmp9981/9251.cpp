#include <iostream>
using namespace std;

int n, m;
const int maxi = 1001;
int len[maxi][maxi];//s1-i, s2-j까지 탐색했을때의 결과
string s1, s2;

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> s1>>s2;
    s1 = '0' + s1;
    s2 = '1' + s2;
}
//LCS
void LCS() {
    for (int i = 1; i < s1.size(); i++) {
        for (int j = 1; j < s2.size(); j++) {
            if (s1[i] == s2[j]) len[i][j] = len[i - 1][j - 1] + 1;
            else len[i][j] = max(len[i - 1][j], len[i][j - 1]);
        }
    }
    cout << len[s1.size()-1][s2.size()-1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    LCS();//LCS
    return 0;
}
