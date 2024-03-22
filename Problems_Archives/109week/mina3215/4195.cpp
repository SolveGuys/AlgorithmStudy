#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

int T;
int F, Networking[200004], Group[200004];

int find(int n) {
	if (n != Group[n])
		return Group[n] = find(Group[n]);
	else
		return n;
}

int combine(int n1, int n2) {
	if (n1 < n2) {
		Group[n2] = n1;
		return Networking[n1] += Networking[n2];
	}
	else {
		Group[n1] = n2;
		return Networking[n2] += Networking[n1];
	}
}

int union_find(int n1, int n2) {
	int g1 = find(n1);
	int g2 = find(n2);
	if (g1 != g2) {
		cout << combine(g1, g2)<<'\n';
	}
	else {
		cout << Networking[g1]<<'\n';
	}
	return 0;
}

int main() {
	cin >> T;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (int t = 0; t < T; t++) {
		unordered_map<string, int> m;
		cin >> F;
		fill(Networking, Networking + 200004, 1);
		for (int i = 0; i < 200004; i++) {
			Group[i] = i;
		}
		int num = 1;
		for (int i = 0; i < F; i++) {
			string name1, name2;
			cin >> name1 >> name2;
			if (!m[name1])
				m[name1] = num++;
			if (!m[name2])
				m[name2] = num++;
			union_find(m[name1],m[name2]);
		}
	}
	return 0;
}