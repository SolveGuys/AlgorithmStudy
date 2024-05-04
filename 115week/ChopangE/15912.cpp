#include<iostream>
#include<vector>

using namespace std;

typedef pair<long long, long long> ii;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<ii> array(N + 1);
	vector<long long> cost(N + 1, 0);
	for ( int i = 1; i < N + 1; i++ ) {
		int w;
		cin >> w;
		array[i].first = w;
	}
	for ( int i = 1; i < N + 1; i++ ) {
		int e;
		cin >> e;
		array[i].second = e;
	}
	for ( int i = 1; i < N + 1; i++ ) {
		long long maxW = array[i].first;
		long long maxE = array[i].second;
		cost[i] = cost[i - 1] + maxW * maxE;			//직전 cost와 현재 부품의 비용의 합
		//그룹의 비용 : a부터 b까지가 그룹이라면 a부터 b까지의 최대 부품의 무게와 최대 부품의 에너지의 곱이 이 그룹의 비용 
		//cost[j-1](j-1까지의 최솟값)번째와 i(현재)부터 j까지 그룹의 비용을 더해서 최솟값이 나오면 cost[i]를 update 
		for ( int j = i - 1; j > 0; j-- ) {		
			maxW = max(array[j].first, maxW);
			maxE = max(array[j].second, maxE);
			cost[i] = min(cost[j - 1] + maxW * maxE, cost[i]);
		}
	}

	cout << cost[N] << endl;
	return 0;
}