#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int month[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
vector<pair<int, int>> flower;//꽃정보

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//날짜를 숫자로 변환
int ChangeNum(int x, int y) {
    return month[x - 1] + y;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int startMonth, startDay, endMonth, endDay;
        cin >> startMonth >> startDay >> endMonth >> endDay;
        int startNum = ChangeNum(startMonth, startDay);
        int endNum = ChangeNum(endMonth, endDay);
        flower.push_back({ startNum,endNum });
    }
    sort(flower.begin(), flower.end());
}
//정원 가꾸기
void Garden() {
    int beginFlower = 60; int endFlower = 0; int cnt = 1;
    for (int i = 0; i < n; i++) {
        int st = flower[i].first; int ed = flower[i].second;

        if (beginFlower >= st) {//시작점 기준
            if (endFlower < ed) endFlower = ed;//끝점 갱신
            
            if (endFlower > 334) break;//종료
        }
        else{
            if (st > endFlower) {//심기 불가
                cnt = 0;
                break;
            }
            beginFlower = endFlower;
            endFlower = ed;
            cnt++;
        }
    }
    if (endFlower <= 334) cnt = 0;//11.30까지 안심어짐
    cout << cnt;
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Garden();//정원 가꾸기
    return 0;
}
