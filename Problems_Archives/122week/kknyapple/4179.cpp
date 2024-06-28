#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<memory.h>
#include<stack>
using namespace std;

int r, c, sy, sx;
char a[1004][1004];
string s;
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 }, res;
int fire_visited[1004][1004], person_visited[1004][1004];
queue <pair<int, int>> q;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < c; j++) {
            a[i][j] = s[j];
            if (a[i][j] == 'F') {
                q.push({ i,j });
                fire_visited[i][j] = 1;
            }
            else if (a[i][j] == 'J') {
                sy = i;
                sx = j;
            }
        }
    }

    int y = 0, x = 0;
    while (q.size()) {
        tie(y,x ) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if (fire_visited[ny][nx]) continue;
            if (a[ny][nx] == '#')continue;

            fire_visited[ny][nx] = fire_visited[y][x] + 1;
            q.push({ ny, nx });
        }
    }

    person_visited[sy][sx]=1;
    q.push({ sy, sx });
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();

        if (y == r - 1 || x == c - 1 || y == 0 || x == 0) {
            res = person_visited[y][x];
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if (person_visited[ny][nx]) continue;
            if (a[ny][nx] == '#')continue;
            if (fire_visited[ny][nx] > person_visited[y][x] + 1 || fire_visited[ny][nx] == 0) {
                person_visited[ny][nx] = person_visited[y][x] + 1;
                q.push({ ny, nx });
            }
        }
    }

    if (res == 0) cout << "IMPOSSIBLE" << "\n";
    else cout << res << "\n";

    return 0;
}
