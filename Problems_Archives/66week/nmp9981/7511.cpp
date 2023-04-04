#include <iostream>
using namespace std;

int n,k,a,b,m;
const int maxi = 1000001;
int root[maxi];//i번 노드의 루트노드

//초기화
void init() {
    cin >> n;
    for (int i = 0; i < n; i++) root[i] = i;
}
//각 노드의 루트노드
int Find(int x) {
    if (root[x] == x) return x;
    return root[x] = Find(root[x]);
}
//연결
void Connect(int a, int b) {
    int rootA = Find(a);
    int rootB = Find(b);
    if (rootA < rootB) root[rootB] = rootA;
    else root[rootA] = rootB;
}
//입력
void input() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        Connect(a, b);//연결
    }
}
//질문
void Question(int testNum) {
    cin >> m;
    cout << "Scenario " << testNum<<":\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (Find(u) != Find(v)) cout << 0 << "\n";
        else cout << 1 << "\n";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for (int i = 1; i <= t;i++) {
        init();//초기화
        input();//입력 및 연결
        Question(i);//칠문
    }
    return 0;
}
