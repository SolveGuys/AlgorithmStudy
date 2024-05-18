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
		//left�� right�� ���� ���������� �����ϵ��� �����.
		//left�� top�� right�� top���� �۰� ������Ų��.
		//��� �Է°��� left�� push�Ѵ�.
		vector<int> res;
		int tmp;
		cin >> tmp;
		//��� �Է°��� left�� push.
		left.push(tmp);
		res.emplace_back(tmp); //1��° �Է��� Ȧ���̹Ƿ� res�� ����.

		for ( int j = 0; j < M -1; j++ ) {
			cin >> tmp;
			left.push(tmp);
			//¦����° �Է��̶�� left�� size�� right�� size ���� 2 �� ũ�Ƿ� ���� ū ���� right�� �����ش�.
			//left�� right�� element���� ���� �ȴ�.
			if ( j % 2 == 0 ) {				
				int left_top = left.top();
				left.pop();
				right.push(left_top);
			}
			//Ȧ����° �Է��̶�� left�� top�� right�� top�� ���Ͽ� left���� �� ũ�� �ٲ��ش�.
			//�̷����ϸ� �׻� left�� right���� ���� ���� element�鸸�� ������ �ȴ�.
			//left�� top�� �߾Ӱ��� �ȴ�.
			else {
				int left_top = left.top();
				int right_top = right.top();
				if ( left_top > right_top ) {
					left.pop();
					right.pop();
					right.push(left_top);
					left.push(right_top);
				}
				res.emplace_back(left.top());			//�߾Ӱ��� res�� �ִ´�.
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