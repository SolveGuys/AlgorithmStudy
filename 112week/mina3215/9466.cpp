#include<iostream>
#include<algorithm>
using namespace std;

int T;
int Student[100002];
int Group[100002];

int find_cycle(int n) {
	int cnt = 1;
	int next = Student[n];
	while (true) {
		if (n == next) return cnt;
		next = Student[next];
		cnt++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		int n = 0;
		int cnt = 0;
		cin >> n;
		
		fill(Student, Student + 100002, 0);
		fill(Group, Group + 100002, 0);
		
		for (int i = 1; i <= n; i++) {
			cin >> Student[i];
			if (i == Student[i]) {
				Group[i] = i;
				cnt++;
			}
		}

		for (int i = 1; i <= n; i++) {
			if (Group[i]) continue;
			Group[i] = i;
			int n = i;
			int next = Student[n];
			
			while (true) {
				if (Group[n] == Group[next]) {
					cnt += find_cycle(n);
					break;
				}
				if (Group[next])
					break;
				Group[next] = Group[n];
				
				n = next;
				next = Student[n];
			}
		}
		
		cout << n-cnt << '\n';
	}
}