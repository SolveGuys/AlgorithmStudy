#include <iostream>
using namespace std;

//최소공배수
int LCM(int a, int b) {
	int AB = a * b;
	if (a<b) swap(a,b);//a가 더 크게
	while (b > 0) {
		int r = a%b;
		a = b;
		b = r;
	}
	return AB/a;
}
//달력
int Calender(int m, int n, int x, int y) {
	int mul = 0;//몫
	int lcm = LCM(m, n);//최소공배수
	while (true) {
		int k = mul * m + x;//후보 숫자
		if (k > lcm) break;//범위 초과 => 해가 없다

		if (k % n == y%n) return k;//정답
		else mul++;//숫자 증가
	}
	return -1;
}
//입력
void input() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int m,n, x, y;
		cin >> m >> n >> x >> y;
		cout<<Calender(m, n, x, y)<<"\n";//달력
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
    input();//입력
	return 0;
}
