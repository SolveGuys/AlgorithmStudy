#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

long sol(vector<int> &change, vector<int> &nochange, int &T) {
	int n = change.size();
	
	map<int, int> mm;

	for ( int i = 0; i < n; i++ ) {
		
		//A[0] ~ A[i]������ ��
		mm[change[i]]++;	
		
		for ( int j = 0; j < i; j++ ) {
			//A[k] ~ A[i]������ �� (K = 1,2,3, ... ,i-1,i)
			mm[change[i] - change[j]]++;
		}
	}
	
	int sz = nochange.size();
	long sum = 0;
	int findN = 0;
	for ( int i = 0; i < sz; i++ ) {
		//nochange[i] �� B[0] ~ B[i]������ �հ� ����.
		findN = T - nochange[i];
		//findN�� ã�ƾ��ϴ� ��
		if ( mm.find(findN) != mm.end() ) {
			//map�ȿ� �����Ѵٸ� �� �ش� value�� sum�� ������(value : findN�� A�迭 ���� ��Ʋ� ���� Ƚ��)
			sum += mm[findN];
		}
		for ( int j = 0; j < i; j++ ) {
			//nochange[i] - nochange[j] : B[k] ~ B[i]�� �� (k = 1,2,3, ... ,i-1, i)
			findN = T - (nochange[i] - nochange[j]);
			if ( mm.find(findN) != mm.end() ) {
				//���� ����
				sum += mm[findN];
			}
		}
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	int n, m;
	cin >> n;
	vector<int> A(n, 0);
	for ( int i = 0; i < n; i++ ) {
		int t;
		cin >> t;
		if ( i == 0 ) {
			A[i] = t;
			continue;
		}
		A[i] = A[i - 1] + t;
	}
	cin >> m;
	vector<int> B(m, 0);
	for ( int i = 0; i < m; i++ ) {
		int t;
		cin >> t;
		if ( i == 0 ) {
			B[i] = t;
			continue;
		}
		B[i] = B[i - 1] + t;
	}
	long res = 0;
	//�ð� ���⵵�� ���̱� ���� ���Ұ� �� ���� �迭�� map�� ����.(��� ������..)
	if ( n < m ) {
		res = sol(B, A, T);
	}
	else {
		res = sol(A, B, T);
	}
	cout << res << endl;
	return 0;
}