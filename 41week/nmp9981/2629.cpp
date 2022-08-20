#include <iostream>
#include <cstring>
using namespace std;

const int maxi = 31;
const int maxiWeight = 40001;
int n,m;
int sumWeight = 0;//무게의 총합
int weight[maxi];//각 추의 무게
bool totalGram[maxi][maxiWeight];//i번까지 사용했을때 jg이 존재하는가?

//입력
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> weight[i];
		sumWeight += weight[i];//무게 총합 구하기
	};
	memset(totalGram, false, sizeof(totalGram));
}

//양팔저울
void panBalance() {
	//1번
	totalGram[1][0] = true;
	totalGram[1][weight[1]] = true;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sumWeight; j++) {
			//이전상태가 가능한 조합이라면
			if (totalGram[i - 1][j]) {
				if (j + weight[i] <= sumWeight) totalGram[i][j + weight[i]] = true;//추가
				totalGram[i][abs(j - weight[i])] = true;//빼기
				totalGram[i][j] = true;//이전과 그대로
			}
		}
	}
}
//질문
void Question() {
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (totalGram[n][x]) cout << "Y ";
		else cout << "N ";
	}
}
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	panBalance();//양팔저울
	Question();//질문
    return 0;
}
