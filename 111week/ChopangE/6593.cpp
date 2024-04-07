#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};

struct quad {
	int l, r, c, t;
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int L, R, C;
	int s_L, s_R, s_C;
	while ( 1 ) {
		cin >> L >> R >> C;
		if ( L == 0 && R == 0 && C == 0 )break;
		vector<vector<vector<char>>> buliding(L, vector<vector<char>>(R, vector<char>(C)));
		vector<vector<vector<bool>>> check(L, vector<vector<bool>>(R, vector<bool>(C,0)));
		for ( int k = 0; k < L; k++ ) {
			for ( int i = 0; i < R; i++ ) {
				for ( int j = 0; j < C; j++ ) {
					char tmp;
					cin >> tmp;
					buliding[k][i][j] = tmp;
					if ( tmp == 'S' ) {
						s_L = k;
						s_R = i;
						s_C = j;
					}
				}
			}
		}
		queue<quad> que;
		bool end = 0;
		que.push(quad{ s_L, s_R, s_C, 0 });
		check[s_L][s_R][s_C] = 1;
		while ( !que.empty()) {
			int tl = que.front().l;
			int tr = que.front().r;
			int tc = que.front().c;
			int tt = que.front().t;
			que.pop();
			if ( buliding[tl][tr][tc] == 'E' ) {
				end = 1;
				cout << "Escaped in " << tt << " minute(s)." << endl;
				break;
			}
			for ( int i = 0; i < 6; i++ ) {
				int z = tl + dz[i];
				int x = tc + dx[i];
				int y = tr + dy[i];
				if ( z >= L || z < 0 ||y >= R || y < 0 || x >= C || x < 0 )continue;
				if ( buliding[z][y][x] != '#' && check[z][y][x] == 0 ) {
					check[z][y][x] = 1;
					que.push(quad{ tl + dz[i],tr + dy[i] , tc + dx[i], tt + 1 });
				}
			}

		}
		if ( end == 0 ) cout << "Trapped!" << endl;
	}


	return 0;
}