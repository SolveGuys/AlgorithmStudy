#include <iostream>
#include <vector>
using namespace std;

int k; string w;
int shortestLen;int longestLen;//문자열 길이
const int inf = 1000001;
vector<int> alpha[26];//각 문자를 포함하는 길이

//입력
void Input() {
    cin >> w>>k;
    for(int i=0;i<26;i++) alpha[i].clear();
    shortestLen = inf;
    longestLen = 0;
}

//문자열 길이
void StringLength() {
    //해당 문자의 인덱스들을 모두 넣는다.
    for (int i = 0; i < w.size(); i++) {
        int idx = w[i] - 'a';
        alpha[idx].push_back(i);
    }
    //각 문자마다 검사
    for (int i = 0; i < 26; i++) {//a~z
        if (alpha[i].size() < k) continue;//문자 개수 조건 불만족

        for (int j = 0; j <= alpha[i].size()-k; j++) {
            shortestLen = min(shortestLen, alpha[i][j + k - 1] - alpha[i][j]+1);
            longestLen = max(longestLen, alpha[i][j + k - 1] - alpha[i][j] + 1);
        }
    }
    //출력
    if (shortestLen == inf || longestLen == 0) cout << -1 << "\n";
    else cout << shortestLen << " " << longestLen << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;cin >> t;
    while (t--) {
        Input();//입력
        StringLength();//문자열 길이
    }
    return 0;
}
