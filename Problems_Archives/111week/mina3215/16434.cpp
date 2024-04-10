#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>

using namespace std;

int N;
long long ATK;
long long Max_HP;
vector<long long> DMG(130000);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> ATK;
	DMG[0] = 0;
	for (int i = 1; i <= N; i++) {
		int t, a, h;
		cin >> t >> a >> h;
		// t == 1 : ����
		long long dmg = 0;
		if (t % 2) {
			// ��簡 ���͸� óġ�ϴµ� �ʿ��� ���� ��
			long long num = ceil(double(h) / double(ATK));
			// ��簡 �´� ������
			dmg = (num - 1) * a;
			// ���������� �������� ������ �����Ѵ�.
			DMG[i] = DMG[i - 1] + dmg;
			// ���� ���� �ǰ� ���̴� ��ŭ�� ��� ����
			Max_HP = max(DMG[i], Max_HP);
		}
		else {
			dmg = DMG[i - 1] - h;
			ATK += a;
			DMG[i] = dmg >= 0 ? dmg : 0;
		}
	}
	// �ּ� �ʿ䷮ 1�� ������.
	cout << Max_HP + 1;
}