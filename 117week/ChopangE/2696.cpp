#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int T, M, N;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for ( int i = 0; i < T; i++ ) {
		cin >> M;
		priority_queue<int,vector<int>, less<int>> left;
		priority_queue<int,vector<int>, greater<int>> right;
		//left는 right에 비해 작은값들이 존재하도록 만든다.
		//left의 top은 right의 top보다 작게 유지시킨다.
		//모든 입력값은 left에 push한다.
		vector<int> res;
		int tmp;
		cin >> tmp;
		//모든 입력값은 left에 push.
		left.push(tmp);
		res.emplace_back(tmp); //1번째 입력은 홀수이므로 res에 삽입.

		for ( int j = 0; j < M -1; j++ ) {
			cin >> tmp;
			left.push(tmp);
			//짝수번째 입력이라면 left의 size가 right의 size 보다 2 더 크므로 가장 큰 값을 right로 보내준다.
			//left와 right의 element수가 같게 된다.
			if ( j % 2 == 0 ) {				
				int left_top = left.top();
				left.pop();
				right.push(left_top);
			}
			//홀수번째 입력이라면 left의 top과 right의 top을 비교하여 left것이 더 크면 바꿔준다.
			//이렇게하면 항상 left가 right보다 작은 값의 element들만을 가지게 된다.
			//left의 top이 중앙값이 된다.
			else {
				int left_top = left.top();
				int right_top = right.top();
				if ( left_top > right_top ) {
					left.pop();
					right.pop();
					right.push(left_top);
					left.push(right_top);
				}
				res.emplace_back(left.top());			//중앙값을 res에 넣는다.
			}
		}

		cout << res.size() << "\n";
		for ( int j = 0; j < res.size(); j++ ) {
			cout << res[j] << " ";
		}
		cout << "\n";
	}


	return 0;
}