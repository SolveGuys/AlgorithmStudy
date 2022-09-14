#include <iostream>
#include <vector>
using namespace std;

int n;
const int maxi = 40001;
int port[maxi];//포트 길이
vector<int> Lis;//LIS길이, 처음부터 오름차순

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> port[i];
}

//연결
void Connect() {
	for (int i = 0; i < n; i++) {
		//빈 벡터거나 가장 큰 원소볻 더 큰값이 왔을 경우
		if (Lis.size()==0 || Lis[Lis.size() - 1] < port[i]) Lis.push_back(port[i]);
		else {
			int pos = lower_bound(Lis.begin(), Lis.end(), port[i]) - Lis.begin();//iterator형을 반환하므로 Lis.begin()을 빼준다.
			Lis[pos] = port[i];//갱신
		}
	}
	cout << Lis.size();//Lis길이
}
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	Connect();//연결
    return 0;
}
