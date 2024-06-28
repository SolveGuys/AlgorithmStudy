#include<iostream>
#include<vector>
#include<map>

using namespace std;
/*
	행에 있는 모든 램프의 상태가 같은 램프들만이 최종적으로 같은상태가 될 수 있다.
	스위치를 누를 때마다 열 전체를 바꾸기 때문인데,
	예를들어 
	000011001
	000111001
	000011001
	110011001
	이라는 램프가 있을 때 첫번째와 두번째 램프는 절대로 마지막에 모든 램프가 같은 상태가 될 수 없다.
	그래서 이 문제의 출력은 다음과 같은 두가지 조건을 고려해야한다.
	1. 0의 개수가 짝수일때 K도 같이 짝수, 0의 개수가 홀수일때 K도 같이 홀수인 행은 마지막에 모두 켜져있을 수 있다.
	   즉 정답행이 될 수 있다.
	2. 초기상태가 아예 똑같은 행들은 마지막에도 무조건 똑같다.
	   즉 1번조건을 만족시키는 행들 중 중복으로 가장 많이 존재하는 행의 개수가 출력값이 된다.
*/
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, K;
	cin >> N >> M;
	map<string, int> mm;			//개수를 map에 담아두었다.
	vector<string> lamp(N);			
	for ( int i = 0; i < N; i++ ) {
		cin >> lamp[i];
	}
	cin >> K;
	for ( string s : lamp ) {
		int t = 0;
		for ( char c : s ) {
			if ( c == '0' ) t++;		//0의 개수 세기
		}
		if ( t > K || (t % 2 != K % 2) ) {		//t가 K보다 크면 정답행 불가. 0의 개수와 K가 짝홀이 다르면 정답행 불가.
			continue;
		}
		mm[s]++;		//위의 조건을 무시했다면 정답행의 조건 충족하므로 map에 저장.
	}
	int total = 0;
	for ( auto iter = mm.begin(); iter != mm.end(); iter++ ) {
		total = max(total, iter->second);
	}
	cout << total << endl;
	return 0;
}