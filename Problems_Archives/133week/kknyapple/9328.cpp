#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
using ll = long long;

int t, h, w;
string low;
char a[104][104];
bool visited[104][104];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
vector <char> key;
string s;
int ans;
map <char, vector<pair<int, int>>> tmp;

void init() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            a[i][j] = ' ';
            visited[i][j] = 0;
        }
    }

    key.clear();
    tmp.clear();
}

void go(int y, int x) {
    queue<pair<int, int>> q;

    // 벽 가장자리 빈공간, 대문자, 소문자, 문서 인지
    if (a[y][x] >= 'A' && a[y][x] <= 'Z') { // 대문자 일 경우
        int flag = 0;
        for (auto p : key) {
            if (p - 32 == a[y][x]) {
                flag = 1;
                visited[y][x] = 1;
                q.push({ y,x });
                break;
            }
        }
        if (flag == 0) {
            tmp[a[y][x]].push_back({ y, x });
        }
    }
    else {
        if (a[y][x] >= 'a' && a[y][x] <= 'z') { // 소문자일 경우
            key.push_back(a[y][x]);
            if (tmp.find(a[y][x] - 32) != tmp.end()) {
                for (auto p : tmp[a[y][x] - 32]) {
                    q.push({ p.first, p.second });
                }
                tmp.erase(a[y][x] - 32);
            }
        }
        else if (a[y][x] == '$') { // 문서일 경우
            ans++;
        }

        visited[y][x] = 1;
        q.push({ y,x });
    }

    // 탐색
    while (!q.empty()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (a[ny][nx] == '*') continue;
            if (visited[ny][nx]) continue;
            
            if (a[ny][nx] >= 'A' && a[ny][nx] <= 'Z') { // 대문자
                int flag = 0;
                for (auto p : key) { // 해당 대문자의 소문자 열쇠가 있는 지 확인
                    if (p - 32 == a[ny][nx]) {
                        flag = 1; break;
                    }
                }
                if (flag == 0) { // 키가 없으면 추후 열쇠가 생기면 열기 위해 [대문자 key에 (y, x)좌표 value] 저장
                    tmp[a[ny][nx]].push_back({ ny, nx });
                    continue;
                }
            }
            else if (a[ny][nx] >= 'a' && a[ny][nx] <= 'z') { // 소문자
                key.push_back(a[ny][nx]); // 열쇠 저장
                if (tmp.find(a[ny][nx] - 32) != tmp.end()) { // 해당 열쇠로 열 수 있는 대문자가 있는 지 확인
                    for (auto p : tmp[a[ny][nx] - 32]) {
                        q.push({ p.first, p.second });
                    }
                    tmp.erase(a[ny][nx] - 32); // 열쇠 사용한 대문자 좌표 삭제
                }
            }
            else if (a[ny][nx] == '$') { // 문서
                ans++;
            }

            visited[ny][nx] = 1;
            q.push({ ny, nx });
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> h >> w;
        ans = 0;
        init();

        for (int i = 0; i < h; i++) {
            cin >> s;
            for (int j = 0; j < w; j++) {
                a[i][j] = s[j];
            }
        }
        cin >> low;
        if (low != "0") {
            for (auto p : low) {
                key.push_back(p); // 열쇠 저장
            }
        }

        // 벽 가장자리 찾아서 bfs
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i == 0 || i == h - 1) {
                    if (a[i][j] == '*') continue; // 벽일 때
                    if (visited[i][j]) continue; // 이미 방문 했을 때
                    go(i, j);
                }
                else {
                    if (j == 0 || j == w - 1) {
                        if (a[i][j] == '*') continue; // 벽일 때
                        if (visited[i][j]) continue; // 이미 방문 했을 때
                        go(i, j);
                    }
                    else {
                        continue;
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
