#include <iostream>
#include <vector>
using namespace std;

int n,m;
const int maxi = 51;
const int inf = 10000000;
int world[maxi][maxi];//지도
vector<pair<int, int>> chicken;//치킨집
vector<pair<int, int>> selectChicken;//선택한 치킨집
vector<pair<int, int>> house;//집
int minDist = inf;//최소 치킨 거리

//min
inline int min(int x, int y) {
	return x > y ? y : x;
}
//입력
void input() {
	cin >> n>>m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> world[i][j];
			if (world[i][j] == 2) chicken.push_back({ i,j });//치킨집
			else if (world[i][j] == 1)house.push_back({ i,j });//집
		}
	}
}
//치킨 거리
int ChickenDist() {
	int total = 0;//치킨 거리 합
	//각 집별로 가장 가까운 치킨 거리
	for (int i = 0; i < house.size(); i++) {
		int chikenDist = inf;
		//가장 가까운 치킨집
		for (int j = 0; j < selectChicken.size(); j++) {
			int dist = abs(house[i].first - selectChicken[j].first) + abs(house[i].second - selectChicken[j].second);
			if (chikenDist > dist) chikenDist = dist;//더 작은거리
		}
		total += chikenDist;
	}
	return total;
}
//치킨집 고르기
void setChicken(int idx,int cnt) {
	//m개를 모두 고름
	if (cnt == m) {
		minDist = min(minDist, ChickenDist());//치킨 거리
		return;
	}
	//다음 지점
	for (int i = idx; i < chicken.size(); i++) {
		selectChicken.push_back(chicken[i]);
		setChicken(i + 1, cnt + 1);
		selectChicken.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	setChicken(0,0);//치킨집 고르기
	cout << minDist;
	return 0;
}
