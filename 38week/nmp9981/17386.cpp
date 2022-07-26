#include <iostream>
using namespace std;
#define ll long long

//점 구조체
struct Point {
	ll X,Y;
};

Point a1,a2,b1,b2;//네 점

//입력
void input() {
	cin >> a1.X >> a1.Y >> a2.X >> a2.Y;
	cin >> b1.X >> b1.Y >> b2.X >> b2.Y;
}

//CCW, 세점의 방향성 판별
int CCW(Point a, Point b, Point c) {
	//외적 구하기
	ll Cross = (b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X);
	//방향 구하기
	if (Cross > 0) return 1;//반시계
	else if (Cross < 0)return -1;//시계
	else if (Cross == 0) return 0;//일직선
}

//교차판정
bool IsCross() {
	//각 선분에 대한 CCW값
	ll line1 = CCW(a1, a2, b1)*CCW(a1,a2,b2);
	ll line2 = CCW(a1, b1, b2)*CCW(a2,b1,b2);

	if (line1 <= 0 && line2 <= 0) return true;//둘다 방향이 반대라면 성립
	else return false;
}
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	cout<<IsCross();//교차판정
    return 0;
}
