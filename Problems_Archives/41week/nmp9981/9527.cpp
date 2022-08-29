#include <iostream>
using namespace std;
typedef long long ll;

ll a, b;

//입력
void input() {
	cin >> a >> b;
}
//1의 개수 구하기
ll f(ll x) {
	ll countBit = 0;
	ll pattern = 2;//자릿수 패턴의 길이(01)
	
	while (pattern <= x) {//패턴의 길이 기준
		countBit += (x / pattern) * (pattern / 2);//각 자릿수에 대해
		//절반 이후
		if ((x % pattern)>=(pattern/2)) countBit += ((x % pattern) - (pattern / 2)+1);
		pattern *= 2;//패턴 길이 증가
	}
	//맨 앞자리
	if ((x % pattern) >= (pattern / 2)) countBit += ((x % pattern) - (pattern / 2)+1);
	return countBit;
}
int main()
{
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	cout << f(b) - f(a-1) << "\n";
	return 0;
}
