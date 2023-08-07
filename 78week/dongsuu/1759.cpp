#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
char chars[16];
int isSelected[16];
vector<char> selected;
vector<string> answer;

// 현재까지 선택한 문자들이 사전순인지 판별
bool isValidate() {
	if (!selected.empty()) {
		for (int i = 0; i < selected.size() - 1; i++) {
			if (selected[i] > selected[i + 1]) return false; // 사전순 아니면 FALSE
		}
	}
	return true;
}

// 모음인지 판별
bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	return false;
}

// 부분집합 
void solve(int cnt, int vowelCnt, int consonantCnt) { // 현재까지 뽑은 cnt: 총 개수, vowelCnt: 모음 개수, consonantCnt: 자음 개수
	if (!isValidate()) return; // 사전순 정렬 안되어있는 경우 종료
	if (cnt == L) { // 길이 L인 암호가 완성된 경우
		if (vowelCnt < 1 || consonantCnt < 2) return; // 최소의 모음,자음 개수 맞지 않는 경우 종료
		// Answer를 answer vector에 넣어두고 나중에 sort해서 출력
		string s = "";
		for (int i = 0; i < selected.size(); i++) {
			s += selected[i];
		}
		answer.push_back(s);
		return;
	}
	
	// 재귀 호출
	for (int i = 0; i < C; i++) { // 순서는 다르게 뽑을 수 있으므로 i=0부터
		if (!isSelected[i]) { // 중복 X
			// 선택
			isSelected[i] = 1;
			selected.push_back(chars[i]);
			if (isVowel(selected[cnt])) vowelCnt += 1; // 모음, 자음 개수 count
			else consonantCnt += 1;
			solve(cnt + 1, vowelCnt, consonantCnt);

			// 다시 돌려놓기 (백트랙킹)
			isSelected[i] = 0;
			if (isVowel(selected[cnt])) vowelCnt -= 1;
			else consonantCnt -= 1;
			selected.erase(selected.begin() + cnt);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// Input
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> chars[i];
	}

	solve(0, 0, 0); // 답 구하기
	std::sort(answer.begin(), answer.end()); // 정렬

	// 출력
	for (int i = 0; i < answer.size(); i++) {
		for (int j = 0; j < answer[i].size(); j++) {
			cout << answer[i][j];
		}
		cout << '\n';
	}


	return 0;
}