#include <iostream>
#include <vector>
using namespace std;

//계란 구조체
struct EGG {
    int HP, Atk;//체력, 공격력
};
//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
int n;
int outEgg = 0;//깬 계란의 개수
vector<EGG> egg;//계란

//입력
void input() {
    cin >>n;
    for (int i = 0; i < n; i++) {
        int s, w;
        cin >> s >> w;
        egg.push_back({ s,w });
    }
}
//계란 깨기
void BreakEgg(int idx) {
    //깨진 계란 개수 세기
    if (idx == n) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (egg[i].HP <= 0) cnt++;
        }
        outEgg = max(outEgg, cnt);//갱신
        return;
    }
    //어떤 계란을 깰지
    bool flag = false;//깰 수 있는가?
    for (int i = 0; i < n; i++) {
        if (i == idx) continue;//자기 자신
        //둘다 안깨짐
        if (egg[idx].HP > 0 && egg[i].HP > 0) {
            //계란 깨기
            egg[idx].HP -= egg[i].Atk;
            egg[i].HP -= egg[idx].Atk;
            flag = true;
            //다음 계란
            BreakEgg(idx + 1);
            //원래대로
            egg[idx].HP += egg[i].Atk;
            egg[i].HP += egg[idx].Atk;
        }
    }
    if(!flag) BreakEgg(idx + 1);//못깨면 다음으로
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    BreakEgg(0);//계란 깨기
    cout << outEgg;//출력
    return 0;
}
