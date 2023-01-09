#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n,power;
const int maxi = 100001;
const int foot = 5;
vector<int> dance;//댄스 버튼
int energe[foot][foot][maxi];//발 x,y에서의 최소 파워

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//추가 에너지
int addEnerge(int now, int next) {
    if (now == next) return 1;
    else if (now == 0) return 2;
    else if (abs(now - next) == 2) return 4;
    return 3;
}
//입력
void input() {
    while (true) {
        int x;
        cin >> x;
        if (x == 0) break;
        dance.push_back(x);
    }
    memset(energe, -1, sizeof(energe));//초기화
}
//춤추기
int Play(int x,int y,int idx) {//왼발,오른발 위치, 인덱스
    //댄스 완료
    if (idx == dance.size()) return 0;
    //이미 한거면
    if (energe[x][y][idx] != -1) return energe[x][y][idx];
    //왼발, 오른발
    int left = Play(dance[idx],y,idx+1) + addEnerge(x, dance[idx]);
    int right = Play(x,dance[idx],idx+1) + addEnerge(y,dance[idx]);
    energe[x][y][idx] = min(left, right);//둘중 더 작은것
    return energe[x][y][idx];
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    cout<<Play(0, 0, 0);//발의 위치, 인덱스
    return 0;
}
