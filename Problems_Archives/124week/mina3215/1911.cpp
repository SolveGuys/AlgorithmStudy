#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>

using namespace std;

int N, L;

vector<pair<int, int>> v;

void input() {
	int s, e;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		v.push_back({ s,e });
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> L;

	int cnt = 0;
	// ���⸷ �κ����� ������ ��ǥ
	// �����̰� 0��ǥ ���� ���۵� �� �ֱ� ������ -1 �Ҵ�.
	int prev_e = -1;
	
	input();
	// ������ ��ǥ ���� 
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		int s, e;
		tie(s, e) = v[i];
		// ���� ��ġ�� �̹� �κ����� �ִ��� Ȯ�� 
		// �κ����� ���� ������ ���� ��ġ ����
		if (s <= prev_e)
			s = prev_e + 1;
		// �� �������� �κ��� ���� Ȯ�� (�̹� ���� ���� �ִ°�?) 
		if (s >= e)
			continue;
		
		// ������ ���� Ȯ�� �� �κ��� ���� üũ. 
		int len = e - s;
		cnt += len / L;
		if (len % L) {
			cnt++;
			// ������ �κ��� ��ǥ üũ.
			prev_e = e + (L - (len % L))-1;
		}
		else
			// ������ �κ��� ��ǥ üũ.
			prev_e = e-1;
	}
	cout << cnt;
}