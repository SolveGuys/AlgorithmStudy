#include <iostream>
#include <vector>
using namespace std;

int n;
const int maxi = 1001;
int A[maxi];//수열
int subLen[maxi];//부분 수열의 최대 길이
vector<int> ans;//정답 배열

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}
//초기화
void init() {
	for (int i = 0; i <= n; i++) subLen[i] = 1;
}
//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	init();//초기화
}

//LIS
void LIS() {
	int maxLen = 1; int maxIdx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			//더 큰값이 왔을 경우
			if (A[i] < A[j]) {
				subLen[j] = max(subLen[j], subLen[i] + 1);
				maxLen = max(maxLen, subLen[j]);
				maxIdx = j;
			}
		}
	}
	cout << maxLen<<"\n";//최대 길이 출력
	
	//LIS 원소 넣기
	int Len = maxLen;
	for (int i = maxIdx; i >= 0; i--) {
		if (Len == subLen[i]) {
			Len--;
			ans.push_back(A[i]);
		}
	}
}

//출력
void output() {
	for (int i = ans.size()-1; i>=0; i--) cout << ans[i] << " ";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	LIS();//LIS
	output();//출력
	return 0;
}
