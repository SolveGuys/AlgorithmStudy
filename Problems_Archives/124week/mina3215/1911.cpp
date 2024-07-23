#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>

using namespace std;

int N, L;

vector<pair<int, int>> v;

void input() {
	int s, e;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		v.push_back({ s,e });
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> L;

	int cnt = 0;
	// 마기막 널빤지가 끝나는 좌표
	// 웅덩이가 0좌표 부터 시작될 수 있기 때문에 -1 할당.
	int prev_e = -1;
	
	input();
	// 웅덩이 좌표 정렬 
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		int s, e;
		tie(s, e) = v[i];
		// 시작 위치에 이미 널빤지가 있는지 확인 
		// 널빤지가 없는 곳으로 시작 위치 변경
		if (s <= prev_e)
			s = prev_e + 1;
		// 끝 지점까지 널빤지 유무 확인 (이미 전부 덮고 있는가?) 
		if (s >= e)
			continue;
		
		// 웅덩이 길이 확인 후 널빤지 개수 체크. 
		int len = e - s;
		cnt += len / L;
		if (len % L) {
			cnt++;
			// 마지막 널빤지 좌표 체크.
			prev_e = e + (L - (len % L))-1;
		}
		else
			// 마지막 널빤지 좌표 체크.
			prev_e = e-1;
	}
	cout << cnt;
}