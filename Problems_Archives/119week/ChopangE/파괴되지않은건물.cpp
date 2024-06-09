#include <string>
#include <vector>

using namespace std;
//https://kimjingo.tistory.com/155
//위 블로그에 엄청나게 자세히 설명되어 있습니다. 참고하시길 바랍니다.
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
	int answer = 0;
	int N = board.size();
	int M = board[0].size();
	vector<vector<int>> sum(N + 1, vector<int>(M + 1, 0));
	for ( vector<int> &a : skill ) {
		int r1, r2, c1, c2, degree;
		int type = a[0];
		r1 = a[1]; c1 = a[2]; r2 = a[3]; c2 = a[4]; degree = a[5];
		//일단 경계값들만 정해준 뒤 나중에 한번에 계산
		if ( type == 1 ) {
			
			sum[r1][c1] += -degree;
			sum[r1][c2 + 1] += degree;
			sum[r2 + 1][c1] += degree;
			sum[r2 + 1][c2 + 1] += -degree;
		}
		else {
			sum[r1][c1] += degree;
			sum[r1][c2 + 1] += -degree;
			sum[r2 + 1][c1] += -degree;
			sum[r2 + 1][c2 + 1] += degree;
		}
	}
	//행으로 밀기
	for ( int i = 0; i < N + 1; i++ ) {
		for ( int j = 0; j < M; j++ ) {
			sum[i][j + 1] += sum[i][j];
		}
	}
	//열로 밀기
	for ( int j = 0; j < M + 1; j++ ) {
		for ( int i = 0; i < N; i++ ) {
			sum[i + 1][j] += sum[i][j];
		}
	}
	//마지막 확인
	for ( int i = 0; i < N; i++ ) {
		for ( int j = 0; j < M; j++ ) {
			if ( sum[i][j] + board[i][j] > 0 )answer++;
		}
	}
	return answer;
}
