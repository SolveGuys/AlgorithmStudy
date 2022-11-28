#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> lines;

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n;
    //초기화
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        lines.push_back({ a,b });
    }
    sort(lines.begin(), lines.end());//정렬
}
//선 그리기
void draw() {
    int total = 0;//총 길이
    int st = lines[0].first;//시작 지점
    int end = lines[0].second;//끝 지점
    for (int i = 1; i < n; i++) {
        if (lines[i].first > end) {
            total += (end - st);//길이 누적
            st = lines[i].first;//시작 지점 갱신
            end = lines[i].second;//끝 지점 갱신
        }
        else end = max(end,lines[i].second);//더 끝값으로 끝 지점 갱신
    }
    total += (end - st);//길이 누적
    cout << total;//출력
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
    input();//입력
    draw();//그리기
	return 0;
}
