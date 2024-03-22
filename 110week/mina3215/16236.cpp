#include<iostream>
#include<queue>
#include<algorithm>
#include<tuple>

using namespace std;

struct Shark {
	int y = 0, x = 0;
	int fish = 0;
	int size = 2;
	int time = 0;
};

int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };

int MAP[21][21];
int N;

int find_next(Shark &bshark);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Shark bshark;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 9)
			{
				bshark.y = i;
				bshark.x = j;
				MAP[i][j] = 0;
			}
		}
	}

	while(find_next(bshark)){
		if (bshark.fish == bshark.size)
		{
			bshark.size++;
			bshark.fish = 0;
		}
	} 
	cout << bshark.time;
}

int find_next(Shark &bshark) {
	int visited[21][21];	
	fill(&visited[0][0], &visited[0][0] + 21 * 21, 0);

	queue<tuple<int, int, int>> q;
	q.push({ bshark.y, bshark.x, 0 });
	visited[bshark.y][bshark.x] = 1;

	int min_V = 2e9;
	// v, y, x
	priority_queue<tuple<int, int, int>> pq;

	while (!q.empty()) {

		int y, x, v;
		tie(y, x, v) = q.front();
		q.pop();
		if (min_V <= v) break;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (visited[ny][nx]) continue;

			if (MAP[ny][nx] != 0) {
				if (bshark.size < MAP[ny][nx]) continue;
				else if (bshark.size > MAP[ny][nx]) {
					min_V = min(v + 1, min_V);
					pq.push({ -(v + 1),-ny,-nx });
				}
			}
			q.push({ ny,nx,v + 1 });
			visited[ny][nx] = 1;
		}
	}
	if (!pq.empty()){
		int v, y, x;
		tie(v, y, x) = pq.top();
		bshark.y = -y;
		bshark.x = -x;
		bshark.time -= v;
		bshark.fish += 1;
		MAP[-y][-x] = 0;
		return 1;
	}
	return 0;
}