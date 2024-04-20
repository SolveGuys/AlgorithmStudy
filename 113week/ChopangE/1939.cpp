#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Find(vector<int> &s, int x) {						//분리집합 Find
	if ( s[x] == -1 )return x;							//s[x] == -1이면 x는 root에 해당한다.
	return s[x] = Find(s, s[x]);						//Tree의 depth를 최소화한다.
}

void Union(vector<int> &s, int x, int y) {				//분리집합 Union
	int s_x = Find(s, x);								//x의 root찾기
	int s_y = Find(s, y);								//y의 root찾기
	if ( s_x == s_y )return;							//root가 같은 경우
	if ( s_x < s_y )s[s_y] = s_x;						//root가 다른 경우 Union 실행 : 값이 작은 쪽이 root가 된다.
	else s[s_x] = s_y;
}

typedef pair<int, int> ii;

typedef pair<ii, int> iii;

bool cmp(iii &a, iii &b) {
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int N,M,start,dest;
	cin >> N >> M;
	vector<int> s(N + 1,-1);
	vector<iii> edge(M);
	for ( int i = 0; i < M; i++ ) {
		int A, B, C;
		cin >> A >> B >> C;
		edge[i].first.first = A;
		edge[i].first.second = B;
		edge[i].second = C;

	}
	cin >> start >> dest;
	//중량제한 기준 내림차순으로 정렬
	sort(edge.begin(), edge.end(), cmp);
	for ( int i = 0; i < M; i++ ) {
		iii &tmp = edge[i];
		//두 지역(tmp.first.first (=A) , tmp.first.second (=B))을 Union한다.
		Union(s , tmp.first.first, tmp.first.second);

		//위의 Union을 통해 시작점과 끝점이 연결되었다면 
		//현재의 tmp.second가 시작점과 끝점을 연결한 다리 중 중량제한이 최소이며
		//이 이상의 다리는 불필요하며(다리가 추가되면 중량제한만 낮춘다.) 
		//이는 곧 tmp.secondr가 옮길 수 있는 물품 중량의 최대값이 된다.
		if ( Find(s, start) == Find(s, dest) ) {
			cout << tmp.second << endl;
			break;
		}
	}

	return 0;
}