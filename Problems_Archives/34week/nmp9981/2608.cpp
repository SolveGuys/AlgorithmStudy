#include <iostream>
using namespace std;

string a; string b;
int add;

//입력
void input() {
	cin >> a >> b;
}

//숫자로 바꾸기
int changeNum(string x) {
	int n = 0;
	int idx = 0;
	while (idx < x.size()) {
		switch (x[idx]) {
		case 'M':
			n += 1000;
			break;
		case 'D':
			n += 500;
			break;
		case 'C':
			if (idx+1<x.size() && x[idx + 1] == 'M') {
				n += 900;
				idx += 1;
			}
			else if (idx + 1 < x.size() && x[idx + 1] == 'D') {
				n += 400;
				idx += 1;
			}
			else n += 100;
			break;
		case 'L':
			n += 50;
			break;
		case 'X':
			if (idx + 1 < x.size() && x[idx + 1] == 'C') {
				n += 90;
				idx += 1;
			}
			else if (idx + 1 < x.size() && x[idx + 1] == 'L') {
				n += 40;
				idx += 1;
			}
			else n += 10;
			break;
		case 'V':
			n += 5;
			break;
		case 'I':
			if (idx + 1 < x.size() && x[idx + 1] == 'X') {
				n += 9;
				idx += 1;
			}
			else if (idx + 1 < x.size() && x[idx + 1] == 'V') {
				n += 4;
				idx += 1;
			}
			else n += 1;
			break;
		}
		idx += 1;
	}
	return n;
}
//로마자로 바꾸기
void changeRome(int x) {
	while (x > 0) {
		if (x >= 1000) {
			cout << "M";
			x -= 1000;
		}else if (x >= 900) {
			cout << "CM";
			x -= 900;
		}
		else if (x >= 500) {
			cout << "D";
			x -= 500;
		}
		else if (x >= 400) {
			cout << "CD";
			x -= 400;
		}
		else if (x >= 100) {
			cout << "C";
			x -= 100;
		}
		else if (x >= 90) {
			cout << "XC";
			x -= 90;
		}
		else if (x >= 50) {
			cout << "L";
			x -= 50;
		}
		else if (x >= 40) {
			cout << "XL";
			x -= 40;
		}
		else if (x >= 10) {
			cout << "X";
			x -= 10;
		}
		else if (x == 9) {
			cout << "IX";
			x -= 9;
		}
		else if (x >= 5) {
			cout << "V";
			x -= 5;
		}
		else if (x == 4) {
			cout << "IV";
			x -= 4;
		}
		else if (x >= 1) {
			cout << "I";
			x -= 1;
		}
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	add = changeNum(a)+changeNum(b);//두 수 더하기
	cout << add << "\n";//합 결과 출력
	changeRome(add);//로마자로 바꾸기
	return 0;
}
