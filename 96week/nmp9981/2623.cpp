#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
const int maxi = 1001;
vector<int> graph[maxi];//그래프
int getNodes[maxi];//진입 노드 개수
vector<int> result;//결과

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}

//입력
void input() {
    cin >>n>>m;
    for (int i = 1; i <= m; i++) {
        int c; cin >> c;
        vector<int> sing;
        for (int j = 0; j < c; j++) {
            int x; cin >> x;
            sing.push_back(x);
        }
        for (int j = 0; j < sing.size() - 1; j++) {
            graph[sing[j]].push_back(sing[j + 1]);
            getNodes[sing[j + 1]]+=1;
        }
    }
}
//위상정렬
void ACM() {
    queue<int> q;
    //진입노드 0인것 모두 큐에 넣기
    for (int i = 1; i <= n; i++) {
        if (getNodes[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        result.push_back(node);//결과 넣기

        for (int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            getNodes[next]-=1;

            if (getNodes[next] == 0) q.push(next);//새로운 지점
        }
    }
    //결과 출력
    if (result.size() == n) {
        for (int i = 0; i < result.size(); i++) cout << result[i] << "\n";
    }else cout << 0;//순위 측정 불가
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    ACM();//위상정렬
    return 0;
}
