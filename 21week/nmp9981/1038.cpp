#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> number;
//감소하는 수
void dfs(int cnt,int start,int digit) {
	//자릿수 채우기
	if (cnt == digit) {
		number.push_back(start);
		return;
	}
	//더 작은숫자
	for (int i = start%10-1; i >=0; i--) {
		int next = 10 * start + i;
		dfs(cnt + 1, next, digit);
	}
}
int main() {
	cin>>n;//입력
	if (n > 1022) cout << -1;
	else if (n == 1022) cout << 9876543210;//long long범위라 따로 처리
	else {
		for (int i = 1; i <= 9; i++) {//자릿수
			for (int j = 9; j >= 0; j--) {//시작숫자
				dfs(1, j,i);
			}
		}
		sort(number.begin(), number.end());//정렬
		cout << number[n];//출력
	}
	return 0;
}
