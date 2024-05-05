#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <memory.h>
#include<tuple>
using namespace std;

int k, w, h, flag;
int a[204][204], visited[204][204][31];
int dy_horse[] = { -2,-1,1,2,2,1,-1,-2};
int dx_horse[] = { 1,2,2,1,-1,-2,-2,-1};
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };

void go() {
	visited[0][0][0] = 1;
	queue <pair<pair<int, int>, pair<int,int>>> q;
	q.push({ { 0, 0 }, { 0, k } });

	while (q.size()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second.first;
		int k = q.front().second.second;

		q.pop();
		if (y == w - 1 && x == h - 1) {
			cout << cnt << "\n";
			return;
		}
        
        for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= w || nx >= h) continue;
			if (a[ny][nx] == 1) continue;
			if (visited[ny][nx][k] == 0) {
				q.push({ { ny, nx }, {cnt + 1, k} });
				visited[ny][nx][k] = 1;
			}

			
		}

		if (k > 0) {
			for (int i = 0; i < 8; i++) {
				int ny = y + dy_horse[i];
				int nx = x + dx_horse[i];

				if (ny < 0 || nx < 0 || ny >= w || nx >= h) continue;
				if (a[ny][nx]==1) continue;
				if (visited[ny][nx][k - 1] == 0) {
					q.push({ { ny, nx }, {cnt + 1, k - 1} });
					visited[ny][nx][k - 1] = 1;
				}
			}
		}

		
	}
	cout << -1 << "\n";
}

int main(){
	cin >> k;
	cin >> h >> w;

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			cin >> a[i][j];
		}
	}

	go();

	return 0;
}
