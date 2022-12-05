#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
const int maxi = 1001;
ll cost[maxi][maxi];//비용
int root[maxi];//각 노드의 루트노드
vector<pair<ll, pair<int, int>>> flow;//플로우

//루트노드
int find(int r) {
    if (root[r] == r) return r;
    return root[r] = find(root[r]);
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> cost[i][j];
    }
    if (n == 1) return;//n=1일때 예외처리
    for (int i = 0; i < n; i++) root[i] = i;//루트 노드 초기화
    //플로우 설치
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j) continue;
            flow.push_back({ cost[i][j],{i,j} });
        }
    }
    sort(flow.begin(), flow.end());//비용 순 배치
}
//설치
void Install() {
    int node = 0; ll total = 0;
    for (int i = 0; i < flow.size(); i++) {
        ll fee = flow[i].first;
        int x = flow[i].second.first;
        int y = flow[i].second.second;

        //루트 노드 검사
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) {
            root[rx] = ry;//그래프 합치기
            node++;
            total += fee;
        }
        //검사 완료
        if (node == n - 1) break;
    }
    cout << total;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
    input();//입력
    Install();//설치
	return 0;
}
