#include <iostream>

using namespace std;
int N;
double X;
double burger[51] = { 0 };
double patty[51] = { 0 };
double ans=0;

void solve(int n,double lower) {
	if (lower == 0 ) {
		printf("%0.lf",ans);
		return;
	}
	else if (n == 0) {
		ans++;
		printf("%0.lf", ans);
		return;
	}
	lower--;
	if (lower == burger[n - 1]) {
		ans += patty[n - 1];
		lower -= (burger[n - 1]);
		solve(n - 1, lower);
	}
	else if (lower < burger[n - 1]) {
		solve(n-1, lower);
	}
	else if (lower > burger[n - 1]) {
		ans += patty[n - 1] + 1;
		lower -= (burger[n - 1] + 1);
		solve(n-1, lower);
	}
}

int main() {

	cin >> N >> X;
	burger[0] = 1; patty[0] = 1; 
	for (int i = 1; i <= 50; i++) {
		burger[i] = 2 * burger[i-1] + 3;
		patty[i] = 2 * patty[i-1] + 1;
	}
	solve(N,X);
}
