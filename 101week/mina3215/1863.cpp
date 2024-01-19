#include<iostream>
#include<stack>
#include<vector>

using namespace std;

stack<int> s;
int N;


int main() {

	cin >> N;
	vector<int> skylines;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		skylines.push_back(y);
	}

	int ans = 0;
	s.push(0);

	for (int i = 0; i < N; i++) {
		//비어있거나 스택의 젤 위 숫자가 다음 숫자보다 작을 경우 push
		if (s.empty() || skylines[i]>s.top()){
			s.push(skylines[i]);
		}
		//비어있지 않고 작을 경우 pop하고 ans+1 위에서 걸리거같긴한데 혹시나 
		else if(!s.empty() && skylines[i]<s.top()){
			while (skylines[i] < s.top()) {
				s.pop();
				ans++;
				if (skylines[i] > s.top()) s.push(skylines[i]);
			}
		}
		//같을 경우는 아무일도 하지 않는다.
	}

	while (!s.empty()) {
		s.pop();
		ans++;
	}

	cout << --ans;
	

}