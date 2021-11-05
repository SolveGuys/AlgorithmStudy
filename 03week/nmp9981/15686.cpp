#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <deque>
#include <math.h>
using namespace std;

vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<pair<int, int>> selected_chicken;



int n, m;
int ans = 999999;
int cnt_home = 0;
int tot_distance = 0;
int cnt = 0;
int map[51][51] = { 0 };
int chicken_distance[101] = { 0 };

void dfs(int cnt, int num) {

	//치킨집 m개 뽑았을 때
	if (cnt == m) {

		//거리 계산하기
		for (int i = 0; i < cnt_home; i++) {
			int hx = home[i].first;
			int hy = home[i].second;

			for (int j = 0; j < m; j++) {
				int cx = selected_chicken[j].first;
				int cy = selected_chicken[j].second;

				chicken_distance[i] = min(chicken_distance[i], (abs(hx - cx) + abs(hy - cy)));
			}
		}

		//도시의 치킨거리 계산
		for (int i = 0; i < cnt_home; i++) {
			tot_distance += chicken_distance[i];
		}

		ans = min(ans, tot_distance);

		
		//초기화
		tot_distance = 0;
		

		for (int i = 0; i < cnt_home; i++)
			chicken_distance[i] = 999999;

		return;
	}




	for (int i = num; i < chicken.size(); i++) {
		//치킨집 선택후 벡터에 삽입
		selected_chicken.push_back(chicken[i]);
		dfs(cnt + 1, i + 1);
		selected_chicken.pop_back();
	}

}


int main() {

	cin >> n >> m;


	//map 입력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];

			//집의 좌표는 벡터에 저장
			if (map[i][j] == 1) {
				home.push_back(make_pair(i, j));
				cnt_home++;
			}

			//치킨가게 위치 벡터에 저장
			if (map[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < cnt_home; i++)
		chicken_distance[i] = 999999;


	dfs(0, 0);
	cout << ans << endl;




	return 0;

}
