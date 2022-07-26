#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
bool successFriend = false;
const int maxi = 2001;
vector<int> graph[maxi];
bool visit[maxi];//방문 여부

//입력
void input() {
	cin >> n >> m;
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
}

//깊이 4인 친구관계가 존재 하는가?
void FriendSearch(int node, int depth) {
	visit[node] = true;//방문 체크
	//깊이가 4
	if (depth == 4) {
		successFriend = true;
		return;
	}

	//다음 노드
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		//미방문이면
		if (visit[next] == false) {
			FriendSearch(next, depth + 1);//다음 지점
		}
	}
	visit[node] = false;//체크 해제
}
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	for (int i = 0; i < n; i++) {
		visit[i] = true;
		FriendSearch(i,0);//시작 노드, 깊이
		visit[i] = false;
		//해당 친구관계 존재
		if (successFriend == true) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
    return 0;
}
