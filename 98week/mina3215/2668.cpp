#include<iostream>
#include<vector>

using namespace std;

int N;
int nums[102];
int ans[102];


int find(int s) {
	vector<int> used(N + 1);
	used[s] = 1;
	int n = s;
	while (1) {
		n = nums[n];
		if (n == s) break;
		if (used[n]) return 1;
		used[n] =1;
	}
	for (int i = 1; i <= N; i++) {
		if (used[i]) ans[i] = 1;
	}
	return 1;
}


int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		nums[i] = n;
	}
	
	for (int i = 1; i <= N; i++) {
		if (ans[i]) continue;
		find(nums[i]);
	}

	vector<int> v;

	for (int i = 1; i <= N;i++) {
		if (ans[i]) v.push_back(i);
	}
	cout << v.size() << '\n';
	for (auto i : v) {
		cout << i << '\n';
	}
}