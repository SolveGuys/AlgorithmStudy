#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

//컴퓨터 클래스
class Computer {
public:
	Computer() {}

	void input();//입력
	void Spread(int x);//확산
	void output() const {cout << cnt;};//출력
private:
	static const int maxi = 101;
	int n, m;
	int cnt = 0;//감염된 바이러스 개수
	int virus[maxi][maxi];
	bool visit[maxi];//방문여부
};

//입력
void Computer::input() {
	cin >> n >> m;
	memset(virus, 0, sizeof(virus));//초기화
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;
		virus[start][end] = 1;//인접행렬
		virus[end][start] = 1;
	}
}
//바이러스 확산
void Computer::Spread(int x) {
	visit[x] = true;//방문 체크

	for (int i = 1; i <= n; i++) {//맵 탐색
		//미방문이고 연결된 컴퓨터라면
		if (visit[i] == false && virus[x][i] == 1) {
			cnt++;
			Spread(i);
		}
	}
}

int main()
{
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Computer computer;//컴퓨터 객체
	computer.input();//입력
	computer.Spread(1);//바이러스 확산
	computer.output();//출력
	return 0;
}
