#include <iostream>
#include <queue>
using namespace std;

int s;
const int maxi = 2001;
int imog[maxi][maxi];//i개 화면, j개 저장

//초기화
void Init() {
    for (int i = 0; i < maxi; i++) {
        for (int j = 0; j < maxi; j++) imog[i][j] = -1;
    }
}
//입력
void input() {
    cin >> s;
}
//이모티콘
void Imoticon() {
    queue<pair<pair<int, int>,int>> q;
    q.push({ { 1,0 },0 });//화면, 저장, 시간
    imog[1][0] = 0;

    while (!q.empty()) {
        int screen = q.front().first.first;
        int store = q.front().first.second;
        int times = q.front().second;
        q.pop();

        //성공
        if (screen == s) {
            cout << times;
            return;
        }
        //복사
        if (imog[screen][screen]==-1) {
            imog[screen][screen] = times+1;
            q.push({ {screen,screen},times + 1 });
        }

        //붙여넣기
        if (store + screen<maxi && imog[store + screen][store]==-1) {
            imog[store + screen][store] = times+1;
            q.push({ {store + screen,store},times + 1 });
        }

        //삭제
        if (screen >= 1 && imog[screen-1][store]==-1) {
            imog[screen-1][store] = times+1;
            q.push({ {screen - 1,store},times + 1 });
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Init();//초기화
    input();//입력
    Imoticon();//이모티콘
    return 0;
}
