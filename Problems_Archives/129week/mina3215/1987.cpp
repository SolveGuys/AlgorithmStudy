#include<iostream>
#include<algorithm>

using namespace std;

string board[21];
int alphabet[26];

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
int R, C;
int ans = 1;

// �ð� ���� 2��
// �ܼ� DFS�� Ǯ �� �ִٰ� ������. 
// -> 20X20�̶�� ���� ���� ũ��
// -> �ִ� 26�ۿ� ���� ����.

int find_ans(int y, int x, int m) {
	
	ans = max(m, ans);

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= R || nx >= C)
			continue;
		int alpha = int(board[ny][nx]) - int('A');
		if (alphabet[alpha])
			continue;
		alphabet[alpha] = 1;
		find_ans(ny, nx, m + 1);
		alphabet[alpha] = 0;
	}

	return 0;
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> board[i];

	fill(alphabet, alphabet + 26, 0);
	
	int start = int(board[0][0]) - int('A');
	alphabet[start] = 1;

	find_ans(0, 0, 1);
	cout << ans;
}