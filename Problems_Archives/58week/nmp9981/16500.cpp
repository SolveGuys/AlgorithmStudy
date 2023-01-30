#include <iostream>
#include <cstring>
using namespace std;

int n;
string goal;//목표 문자열
const int maxi = 101;
string word[maxi];//단어 목록
bool isMake[maxi];//i~goal.size()번까지 만들 수 있는가?

//입력
void input() {
    cin >> goal;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> word[i];
}
//문자열 만들기
void MakeString() {
    isMake[goal.size()] = true;
    for (int i = goal.size()-1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {//단어를 쭉 보면서
            //이어서 붙일 수 있고 부분 단어가 일치하는가
            if (isMake[i+word[j].size()]==true && goal.substr(i,word[j].size())==word[j]) {//합칠 수 있는가?
                isMake[i] = true;
                break;//단어가 이어졌으므로 해당 반복문은 빠져나간다.
            }
            else isMake[i] = false;
        }
    }
    cout << isMake[0];//0~goal.size() => 목표 문자열을 만들 수 있는가?
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    MakeString();//문자열 만들기
    return 0;
}
