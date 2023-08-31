#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX 1001

int n, m;
int map[MAX][MAX];
bool visit[MAX][MAX][2]; // 이전까지 벽을 부셨을 경우를 판별하기 위한 방문표시배열

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

typedef struct {
    int x; 
    int y;
    int length; // 이동한 거리
    bool flag; // 벽 1개를 부쉈는지 여부
}node;

int bfs() {

	queue<node> q;

	visit[0][0][0] = true;
	q.push({ 0, 0, 1, false });

	while (!q.empty()) {
		node now = q.front();
		q.pop();


		if (now.x == m - 1 && now.y == n - 1) {
			return now.length;
		}

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n)
				continue;

			if (map[ny][nx] == 1 && now.flag == 0) {
				visit[ny][nx][now.flag + 1] = true;
				q.push({ nx, ny, now.length + 1, now.flag + 1 });
			}
			else if (map[ny][nx] == 0 && !visit[ny][nx][now.flag]) {
				visit[ny][nx][now.flag] = true;
				q.push({ nx, ny, now.length + 1, now.flag });
			}
		}

	}
	return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j=0; j<m; j++)
        {
            map[i][j] = tmp[j] - '0';
        }
    }

    cout << bfs();
    return 0;
}
