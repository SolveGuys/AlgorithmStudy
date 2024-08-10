#include<iostream>
#include<vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string t;
	string angel;
	string demon;
	cin >> t >> demon >> angel;
	int n = t.size();
	int m = demon.size();
	
	vector<vector<int>> demons(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> angels(n + 1, vector<int>(m + 1, 0));
	for (int j = 1; j < m + 1; j++) {
		if (t[0] == angel[j - 1]) angels[1][j] = 1 + angels[1][j - 1];
		else {
			angels[1][j] = angels[1][j - 1];
		}
		if (t[0] == demon[j - 1]) demons[1][j] = 1 + demons[1][j - 1];
		else {
			demons[1][j] = demons[1][j - 1];
		}
	}
	for (int i = 2; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (t[i - 1] == demon[j - 1]) {		//마법의 두루마리에 있는 문자와 같은 문자라면
				demons[i][j] = demons[i][j - 1] + angels[i - 1][j - 1];
			}
			else {								//다르다면 단순 복사.
				demons[i][j] = demons[i][j - 1];
			}
			if (t[i - 1] == angel[j - 1]) {		//demon의 상황과 동일
				angels[i][j] = angels[i][j - 1] + demons[i - 1][j - 1];
			}
			else {
				angels[i][j] = angels[i][j - 1];
			}

		}
	}
	cout << angels[n][m] + demons[n][m] << endl;



	return 0;
}