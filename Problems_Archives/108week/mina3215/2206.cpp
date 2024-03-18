#include<iostream>

using namespace std;

int N, M;
int min_V = 2e9;
int MAP[1001][1001];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };

struct Info {
	int y, x;
	int prev;
	int n;
	bool is_broken;
};

void DFS(Info info) {
	if (info.y == M && info.x == N) {
		min_V = min(min_V, info.n);
		return;
	}
	if (min_V <= info.n) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = info.y;
		int nx = info.x;
		int move = 0;
		
		if (info.prev == i) continue; // ������ ������ �������� ���� �ʴ´�. 
		if (info.prev!=-1&&(info.prev + 2) % 4 == i)continue; // ������ �� �������� ���ư��� �ʴ´�. 
		
		Info new_info = { 0, 0, i, 0, info.is_broken };

		while (true) {
			// ���� ��ġ�� ���� �̻��̸� ���� �ʴ´�. 
			if (ny + dy[i] <= 0 || nx + dx[i] <= 0 || ny + dy[i] > N || nx + dx[i] > M) break;
			// ���̸� �б�.
			if (MAP[ny + dy[i]][nx + dx[i]]) {
				// 1. �̹� ���� �ν��ų�, �Ⱥν��� �� ������� DFS. 
				new_info.y = ny;
				new_info.x = nx;
				new_info.n = info.n + move;
				DFS(new_info);
				//�̹� ���� �ν��ٸ�?
				if (new_info.is_broken) {
					break; //DFS�ϰ� ����. 
				}
				//�ƴϸ� ��� �����Ѵ�. new_info.is_broken = ture�� ����( �� �μ� ) >> ���� ���� �� �μ���. 
				new_info.is_broken = true;
			}

			ny += dy[i];
			nx += dx[i];
			move++;
		}
		new_info.y = ny;
		new_info.x = nx;
		new_info.n = info.n + move;
		if(info.is_broken!=new_info.is_broken) DFS(new_info);
	}

	return;

}

int main() {
	cin >> N >> M;
	string s;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		int j = 1;
		for (auto c : s) MAP[i][j++] = int(c)-48;
	}
	Info start = { 1,1,-1,1,false };
	DFS(start);
	if (min_V == 2e9)min_V = -1;
	cout << min_V;
}