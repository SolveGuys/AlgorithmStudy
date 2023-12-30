#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n;
const int maxi = 101;
int A[maxi];//두번째 수열
bool visit[maxi];//방문 여부
vector<int> answer;//정답

//입력
void Input() {
    cin >>n;
    for (int i = 1; i <= n; i++) cin >> A[i];
}
//dfs
void DFS(int cur, int start) {//현재노드, 시작노드
    if (!visit[cur]) {//미방문
        visit[cur] = true;
        DFS(A[cur], start);//다음 지점
    }
    else if (cur == start) {//사이클 형성
        answer.push_back(start);
        return;
    }
}
//사이클 찾기
void FindCycle() {
    for (int i = 1; i <= n; i++) {
        memset(visit, false, sizeof(visit));//초기화
        DFS(i, i);//탐색
    }
}
//출력
void Output() {
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++) cout << answer[i] << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Input();//입력
    FindCycle();//사이클 찾기
    Output();//출력
    return 0;
}
