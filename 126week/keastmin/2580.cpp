#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
vector<pair<int, int>> startPos;

bool Check(int x, int y, int num) {
	for (int i = 0; i < 9; i++) {
		if (map[i][x] == num && i != y) return false;
		if (map[y][i] == num && i != x) return false;
	}

	int part_x = x / 3;
	int part_y = y / 3;
	part_x *= 3;
	part_y *= 3;
	for (int i = part_y; i < part_y + 3; i++) {
		for (int j = part_x; j < part_x + 3; j++) {
			if (i != y && j != x) {
				if (map[i][j] == num) return false;
			}
		}
	}

	return true;
}

bool Sdoku(int idx) {
	if (idx == startPos.size()) return true;

	int x = startPos[idx].first;
	int y = startPos[idx].second;

	for (int i = 1; i <= 9; i++) {
		map[y][x] = i;
		if (Check(x, y, i)) {
			if (Sdoku(idx + 1)) return true;
		}
		map[y][x] = 0;
	}

	return false;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	map.resize(9, vector<int>(9));
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				startPos.push_back({ j, i });
			}
		}
	}

	int x = startPos[0].first;
	int y = startPos[0].second;
	for (int i = 1; i <= 9; i++) {	
		map[y][x] = i;
		if (Check(x, y, i)) {
			if (Sdoku(1)) {
				//cout << "find" << '\n';
				break;
			}
		}
		map[y][x] = 0;
	}
	
	for (const auto ma : map) {
		for (const auto m : ma) {
			cout << m << ' ';
		}
		cout << '\n';
	}

	return 0;
}
