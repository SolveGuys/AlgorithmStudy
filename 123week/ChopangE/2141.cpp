#include<iostream>
#include<vector>
#include<algorithm>

/*
	거리별로 정렬한 후 누적합이 전체 사람 수 / 2가 되는 지점을 찾으면 그 지점이 답이다.

*/



using namespace std;

typedef pair<int, int> ii;

bool cmp(ii &a, ii &b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<ii> town(N);
	long long sum = 0;
	for ( int i = 0; i < N; i++ ) {
		cin >> town[i].first >> town[i].second;
		sum += town[i].second;
	}

	long long th = sum / 2;
	if ( sum % 2 == 1 ) th += 1;	//sum이 101 일 때 sum/2를 하면 th는 50이다. 
									//하지만 50은 과반수를 넘기지 못하므로 일부러 1을 더해 51로 만들어 과반수를 넘기도록 하였다.

	sort(town.begin(), town.end(), cmp);

	long long tmp = 0;

	for ( int i = 0; i < N; i++ ) {
		tmp += town[i].second;
		if ( tmp >= th ) {
			//누적합이 과반수를 넘기는 경우 우리 찾는 지점이다.
			cout << town[i].first << endl;
			break;
		}
	}

	return 0;
}