#include <iostream>
#include <vector>
using namespace std;

//계란 구조체
struct EggInfo {
    int HP, attack;
};
int n,eggSize;
vector<EggInfo> egg;//계란
int breakCount = 0;//깬 개수

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int hp, atk;
        cin >> hp >> atk;
        egg.push_back({ hp,atk });
    }
    eggSize = egg.size();
}
//계란깨기
void EggBreak(int idx) {
    //가장 오른쪽 계란, 깬 개수 세기
    if (idx == n) {
        int cnt = 0;
        for (int i = 0; i < eggSize; i++) {
            if (egg[i].HP <= 0) cnt ++;
        }
        breakCount = max(cnt, breakCount);
        return;
    }
    //들고 있는 계란
    bool isBreak = false;
    //계란 깨기
    for (int i = 0; i < eggSize; i++) {
        if (idx == i) continue;//본인

        //둘다 안깨짐
        if (egg[idx].HP > 0 && egg[i].HP > 0) {
            egg[idx].HP -= egg[i].attack;
            egg[i].HP -= egg[idx].attack;
            isBreak = true;
            EggBreak(idx + 1);//든 계란의 바로 오른쪽 계란으로
            egg[idx].HP += egg[i].attack;
            egg[i].HP += egg[idx].attack;
        }
    }
    if (!isBreak) EggBreak(idx + 1);//다음 계란
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    EggBreak(0);//계란깨기
    cout << breakCount;//출력
    return 0;
}
