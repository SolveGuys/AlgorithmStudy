#include<iostream>
#include<vector>
#include<algorithm>

/*
	�Ÿ����� ������ �� �������� ��ü ��� �� / 2�� �Ǵ� ������ ã���� �� ������ ���̴�.

*/



using namespace std;

typedef pair<int, int> ii;

bool cmp(ii &a, ii &b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<ii> town(N);
	long long sum = 0;
	for ( int i = 0; i < N; i++ ) {
		cin >> town[i].first >> town[i].second;
		sum += town[i].second;
	}

	long long th = sum / 2;
	if ( sum % 2 == 1 ) th += 1;	//sum�� 101 �� �� sum/2�� �ϸ� th�� 50�̴�. 
									//������ 50�� ���ݼ��� �ѱ��� ���ϹǷ� �Ϻη� 1�� ���� 51�� ����� ���ݼ��� �ѱ⵵�� �Ͽ���.

	sort(town.begin(), town.end(), cmp);

	long long tmp = 0;

	for ( int i = 0; i < N; i++ ) {
		tmp += town[i].second;
		if ( tmp >= th ) {
			//�������� ���ݼ��� �ѱ�� ��� �츮 ã�� �����̴�.
			cout << town[i].first << endl;
			break;
		}
	}

	return 0;
}