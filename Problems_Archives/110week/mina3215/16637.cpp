#include<iostream>
#include<vector>
#include<string>
using namespace std;

int N, max_V=-2e9;
vector<char> num;
vector<char> op;

int calculator(int  n1, int n2, char _op) {
	if (_op == '+')
		return n1 + n2;
	if (_op == '-')
		return n1 - n2;
	if (_op == '*')
		return n1 * n2;
}


void find_max(int idx1, int idx2, int result) {
	if (idx1 >= num.size()) {
		max_V = max(max_V, result);
		return;
	}
	int f;
	f = calculator(result, num[idx1], op[idx2]);
	find_max(idx1 + 1, idx2 + 1, f);
	if (idx1 + 1 >= num.size())
		return;
	f = calculator(result, calculator(num[idx1], num[idx1 + 1], op[idx2 + 1]),op[idx2]);
	find_max(idx1 + 2, idx2 + 2, f);
}


int main() {
	cin >> N;
	string s;
	cin >> s;
	for (int i = 0; i < N; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			num.push_back(int(s[i]-'0'));
		else
			op.push_back(s[i]);
	}

	find_max(1, 0, num[0]);

	cout << max_V;

	return 0;

}