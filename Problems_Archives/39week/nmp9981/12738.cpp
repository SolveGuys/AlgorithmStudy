#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
const int maxi = 1000001;
int A[maxi];//수열
vector<int> Lis;//LIS벡터, 처음부터 오름차순으로 정렬

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
}

//LIS
void LIS() {
	for (int i = 0; i < n; i++) {//기준점
		//가장 큰수가 오면
		if (Lis.size() == 0 || A[i] > Lis[Lis.size() - 1]) Lis.push_back(A[i]);
		else {
			//lower_bound() : 주어진 범위(Start ~ End) 에서, Key값 이상인 첫 번째 원소의 위치를 반환
			int pos = lower_bound(Lis.begin(), Lis.end(), A[i]) - Lis.begin();//반환형이 iterator
			Lis[pos] = A[i];//값을 바꿔준다.
		}
	}
	//벡터의 길이가 답
	cout << Lis.size();
}

int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	LIS();//최대 증가 수열
    return 0;
}
