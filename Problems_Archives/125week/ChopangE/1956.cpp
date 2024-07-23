#include<iostream>
#include<vector>

using namespace std;

int V, E;
int a, b, c;
int total_min = 1000000000;

//플로이드 워셔 접근법

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E;
	vector<vector<int>> arr(V + 1, vector<int>(V + 1, 1000000000));
	for ( int i = 0; i < E; i++ ) {
		cin >> a >> b >> c;
		arr[a][b] = c;
	}

	for ( int k = 1; k < V + 1; k++ ) {
		for ( int i = 1; i < V + 1; i++ ) {
			for ( int j = 1; j < V + 1; j++ ) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);	//플로이드 워셔
			}
		}
	}

	for ( int i = 1; i < V + 1; i++ ) {
		for ( int j = 1; j < V + 1; j++ ) {
			if ( i == j )continue;
			total_min = min(total_min, arr[i][i]);		//자기자신으로 돌아오는 것만 확인
		}
	}

	if ( total_min == 1000000000 ) {		//total_min이 바뀌지 않았다면 -1 출력
		cout << -1 << endl;
		return 0;
	}
	cout << total_min << endl;
	return 0;
}