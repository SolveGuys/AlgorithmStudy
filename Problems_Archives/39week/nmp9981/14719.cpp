#include <iostream>
using namespace std;

int h,w;
const int maxi = 501;
int height[maxi];//높이
int maxiHeight;//최대 높이
int maxiHeightIndex;//최대 높이의 위치

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}

//입력
void input() {
	cin >> h>>w;
	for (int i = 0; i < w; i++) {
		cin >> height[i];
		maxiHeight = max(maxiHeight, height[i]);//최대 높이 구하기
	}
	//최대 높이의 위치
	for (int i = 0; i < w; i++) {
		if (maxiHeight == height[i]) maxiHeightIndex = i;
	}
}

//빗물 채우기
void Raining() {
	int left = 0;//왼쪽 기준 기둥
	int right = w-1;//오른쪽 기준 기둥
	int water = 0;//총 물의 양
	//왼쪽
	for (int i = 0; i < maxiHeightIndex; i++) {
		//기준 기중보다 낮으면 더함
		if (height[left] > height[i]) water += height[left] - height[i];
		else left = i;//기준 기둥보다 높으면 기준 기둥 갱신
	}
	//오른쪽
	for (int i = w-1; i > maxiHeightIndex; i--) {
		//기준 기중보다 낮으면 더함
		if (height[right] > height[i]) water += height[right] - height[i];
		else right = i;//기준 기둥보다 높으면 기준 기둥 갱신
	}
	cout << water;//출력
}

int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	Raining();//빗물 채우기
    return 0;
}
