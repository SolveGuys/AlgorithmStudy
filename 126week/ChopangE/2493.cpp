#include<iostream>
#include<vector>
#include<stack>

using namespace std;

typedef pair<int, int> ii;
/*
* 
//stack을 활용해 문제 풀이
//stack에 집어넣은 값이 stack의 top보다 크다면 top에 해당하는 탑이 쏜 레이저를 집어넣은 값에 해당하는 탑이 수신하는 것
//오른쪽에서 왼쪽으로 레이저를 쏘므로 뒤에서부터 탐색하여 stack에 삽입

*/
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> arr(N + 1, 0);
	vector<int> res(N + 1, 0);
	for (int i = 1; i < N + 1; i++) {
		cin >> arr[i];
	}
	stack<ii> sta;
	for (int i = N; i > 0; i--) {					//뒤에서부터 탐색
		while (!sta.empty() && sta.top().first < arr[i]) {		//stack이 비어있지 않고 top()에 해당하는 탑의 높이보다 집어넣은 탑의 높이가 클때
			int t = sta.top().first;
			int idx = sta.top().second;
			res[idx] = i;										//결과값 설정
			sta.pop();
		}
		sta.push({ arr[i],i });									
	}
	for (int i = 1; i < N + 1; i++) {
		printf("%d ", res[i]);
	}
	printf("\n");


	return 0;
}