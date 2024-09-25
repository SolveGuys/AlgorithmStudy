#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

queue<pair<int, int>> q; // �ѹ����� BFS �����̹Ƿ� ť �ʿ�
vector<pair<int, int>> v; // ���̸� ��� ����
vector < pair<int, pair<int, int>> > bridge; //  ��� �ٸ� ������ ������ 
// �ٸ� ����, pair<from, to>

int arr[10][10]; // �Է� ���� �迭
int parent[7]; // �θ� Ȯ�� ( Union-Find �˰��� ����� ����)
int land[10][10]; // ������ �� ��ȣ ���
bool visit[10][10]; // BFS ����� ���� �湮 ��� 
int side[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }; // �����¿� �̵�

int islandCnt = 0; // ���� ����
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
		if (visit[v[i].first][v[i].second] == true) // �̹� ��ȣ�� �����ϸ� �н�
			continue;

		q.push(make_pair(v[i].first, v[i].second));
		visit[q.front().first][q.front().second] = true;
		land[q.front().first][q.front().second] = ++islandCnt; // �� ������ ù �� �߽߰� �� ��ȣ�� �ű�� �湮 ó��, ť�� ����


		while (!q.empty()) // ���� ���� ����� ���� ���� ��ȣ�� �ѹ���
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

void make_bridge(int y, int x, int dir) // y,x ��ǥ���� dir �������� �� Ž��
{
	int len = 0;
	int start = land[y][x];

	while (1)
	{
		int ny = y + side[dir][0];
		int nx = x + side[dir][1];

		if (ny >= 0 && nx >= 0 && ny < N && nx < M)
		{
			if (arr[ny][nx] == 0) // �ٴٸ� �ٸ� 1�� ��� ��ǥ����
			{
				y = ny;
				x = nx;
				len += 1;
			}
			else if (arr[ny][nx] == 1 && len >= 2 && start != land[ny][nx]) // ����̰� ������ ��ƿ� �ٸ� ���̰� 2�̻��̰� ���۰� �ٸ� �����ȣ�� ���
			{
				bridge.push_back(make_pair(len, make_pair(start, land[ny][nx])));
				break;
			}
			else // �׿ܴ� break ó��, 1 0 1 ������� ����
				break;
		}
		else // ������ ����ٸ� break ó��
			break;

	}

}


void solve()
{
	for (int i = 0; i < v.size(); i++) // ��� ���� ���ؼ� 4�� �������� ����� ����� ����� Ȯ���ϱ�
	{
		for (int j = 0; j < 4; j++) // side(dir)�� 0~3�� �־� 4 ����
			make_bridge(v[i].first, v[i].second, j);
	}

	sort(bridge.begin(), bridge.end()); // ũ�罺Į �˰��� ����� ���� ����

	for (int i = 1; i <= islandCnt; i++) // union-find �˰����� ���� �ʱ�ȭ
		parent[i] = i;

	int res = 0;
	for (int i = 0; i < bridge.size(); i++) // ��� �ٸ��� ���� Ž��
	{
		if (!sameParent(bridge[i].second.first, bridge[i].second.second)) // A-B ��� A,B ���� �θ� �ٸ��� Ȯ��
		{
			Union(bridge[i].second.first, bridge[i].second.second);
			res += bridge[i].first;
		}
	}

	for (int i = 1; i <= islandCnt; i++) // ��� ���� �θ� 1�� ����ų���̹Ƿ� �ٸ��ٸ� -1 ó��
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