#include <iostream>
#include <string>

typedef long long ll;
using namespace std;

string code;
ll dp[5005];
bool err;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> code; // Input

	// Exception1 : 젤 앞에 0이 오는 경우는 해석할 수 없는 암호코드이다.
	if (code[0] == '0') {
		cout << 0 << '\n';
		return 0;
	}

	// Init
	dp[0] = 1; // 한 자리는 무조건 1가지로 해석 가능.

	// 두 글자 파싱
	string init = code.substr(0, 2);
	int val = std::stoi(init);

	
	if (val <= 26 && val >= 1) { // 두 글자를 하나의 문자로 대체가능한 경우
		if (code[1] != '0') dp[1] = 2; 
		else dp[1] = 1;
	} else { // 두 글자를 하나의 문자로 대체 불가능한 경우
		if (code[1] == '0') {
			err = true;
		}
		dp[1] = 1;
	}

	// Dp
	for (int i = 2; i < code.size(); i++) {
		string str;
		str += code[i - 1];
		str += code[i];

		int value = std::stoi(str);

		// 두 글자를 하나의 문자로 대체가능한 경우 ( 0X 의 경우도 한 문자로 만들지 못한다)
		if (value <= 26 && value >= 1 && code[i-1] != '0') {
			if (code[i] != '0') { // 끝자리가 0이 아닌 경우는 하나짜리로도 가능, 두개 짜리로도 가능 (ex. 21)
				dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000;
			}
			else { // 끝자리가 0이면 두개 짜리로만 가능 (ex. 20)
				dp[i] = dp[i - 2] % 1000000;
			}
		}
		else { // 두 글자를 하나의 문자로 대체 불가능한 경우
			if (code[i] == '0') { // 끝자리가 0이면 해석 불가 암호 (ex. 30)
				err = true;
				break;
			}
			dp[i] = dp[i - 1] % 1000000; // 0이 아니면 하나짜리로 가능) (ex. 36)
		}
	}

	// 해석 불가능하면 0
	if (err) {
		cout << 0;
	}
	else {
		cout << dp[code.size() - 1] % 1000000;
	}

	

	return 0;
}