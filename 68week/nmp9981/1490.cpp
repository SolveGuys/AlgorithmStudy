#include <iostream>
#include <vector>
using namespace std;

//버스 정보
struct BusInfo {
    int start, interval, count;
};
int n, t;
const int inf = 99999999;
vector<BusInfo> bus;

//입력
void input() {
    cin >> n >> t;
    for (int k = 0; k < n; k++) {
        int s, i, c;
        cin >> s >> i >> c;
        bus.push_back({ s,i,c });
    }
}
//탑승
void CheckIn() {
    int minWait = inf;
    for (int i = 0; i < bus.size(); i++) {//각 버스에 대해
        int start = bus[i].start;//최초 도착 시간
        int interval = bus[i].interval;//간격
        int cnt = bus[i].count;//대수
        for (int j = 0; j < cnt; j++) {
            int leave = start + interval * j;//출발 시간
            if (leave >= t) minWait = min(minWait, leave - t);//지각 X
        }
    }
    //출력
    if (minWait == inf) cout << -1;//어떤 버스도 탑승 불가(지각)
    else cout << minWait;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    CheckIn();//탑승
    return 0;
}
