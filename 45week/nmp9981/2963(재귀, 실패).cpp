#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef unsigned long long ull;

string s;//문자열
ull sum = 1;//초기값

//합구하기
ull StarSum(int cnt,int totalcnt, ull total) {
	if (cnt == totalcnt) return total;//계산 종료

	ull next = total * 5ll + pow(3ll, cnt);//다음 누적합
	StarSum(cnt + 1, totalcnt, next);
}
//탐색
ull Search(string s) {
	int starTotalCount = 0;//총 별의 개수
	int starCount = 0;//연속된 별의 개수
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '*') {
			starCount++;
			starTotalCount++;
		}
		else {
			sum = StarSum(0, starCount, sum);//*에따른 누적합 구하기
			if (s[i] == 'L') {//왼쪽
				sum *= 2;
			}
			else if (s[i] == 'R') {//오른쪽
				sum = sum * 2 + pow(3ll, starTotalCount);//총 별의 개수 사용
			}
			starCount = 0;//초기화
		}
	}
	sum = StarSum(0, starCount, sum);//마지막 *부분
	return sum;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> s;//문자열
	cout<<Search(s);//탐색
	return 0;
}
