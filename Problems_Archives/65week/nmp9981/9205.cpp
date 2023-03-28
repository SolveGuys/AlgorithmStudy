#include <iostream>
#include <queue>
using namespace std;

//위치
struct Pos {
    int x, y;
};
int n;
const int maxi = 103;
Pos store[maxi];//편의점
bool visit[maxi];//i번 편의점 방문 여부

//맨해튼 거리
inline int Manhatten(int x0, int y0, int x1, int y1) {
    return abs(x0 - x1) + abs(y0 - y1);
}

//초기화
void init() {
    for (int i = 0; i < maxi; i++) visit[i] = false;
}
//이동
void Move() {
    queue<Pos> q;
    q.push(store[0]);
    visit[0] = true;

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        //도착
        if (x == store[n+1].x && y == store[n+1].y) {
            cout << "happy\n";
            return;
        }
        //다음 지점
        for (int i = 1; i < n+2; i++) {
            if (visit[i]) continue;//이미 방문

            int nx = store[i].x;
            int ny = store[i].y;
            int dist = Manhatten(x, y, nx, ny);
            //거리가 더 작다.
            if (dist <= 1000) {
                q.push(store[i]);
                visit[i] = true;
            }
        }
    }
    cout << "sad\n";
}

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n+2; i++) cin >> store[i].x >> store[i].y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        init();//초기화
        input();//입력
        Move();//이동
    }
    return 0;
}
