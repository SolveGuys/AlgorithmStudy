#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;



int BFS(vector<vector<int>> tmpPlace, queue<pair<int, int>> virus, stack<pair<int, int>> wall, int N, int M, int Max) {
	int x, y;
	while ( !wall.empty() ) {
		x = wall.top().first;
		y = wall.top().second;
		tmpPlace[x][y] = 1;
		wall.pop();
	}

	while ( !virus.empty() ) {
		x = virus.front().first;
		y = virus.front().second;
		virus.pop();
		if ( x - 1 >= 0 ) {
			if ( tmpPlace[x - 1][y] == 0 ) {
				virus.push(pair<int, int>(x - 1, y));
				tmpPlace[x - 1][y] = 2;
				Max -= 1;
			}
		}

		if ( y - 1 >= 0 ) {
			if ( tmpPlace[x][y - 1] == 0 ) {
				virus.push(pair<int, int>(x, y - 1));
				tmpPlace[x][y - 1] = 2;
				Max -= 1;
			}
		}

		if ( y + 1 < M ) {
			if ( tmpPlace[x][y + 1] == 0 ) {
				virus.push(pair<int, int>(x, y + 1));
				tmpPlace[x][y + 1] = 2;
				Max -= 1;
			}
		}

		if ( x + 1 < N ) {
			if ( tmpPlace[x + 1][y] == 0 ) {
				virus.push(pair<int, int>(x + 1, y));
				tmpPlace[x + 1][y] = 2;
				Max -= 1;
			}
		}
	}


	return Max;

}


void SetWall(int &totalmax, int startx, int starty, vector<vector<int>> &place, stack<pair<int, int>> wall, queue<pair<int, int>> &virus, int N, int M, int &Max) {
	int i, j;
	int tmp = 0;
	i = startx;
	j = starty;
	for ( ; i < N; i++ ) {
		for ( ; j < M; j++ ) {
			if ( place[i][j] == 0 ) {
				wall.push(pair<int, int>(i, j));
				if ( wall.size() == 3 ) {
					tmp = BFS(place, virus, wall, N, M, Max - 3);
					if ( tmp > totalmax ) totalmax = tmp;
				}
				else {
					if ( j + 1 < M ) {
						SetWall(totalmax, i, j + 1, place, wall, virus, N, M, Max);
					}
					else {
						SetWall(totalmax, i + 1, 0, place, wall, virus, N, M, Max);
					}
					if ( totalmax < tmp ) totalmax = tmp;

				}
				wall.pop();
			}
		}
		j = 0;
	}
}



int main() {
	int N, M, Max;
	int tmpMax = 0;
	cin >> N >> M;
	Max = N * M;
	vector<vector<int>> place(N, vector<int>(M, 0));
	queue<pair<int, int>> virus;
	stack<pair<int, int>> wall;
	for ( int i = 0; i < N; i++ ) {
		for ( int j = 0; j < M; j++ ) {
			cin >> place[i][j];
			if ( place[i][j] == 1 || place[i][j] == 2 ) Max--;
			if ( place[i][j] == 2 ) {
				virus.push(pair<int, int>(i, j));
			}
		}
	}
	SetWall(tmpMax, 0, 0, place, wall, virus, N, M, Max);

	cout << tmpMax << endl;
	return 0;

}