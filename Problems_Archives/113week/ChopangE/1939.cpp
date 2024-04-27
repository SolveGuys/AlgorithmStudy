#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Find(vector<int> &s, int x) {						//�и����� Find
	if ( s[x] == -1 )return x;							//s[x] == -1�̸� x�� root�� �ش��Ѵ�.
	return s[x] = Find(s, s[x]);						//Tree�� depth�� �ּ�ȭ�Ѵ�.
}

void Union(vector<int> &s, int x, int y) {				//�и����� Union
	int s_x = Find(s, x);								//x�� rootã��
	int s_y = Find(s, y);								//y�� rootã��
	if ( s_x == s_y )return;							//root�� ���� ���
	if ( s_x < s_y )s[s_y] = s_x;						//root�� �ٸ� ��� Union ���� : ���� ���� ���� root�� �ȴ�.
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
	//�߷����� ���� ������������ ����
	sort(edge.begin(), edge.end(), cmp);
	for ( int i = 0; i < M; i++ ) {
		iii &tmp = edge[i];
		//�� ����(tmp.first.first (=A) , tmp.first.second (=B))�� Union�Ѵ�.
		Union(s , tmp.first.first, tmp.first.second);

		//���� Union�� ���� �������� ������ ����Ǿ��ٸ� 
		//������ tmp.second�� �������� ������ ������ �ٸ� �� �߷������� �ּ��̸�
		//�� �̻��� �ٸ��� ���ʿ��ϸ�(�ٸ��� �߰��Ǹ� �߷����Ѹ� �����.) 
		//�̴� �� tmp.secondr�� �ű� �� �ִ� ��ǰ �߷��� �ִ밪�� �ȴ�.
		if ( Find(s, start) == Find(s, dest) ) {
			cout << tmp.second << endl;
			break;
		}
	}

	return 0;
}