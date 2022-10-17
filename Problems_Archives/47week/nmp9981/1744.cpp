#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> posi;//양수
int one;//1
vector<int> nega;//0 이하

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x > 1) posi.push_back(x);
		else if (x == 1) one++;
		else nega.push_back(x);//절댓값으로
	}
	//정렬, 큰수부터 곱해야 최댓값을 구할 수 있다.
	if(posi.size()>0) sort(posi.begin(), posi.end(), greater<int>());
	if (nega.size() > 0) sort(nega.begin(), nega.end());
}
//수묶기
void Bind() {
	int ans = 0;
	//양수
	if (posi.size() % 2 == 1) ans += posi[posi.size() - 1];//마지막 수
	if (posi.size() >= 2) {
		for (int i = 0; i < posi.size()-1; i += 2) ans += (posi[i] * posi[i + 1]);//더하기
	}
	//음수
	if (nega.size() % 2 == 1) ans += nega[nega.size() - 1];//마지막 수(음수)
	if (nega.size() >= 2) {
		for (int i = 0; i < nega.size()-1; i += 2) ans += (nega[i] * nega[i + 1]);//더하기
	}
	cout << ans+one;//출력
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	Bind();//수 묶기
	return 0;
}
