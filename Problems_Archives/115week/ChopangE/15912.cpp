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
		cost[i] = cost[i - 1] + maxW * maxE;			//���� cost�� ���� ��ǰ�� ����� ��
		//�׷��� ��� : a���� b������ �׷��̶�� a���� b������ �ִ� ��ǰ�� ���Կ� �ִ� ��ǰ�� �������� ���� �� �׷��� ��� 
		//cost[j-1](j-1������ �ּڰ�)��°�� i(����)���� j���� �׷��� ����� ���ؼ� �ּڰ��� ������ cost[i]�� update 
		for ( int j = i - 1; j > 0; j-- ) {		
			maxW = max(array[j].first, maxW);
			maxE = max(array[j].second, maxE);
			cost[i] = min(cost[j - 1] + maxW * maxE, cost[i]);
		}
	}

	cout << cost[N] << endl;
	return 0;
}