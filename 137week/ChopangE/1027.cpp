#include<iostream>
#include<list>
#include<string>
#include<vector>

using namespace std;

int res;

int main() {
	
	int N;
	cin >> N;

	vector<int> building(N);
	vector<int> cnt(N, 0);
	for ( int i = 0; i < N; i++ )
		cin >> building[i];

	for ( int i = 0; i < N; i++ )
	{
		double max_level = -9999999999;
		for ( int j = i + 1; j < N; j++ )
		{
			double level = (double)(building[j] - building[i]) / (j - i);	//기울기 계산
			if ( level > max_level )		//기울기가 더 크다면
			{
				cnt[i]++;					//현재 빌딩 cnt 업
				cnt[j]++;					//j번째 빌딩 cnt 업
				max_level = level;			//기울기 갱신
			}
		}
	}

	for ( auto elem : cnt )
		res = max(res, elem);
	cout << res << '\n';
	return 0;
}