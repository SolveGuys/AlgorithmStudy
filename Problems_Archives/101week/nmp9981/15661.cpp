#include <iostream>
#include <vector>
using namespace std;

int n;
const int maxi = 21;
int stats[maxi][maxi];//조합별 능력치
bool selectTeam[maxi];//선택한 팀
int minDiff = 10000000;

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> stats[i][j];
    }
}
//스탯 차이 계산
int StatDiff() {
    vector<int> red;
    vector<int> blue;
    for (int i = 1; i <= n; i++) {
        if (selectTeam[i]) red.push_back(i);
        else blue.push_back(i);
    }
    //레드팀
    int redScore = 0;
    int redSize = red.size();
    for (int i = 0; i < redSize - 1; i++) {
        for (int j = i + 1; j < redSize; j++) redScore += (stats[red[i]][red[j]] + stats[red[j]][red[i]]);
    }
    //블루팀
    int blueScore = 0;
    int blueSize = n - redSize;
    for (int i = 0; i < blueSize - 1; i++) {
        for (int j = i + 1; j < blueSize; j++) blueScore += (stats[blue[i]][blue[j]] + stats[blue[j]][blue[i]]);
    }
    return abs(redScore-blueScore);
}

//팀 설정
void TeamSet(int idx, int cnt) {
    if(cnt>=1) minDiff = min(minDiff,StatDiff());//스탯 차이 계산
    if (cnt == n / 2) return;//인원 수 초과

    //다음 선수 선택
    for (int k = idx; k <= n; k++) {
        if (selectTeam[k]) continue;
        selectTeam[k] = true;
        TeamSet(k+1, cnt + 1);
        selectTeam[k] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Input();//입력
    TeamSet(1,0);//팀 설정
    cout << minDiff;//출력
    return 0;
}
