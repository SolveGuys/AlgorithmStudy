#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
const int maxi = 200001;
int cost[maxi];//비용
int Synergy[maxi][2];//i가 멘토인가?
int maxSynergy = 0;//최대 시너지
vector<int> graph[maxi];//그래프

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    memset(Synergy, -1, sizeof(Synergy));//초기화

    cin >> n;
    for (int i = 2; i <= n; i++) {
        int mento; cin >> mento;
        graph[mento].push_back(i);
    }
    for (int i = 1; i <= n; i++) cin >> cost[i];
}
//멘토링 (트리 DP사용)
int Mentoring(int node, int state) {
    //이미 값이 있다.
    if (Synergy[node][state] >= 0) return Synergy[node][state];

    int sum = 0;//시너지 합
    //멘토 X, stage = 1인데 멘토를 안할 수 있다.
    for (int i = 0; i < graph[node].size(); i++) {
        int nextNode = graph[node][i];
        sum += max(Mentoring(nextNode, 0), Mentoring(nextNode, 1));
    }

    if (state == 1) {//멘토
        int mentoSynergy = sum;//멘토를 안하는 경우
        //하위 노드 탐색
        for (int i = 0; i < graph[node].size(); i++) {
            int nextNode = graph[node][i];
            int current = cost[node] * cost[nextNode];//현재 시너지
            sum = max(sum, current+Mentoring(nextNode,0)+mentoSynergy-max(Mentoring(nextNode,0), Mentoring(nextNode,1)));
        }
    }
   
    return Synergy[node][state] = sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    maxSynergy = max(Mentoring(1, 0), Mentoring(1, 1));
    cout << maxSynergy;//출력
    return 0;
}
