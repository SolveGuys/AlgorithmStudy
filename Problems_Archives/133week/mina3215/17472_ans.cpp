#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

queue<pair<int, int>> q; // 넘버링에 BFS 쓸것이므로 큐 필요
vector<pair<int, int>> v; // 땅이면 모두 담음
vector < pair<int, pair<int, int>> > bridge; //  모든 다리 간선을 담을것 
// 다리 길이, pair<from, to>

int arr[10][10]; // 입력 받은 배열
int parent[7]; // 부모 확인 ( Union-Find 알고리즘 사용을 위해)
int land[10][10]; // 땅마다 섬 번호 기록
bool visit[10][10]; // BFS 사용일 위해 방문 기록 
int side[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }; // 상하좌우 이동

int islandCnt = 0; // 섬의 개수
int N, M;

int find(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = find(parent[a]);
}

void Union(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
	{
		if (a < b)
			parent[b] = a;
		else
			parent[a] = b;
	}

}

bool sameParent(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
		return false;
	return true;

}

void numbering()
{
	for (int i = 0; i < v.size(); i++)
	{
		if (visit[v[i].first][v[i].second] == true) // 이미 번호가 존재하면 패스
			continue;

		q.push(make_pair(v[i].first, v[i].second));
		visit[q.front().first][q.front().second] = true;
		land[q.front().first][q.front().second] = ++islandCnt; // 위 세줄은 첫 땅 발견시 섬 번호를 매기고 방문 처리, 큐에 담음


		while (!q.empty()) // 위의 땅과 연결된 땅을 같은 번호로 넘버링
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int ny = y + side[j][0];
				int nx = x + side[j][1];
				if (nx >= 0 && ny >= 0 && ny < N && nx < M && visit[ny][nx] == false && arr[ny][nx] == 1)
				{
					q.push(make_pair(ny, nx));
					visit[ny][nx] = true;
					land[ny][nx] = islandCnt;
				}
			}
		}


	}


}

void make_bridge(int y, int x, int dir) // y,x 좌표에서 dir 방향으로 쭉 탐색
{
	int len = 0;
	int start = land[y][x];

	while (1)
	{
		int ny = y + side[dir][0];
		int nx = x + side[dir][1];

		if (ny >= 0 && nx >= 0 && ny < N && nx < M)
		{
			if (arr[ny][nx] == 0) // 바다면 다리 1개 깔고 좌표갱신
			{
				y = ny;
				x = nx;
				len += 1;
			}
			else if (arr[ny][nx] == 1 && len >= 2 && start != land[ny][nx]) // 대륙이고 이제껏 깔아온 다리 길이가 2이상이고 시작과 다른 대륙번호일 경우
			{
				bridge.push_back(make_pair(len, make_pair(start, land[ny][nx])));
				break;
			}
			else // 그외는 break 처리, 1 0 1 같은경우 방지
				break;
		}
		else // 범위에 벗어난다면 break 처리
			break;

	}

}


void solve()
{
	for (int i = 0; i < v.size(); i++) // 모든 땅에 대해서 4개 방향으로 뻗어가서 대륙이 닿는지 확인하기
	{
		for (int j = 0; j < 4; j++) // side(dir)에 0~3을 넣어 4 방향
			make_bridge(v[i].first, v[i].second, j);
	}

	sort(bridge.begin(), bridge.end()); // 크루스칼 알고리즘 사용을 위해 정렬

	for (int i = 1; i <= islandCnt; i++) // union-find 알고리즘을 위해 초기화
		parent[i] = i;

	int res = 0;
	for (int i = 0; i < bridge.size(); i++) // 모든 다리에 대해 탐색
	{
		if (!sameParent(bridge[i].second.first, bridge[i].second.second)) // A-B 경우 A,B 땅의 부모가 다른지 확인
		{
			Union(bridge[i].second.first, bridge[i].second.second);
			res += bridge[i].first;
		}
	}

	for (int i = 1; i <= islandCnt; i++) // 모든 땅의 부모가 1을 가리킬것이므로 다르다면 -1 처리
	{
		if (find(i) != 1) {
			cout << "-1";
			return;
		}
	}
	cout << res;

}

int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				v.push_back(make_pair(i, j));
		}
	numbering();
	solve();
}