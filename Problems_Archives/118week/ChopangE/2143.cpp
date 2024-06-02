#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

long sol(vector<int> &change, vector<int> &nochange, int &T) {
	int n = change.size();
	
	map<int, int> mm;

	for ( int i = 0; i < n; i++ ) {
		
		//A[0] ~ A[i]까지의 합
		mm[change[i]]++;	
		
		for ( int j = 0; j < i; j++ ) {
			//A[k] ~ A[i]까지의 합 (K = 1,2,3, ... ,i-1,i)
			mm[change[i] - change[j]]++;
		}
	}
	
	int sz = nochange.size();
	long sum = 0;
	int findN = 0;
	for ( int i = 0; i < sz; i++ ) {
		//nochange[i] 는 B[0] ~ B[i]까지의 합과 같다.
		findN = T - nochange[i];
		//findN은 찾아야하는 값
		if ( mm.find(findN) != mm.end() ) {
			//map안에 존재한다면 그 해당 value를 sum에 더해줌(value : findN이 A배열 조합 통틀어서 나온 횟수)
			sum += mm[findN];
		}
		for ( int j = 0; j < i; j++ ) {
			//nochange[i] - nochange[j] : B[k] ~ B[i]의 합 (k = 1,2,3, ... ,i-1, i)
			findN = T - (nochange[i] - nochange[j]);
			if ( mm.find(findN) != mm.end() ) {
				//위와 동일
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
	//시간 복잡도를 줄이기 위해 원소가 더 많은 배열을 map에 넣음.(사실 조삼모사..)
	if ( n < m ) {
		res = sol(B, A, T);
	}
	else {
		res = sol(A, B, T);
	}
	cout << res << endl;
	return 0;
}