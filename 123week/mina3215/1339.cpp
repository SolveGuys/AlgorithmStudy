#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

// 그리디 | 순열
// 제한 시간 : 2초

/* 1. 순열
*  WHY? 그리디 or 완전 탐색
*  단어수 <= 10, 알파벳 <= 9
*  주어진 알파벳을 순열로 표현한다 했을때, 
*  9! => 7십만? 2초 내로 될 듯? => next_permutation O(N*N!) => 7백만
*  
*  가능은 한데, stoi, to_string => 이런걸 포함하면 시간이 초과됨. 
*  다른 언어로 가능할지도 잘 모르겠음
*/

/*
* 2. 그리디 (써칭...)
* ABCDE, EEE
* A : 10000
* B : 1000
* C : 100
* D : 10
* E : 112
* 
* 생각해야 할 거 : 
* 1. 높은 숫자대로 번호를 부여한다. 
* 2. 같은 자리에 있는 수 중, 아래 자리 숫자가 높은 경우가 더 큰 숫자.
*/



int N;
int _max = 0;
vector<string> words;
int a[26];

void input() {
	cin >> N;
	fill(a, a + 26, 0);
	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		words.push_back(word);
	}
}


int main() {
	// input : 문자열을 words에 담는다
	input();

	// 단어를 돌아가면서 자릿수에 맞는 숫자를 배열에 담아준다
	for(int i=0; i<words.size(); i++){
		int v = 1;
		for (int j = words[i].size() - 1; j >= 0; j--) {
			a[words[i][j] - 'A'] += v;
			v *= 10;
		}
	}

	// 문자와 상관없이 숫자만을 기준으로 9 -> 1까지 배정. 
	// sort.
	sort(a, a + 26, greater<int>());

	int answer = 0;
	int cnt = 9;
	for (auto i : a) {
		answer += (cnt--) * i;
	}

	cout << answer;

	return 0;
}