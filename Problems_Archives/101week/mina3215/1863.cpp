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
		//����ְų� ������ �� �� ���ڰ� ���� ���ں��� ���� ��� push
		if (s.empty() || skylines[i]>s.top()){
			s.push(skylines[i]);
		}
		//������� �ʰ� ���� ��� pop�ϰ� ans+1 ������ �ɸ��Ű����ѵ� Ȥ�ó� 
		else if(!s.empty() && skylines[i]<s.top()){
			while (skylines[i] < s.top()) {
				s.pop();
				ans++;
				if (skylines[i] > s.top()) s.push(skylines[i]);
			}
		}
		//���� ���� �ƹ��ϵ� ���� �ʴ´�.
	}

	while (!s.empty()) {
		s.pop();
		ans++;
	}

	cout << --ans;
	

}