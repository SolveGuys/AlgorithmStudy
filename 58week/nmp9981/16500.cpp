#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string goal;//목표 문자
int n;
const int maxi = 101;
string word[maxi];//단어 목록
int cache[maxi];//i번부터 끝까지 완성 되었는가?

//입력
void input() {
    cin >>goal >> n;
    for (int i = 0; i < n; i++) cin >> word[i];
}
//문자열 판별
void Judge() {
    cache[goal.size()] = 1;//초기값
    for (int i = goal.size() - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (goal.find(word[j], i) == i && cache[i + word[j].length()] == 1) {
                cache[i] = 1;
                break;
            }
            else {
                cache[i] = 0;
            }
        }
    }
    cout << cache[0];
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Judge();//문자열 판별
    return 0;
}
