#include<bits/stdc++.h>

using namespace std;

int N;
int record[10000][10000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	queue<vector<int>> q;
	vector<int> v; // 현재 상태, 클립 보드
	q.push({ 1,0,0 });

	while (true) {
		v = q.front();
		if (v[0] == N) {
			break;
		}
		if (!record[v[0]][v[0]]) {
			q.push({ v[0],v[0],v[2] + 1 });
			record[v[0]][v[0]]=1;
		}
		if (!record[v[0] + v[1]][v[1]]&&v[0]+v[1]<2000) {
			q.push({ v[0] + v[1],v[1],v[2] + 1 });
			record[v[0] + v[1]][v[1]]=1;
		}
		if (!record[v[0] - 1][v[1]]&&v[0]-1>1) {
			q.push({ v[0] - 1,v[1],v[2] + 1 });
			record[v[0] - 1][v[1]] = 1;
		}
		q.pop();
	}

	cout << v[2];
}