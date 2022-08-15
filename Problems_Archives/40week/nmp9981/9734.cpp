#include <iostream>
#include <cstring>
using namespace std;

string num;
int gcd,up,down;

//최대공약수
int GCD(int x, int y) {
	while (y != 0) {
		int r = x % y;
		x = y;
		y = r;
	}
	return x;
}

//10의 거듭제곱 구하기
int pow(int x) {
	int res10 = 1;
	for (int i = 0; i < x; i++) res10 *= 10;
	return res10;
}

//분자 구하기
int Numerator() {
	int allNum = 0;//전체 숫자
	int index = 0;//괄호의 위치
	//전체 숫자
	for (int i = 0; i < num.size() - 1; i++) {
		if (num[i] == '(') index = i;
		else if (num[i] != '.') {
			int nextNum = 10 * allNum;
			allNum = nextNum+(num[i]-'0');
		}
	}
	//괄호 내부
	int pointNum = 0;//빠지는 숫자
	for (int i = 0; i < index; i++) {
		if (num[i] == '.') continue;
		int nextNum = 10 *pointNum;
		pointNum = nextNum + (num[i] - '0');
	}
	return allNum - pointNum;
}

//분모 구하기
int Denominator() {
	int allCount = 0;//전체 자릿수
	int pointCount = 0;//소수점 아래위치
	int parenthesisIndex = 0;//'('위치
	int pointIndex = 0;//소수점 위치
	for (int i = 0; i < num.length() - 1; i++) {
		if (num[i] == '.') {
			pointIndex = i;
		}
		else if (num[i] == '(') {
			parenthesisIndex = i;
		}
	}
	allCount = num.length() - pointIndex - 3;//소수점,괄호 제외
	pointCount = parenthesisIndex-pointIndex - 1;//괄호 제외
	return pow(allCount) - pow(pointCount);
}

int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> num) {//EOF입력
		up = Numerator();//분자
		down = Denominator();//분모
		gcd = GCD(up, down);//분자와 분모의 최대공약수
		cout << num << " = " << (up / gcd) << " / " << (down / gcd) << "\n";//출력
	}
    return 0;
}
