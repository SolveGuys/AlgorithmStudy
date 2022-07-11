#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N;
bool check[10]; // 0 ~ 9까지의 수 중 사용한 것은 true, 아니면 false. 
vector <int> num;         // 현재 내가 선택한 수를 담을 배열
vector <int> max_vector;  // 최대값
vector <int> min_vector;  // 최소값
string ch;
long long max_value = 0;
long long min_value = 9999999999;

void set(int index, int loc);
bool promising(vector<int> num, int count);

int main() {
	char c;
	cin >> N;

	// check[] false로 초기화
	for (int i = 0; i < 10; i++) {
		check[i] = false;
	}

	// 부등호 정보 입력 후, string에 담아둔다. 
	for (int i = 0; i < N; i++) {
		cin >> c;
		ch.push_back(c);
	}

	// start 
	set(0, 0);

	// max, min 출력
	for(int i=0; i<max_vector.size(); i++)
		cout << max_vector.at(i);
	cout << endl;
	for(int j=0; j<max_vector.size(); j++)
		cout << min_vector.at(j);
}

void set(int index, int count) {
	// 현재 선택한 숫자가 promising하면 진행.
	// 즉, promising하면 숫자를 선택할 것이다. 
	if (promising(num,count)) {
		if (num.size() == ch.size() + 1) { // 부등호 수+1 개의 숫자가 넣어지면 다 넣은 것. (종료)
			
			// max와 min값 계산. 첫째 자리의 0도 출력해야해서 vector 이용.
			long long value = 0;
			for (int i = 1; i <= num.size(); i++) {
				value = value + num.at(num.size() - i) * pow(10, i - 1);
			}
			if (value > max_value) {
				max_value = value;
				max_vector = num;
			}
			if (value < min_value) {
				min_value = value;
				min_vector = num;
			}
		}

		else {
			// 선택한 수는 true로 표시해두고, num에 넣고, 탐색하다가 안되면 false로 바뀌고 num에서 빼낸다.
			// 재귀적으로 구현
			for (int i = 0; i < 10; i++) {
				if (check[i] == true)
					continue;
				num.push_back(i);
				check[i] = true;
				set(i+1,count+1);
				check[i] = false;
				num.pop_back();
			}
		}
	}
}

// promising함수. 
// 내가 선택한 수가 promising한지 판별. 
// promising하면 true, 아니면 false로 return
bool promising(vector<int> num, int count) {
	if (num.size() == 0 || num.size() == 1) // 처음 실행에서 하나까지는 아무 숫자가 와도 성립한다.
		return true;

		if (ch.at(count-2) == '<') { 
			if (num.at(count-2) < num.at(count-1)) {
				return true; // 부등호 성립
			}
			else
				return false; // 부등호 성립x
		}
		else if (ch.at(count-2) == '>') {
			if (num.at(count-2) > num.at(count-1)) { 
				return true; // 부등호 성립
			}
			else
				return false; // 부등호 성립 x
		}
}
