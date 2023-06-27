#include <iostream>
using namespace std;

int n,d,k,c;
const int maxi = 60001;//벨트 사이즈
const int maxiKind = 3001;//가짓수
int sushi[maxiKind] = { 0, };//i번 초밥의 초밥 개수
int dish[maxi];//회전 초밥 벨트
int maxCnt = 0;//최대 개수

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//식사
void Eat() {
    int cnt = 1;
    sushi[c] = 1;//쿠폰
    //처음 k개
    for (int i = 0; i < k; i++) {
        sushi[dish[i]]++;
        if (sushi[dish[i]] == 1) cnt += 1;//새로운 종류
    }
    maxCnt = cnt;
    
    //회전 벨트
    for (int i = k; i < 2 * n; i++) {
        //새로운 것 
        int newSushi = dish[i];
        sushi[newSushi]++;
        if (sushi[newSushi] == 1) cnt++;
        //기존 것 버리기 
        int destroySushi = dish[i - k];
        sushi[destroySushi]--;
        if (sushi[destroySushi] == 0) cnt--;

        maxCnt = max(maxCnt, cnt);//가짓수 갱신
    }
    cout << maxCnt;
}
//입력
void input() {
    cin >> n>>d>>k>>c;
    for (int i = 0; i < n; i++) cin>>dish[i];//앞부분
    for (int i = 0; i < n; i++) dish[i+n]=dish[i];//뒷부분
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Eat();//식사
    return 0;
}
