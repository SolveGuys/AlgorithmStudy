#include<iostream>
#include<vector>

using namespace std;

int XDFS(vector<vector<int>> &adj, vector<bool> &check, bool &isCycle, int &X, int fr, int &first) {
	check[fr] = 1;
	int tmp = 0;
	for ( int ad : adj[fr] ) {
		if ( ad == X && fr != first ) {		//cycle�� ����ڰ� ���Ե� ���
			isCycle = 1;
			continue;
		}
		if ( check[ad] == 0 ) {
			tmp += XDFS(adj, check, isCycle, X, ad, first);
		}
	}
	return tmp + 1;
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, X;
	cin >> N >> M;
	vector<vector<int>> adj(N + 1, vector<int>());
	vector<bool> check(N + 1, 0);
	for ( int i = 0; i < M; i++ ) {
		int a, b;
		cin >> a >> b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}

	cin >> X;
	int total = -1;
	bool isCycle = 0;
	check[X] = 1;
	for ( int fr : adj[X] ) {
		if ( !check[fr] ) {
			int tmp = XDFS(adj, check, isCycle, X, fr, fr);
			if ( isCycle == 0 ) tmp += 1;		//cycle�� �����ٸ� ����ڱ��� �����ؼ� +1
			total = max(total, tmp);			//�ְ� ���
			isCycle = 0;
		}
	}
	for ( int i = 1; i < N + 1; i++ ) {
		if ( i == X ) continue;
		if ( !check[i] ) {						//X(�����)�� ����Ǿ� ���� ���� ģ����
			total = max(total, XDFS(adj, check, isCycle, X, i, i));
		}
	}
	cout << total << endl;
	return 0;
}