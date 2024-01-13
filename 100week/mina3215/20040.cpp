#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int node[500002];


int find_parent(int n) {
	if (n==node[n]) return n;
	return node[n] = find_parent(node[n]);
}

int find_Cycle(int n1, int n2) {
	int rootN1 = find_parent(n1);
	int rootN2 = find_parent(n2); 
	
	if (rootN1 == rootN2) return 1;
	if (rootN1 < rootN2) node[rootN2] = rootN1;
	else node[rootN1] = rootN2;
	return 0;
}

int main(){
	cin >> N >> M;

	for (int i = 0; i < N; i++) node[i] = i;
	int ans = 0;

	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		if (find_Cycle(n1, n2)) {
			ans = i + 1;
			break;
		}
	}
	cout << ans;
	return 0;

}