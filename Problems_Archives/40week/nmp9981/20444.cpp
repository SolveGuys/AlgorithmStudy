#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
ll n,k;

//입력
void input() {
	cin >> n>>k;
}

//종이의 개수
ll NumberOfPaper(ll x, ll y) {
	return (x + 1) * (y + 1);
}
//종이 자르기
bool CutPaper() {
	//가로 개수 기준
	ll start = 0;
	ll end = n / 2;
	while (start <= end) {
		ll mid = (start + end) / 2;
		ll amount = NumberOfPaper(mid, n - mid);
		if (amount == k) return true;
		else if (amount < k) start = mid + 1;
		else if (amount > k) end = mid - 1;
	}
	return false;
}

//출력
void output(bool exist) {
	if (exist == true) cout << "YES";
	else cout << "NO";
}
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	output(CutPaper());//종이 자르기
    return 0;
}
