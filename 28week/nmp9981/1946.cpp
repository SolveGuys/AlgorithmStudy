#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,test;
vector<pair<int, int>> score;//성적

//초기화
void init() {
	score.clear();
}
//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int document, interview;
		cin >> document>>interview;//서류점수, 면접점수
		score.push_back({ document,interview });
	}
	sort(score.begin(),score.end());//서류점수 기준으로 정렬
}

//사원 선발
void choise() {
	int cnt = 1;
	int max_interview = score[0].second;//면접 최고점수
	for (int i = 1; i < n; i++) {
		if (score[i].second < max_interview) {//서류는 높지만 면접은 더 낮음
			max_interview = score[i].second;//갱신
			cnt++;
		}
	}
	cout << cnt<<"\n";//출력
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> test;
	for (int t = 0; t < test; t++) {
		init();//초기화
		input();//입력
		choise();//사원 선발
	}
	return 0;
}
