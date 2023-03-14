#include <iostream>
#include <queue>
using namespace std;

int n, w,l;
const int maxi = 1001;
int truck[maxi];//트럭

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}
//입력
void input() {
	cin >> n >> w>>l;
	for (int i = 0; i < n; i++) cin >> truck[i];
}
//다리 건너기
void Bridge() {
	queue<int> q;//현재 다리에 있는 트럭
	int sumWeight = 0;//무게 총합
	int times = 0;//다리를 건너는 시간

	for (int i = 0; i < n;i++) {
		while (1) {
			if (q.size() == w) {//용량 초과
				sumWeight -= q.front();
				q.pop();
			}
			if (sumWeight + truck[i] > l) {//무게 초과
				q.push(0);
				times++;
			}
			else break;
		}
		times++;
		q.push(truck[i]);
		sumWeight += truck[i];
	}
	cout << times+w;//마지막 트럭
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	Bridge();//다리 건너기
	return 0;
}
