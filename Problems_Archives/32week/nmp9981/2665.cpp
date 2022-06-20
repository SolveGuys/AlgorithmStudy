#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n,ans;
const int maxi = 51;
const int inf = 1e+8;
int room[maxi][maxi];
int visit[maxi][maxi];//방을 바꾸는 횟수
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
    int ans = inf;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            room[i][j] = s[j]-'0';//하나씩 받기
            visit[i][j] = inf;//초기화
        }
    }
}

//탐색
void bfs(int st_x, int st_y) {
    queue<pair<int, int>> q;
    q.push({ st_x,st_y });
    visit[st_x][st_y] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //다음 지점
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            //범위내에 드는가?
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if (room[nx][ny] == 0) {//검은방
                //더 적은 횟수일 경우에만
                if (visit[nx][ny] > visit[x][y] + 1) {
                    visit[nx][ny] = visit[x][y] + 1;
                    q.push({ nx,ny });
                }
            }else if (room[nx][ny] == 1) {//흰방
                //더 적은 횟수일 경우에만
                if (visit[nx][ny] > visit[x][y]) {
                    visit[nx][ny] = visit[x][y];
                    q.push({ nx,ny });
                }
            }
        }
    }
    cout << visit[n-1][n-1];//출력
}

int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    bfs(0, 0);//탐색
    return 0;
}
