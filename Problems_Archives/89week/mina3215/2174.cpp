#include<bits/stdc++.h>

using namespace std;

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };

map<int, int> dir;
vector <pair<int, int>> pos;
vector<string> ans;

int land[100][100];

int main() {
	fill(&land[0][0],&land[0][0]+100*100,0);
	int A, B;
	int N, M;
	cin >> A >> B;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int y, x, n;
		char w;
		cin >> x >> y >> w;
		land[y][x] = i;
		pos.push_back({ y,x });
		n = 3;
		if (w == 'N') n = 0;
		else if (w == 'E') n = 1;
		else if (w == 'S') n = 2;
		dir[i] = n;
	}
	for (int i = 0; i < M; i++) {
		int num, how, y, x, ny, nx;
		char comm;
		cin >> num >> comm >> how;

		tie(y, x) = pos[num-1];
		land[y][x] = 0;
		
		for (int j = 0; j < how; j++) {
			if (comm == 'F') {
				ny = y+dy[dir[num]];
				nx = x+dx[dir[num]];
				if (ny < 1 || nx < 1 || ny > B || nx > A) {
					cout<< "Robot " + to_string(num) + " crashes into the wall";
					return 0;
				}
				if (land[ny][nx] != 0) {
					cout<< "Robot " +to_string(num)+ " crashes into robot "+ to_string(land[ny][nx]);
					return 0;
				}
				y = ny;
				x = nx;
			}
			else if (comm == 'R') {
				dir[num] = (dir[num]+1) % 4;
			}
			else {
				dir[num] = dir[num ]>0?dir[num]-1:3;
			}
		}
		land[y][x] = num;
		pos[num - 1] = { y,x };
	}
	cout << "OK";
	return 0;

}