#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> crain;//크레인
vector<int> box;//상자

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		crain.push_back(x);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int y;
		cin >> y;
		box.push_back(y);
	}
	//내림차순 정렬
	sort(crain.begin(), crain.end(), greater<int>());
	sort(box.begin(), box.end(), greater<int>());
}
//옮기기
void carry() {
	int cnt = 0;//횟수
	while (!box.empty()) {
		cnt++;
		//강한 크레인부터
		for (int i = 0; i < n; i++) {
			//상자를 옮긴다.
			for (int j = 0; j < box.size(); j++) {
				//옮길 수 있으면 상자 제거
				if (crain[i] >= box[j]) {
					box.erase(box.begin()+j);
					break;
				}
			}
		}
	}
	cout << cnt;//출력, 마지막 포함
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	if (box[0] > crain[0]) cout << -1;//옮길 수 없음
	else carry();//옮기기
	return 0;
}
