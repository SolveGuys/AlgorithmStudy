#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int,int>> Line;//선

//입력
void input() {
    cin >> n;
    for (int k = 0; k < n; k++) {
        int s,e;
        cin >> s>>e;
        Line.push_back({ s,e });
    }
    sort(Line.begin(), Line.end());//정렬
}
//그리기
void Draw() {
    int start = Line[0].first;
    int end = Line[0].second;
    int len = 0;//총 길이
    for (int i = 1; i < n; i++) {
        int left = Line[i].first;
        int right = Line[i].second;
        
        if (left <= end && right > end) end = right;//이어서 그림
        else if(left>end){//끊어짐
            len += (end - start);
            start = left;
            end = right;
        }
    }
    cout << len + (end - start);//최종 길이
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Draw();//그리기
    return 0;
}
