#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <memory.h>
#include<tuple>
using namespace std;

int n, a[3], visited[64][64][64];
int attack[6][3] = { {1,3,9},{1,9,3},{3,1,9},{3,9,1},{9,1,3},{9,3,1} };

struct A {
	int a; int b; int c;
};

queue<A> q;

void go(int a, int b, int c) {
	visited[a][b][c] = 1;
	q.push({ a,b,c });
	
	while (q.size()) {
		int _a = q.front().a;
		int _b = q.front().b;
		int _c = q.front().c;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int na = max(0, _a - attack[i][0]);
			int nb = max(0, _b - attack[i][1]);
			int nc = max(0, _c - attack[i][2]);

			if (visited[na][nb][nc]!=0) continue;

			visited[na][nb][nc] = visited[_a][_b][_c] + 1;
			if (na == 0 && nb == 0 && nc == 0) break;
			q.push({ na, nb, nc });

			// cout << visited[na][nb][nc] << "\n";
		}
	}
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	go(a[0], a[1], a[2]);

	cout << visited[0][0][0] - 1 <<"\n";

	return 0;
}
