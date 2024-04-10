#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> ii;

vector<int> arr(200000, 0);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	int time = 1;
	int cnt = 0;
	bool isfirst = 0;
	cin >> N >> K;
	if ( N == K ) {
		cout << 0 << endl << 1 << endl;
		return 0;
	}
	arr[N] = -1;
	queue<int> que;
	que.push(N);
	while ( !que.empty() ) {
		int x = que.front();
		que.pop();
		if ( arr[x] == time ) {
			time++;
		}
		
		
		if ( isfirst && x!=K ) {
			continue;
		}
		
		
		if ( x == K ) {
			isfirst = true;
			cnt++;
		}
		
		if ( x < K ) {
			if ( x - 1 >= 0 && (arr[x - 1] == 0 || arr[x-1]==time)) {
				que.push(x - 1);
				arr[x - 1] = time;
			}
			if ( 2 * x < 200000 && (arr[2 * x] == 0 || arr[2 * x] == time) ) {
				que.push(2 * x);
				arr[2 * x] = time;
			}
			if ( arr[x + 1] == 0 || arr[x + 1] == time ) {
				que.push(x + 1);
				arr[x + 1] = time;
			}
		}
		else if ( x > K ) {
			if ( arr[x - 1] == 0 || arr[x - 1] == time ) {
				que.push(x - 1);
				arr[x - 1] = time;
			}
		}
	}
	cout << arr[K] << endl << cnt << endl;

	return 0;
}