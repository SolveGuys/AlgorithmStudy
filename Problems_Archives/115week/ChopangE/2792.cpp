#include<iostream>
#include<vector>

using namespace std;

int check(vector<int> &color, int &N, int &num) {
	int size = color.size();
	int sum = 0;
	for ( int i = 0; i < size; i++ ) {
		int a = color[i] / num;
		int b = color[i] % num;
		if ( b != 0 ) {
			sum += a + 1;
		}
		else {
			sum += a;
		}	
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int> color(M);
	int maxColor = 0;
	for ( int i = 0; i < M; i++ ) {
		cin >> color[i];
		maxColor = max(maxColor, color[i]);
	}
	int left = 1;
	int right = maxColor;
	int res = 0;
	while ( left <= right ) {
		int mid = (left + right) / 2;
		int num = check(color, N, mid);

		if ( num > N ) {
			left = mid + 1;
		}
		else  {
			res = mid;
			right = mid - 1;
		}
		
	}

	cout << res << endl;



	return 0;
}