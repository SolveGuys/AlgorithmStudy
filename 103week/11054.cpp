/**********************************************************
2024-02-03
https://github.com/keastmin
����/11054/���� �� ������� �κ� ����
���̵�: ���4
����: DP(Dynamic-Programming)
**********************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	// C���� ����� ���� ����ȭ�� �����Ͽ� ���� �ӵ��� Ȯ��
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	// ������ ���� �Է¹ޱ�
	int N;
	cin >> N;

	vector<int> arr(N, 0);		// ������ �����ϴ� �迭
	vector<int> lis(N, 0);		// ���� �� �κ� ���� ���� ���� ����
	vector<int> rev_lis(N, 0);	// �������� �� �κ� ���� ���� ����

	// ������ �迭�� ����
	for (int i = 0; i < N; i++) {
		int m;
		cin >> m;
		arr[i] = m;
	}

	// DP�� �̿��Ͽ� ���� �� �κ� ���� ���� ����
	for (int i = 0; i < N; i++) {
		lis[i] = 1;
		for (int j = 0; j < i; j++) {

			// ���� ������ ũ�Ⱑ �����鼭 ���̰� �� �κ� ���� ���� ����
			if (arr[i] > arr[j]) {
				lis[i] = max(lis[i], lis[j] + 1);
			}
		}
	}

	// ���� ������ �������� ����
	for (int i = N - 1; i >= 0; i--) {
		rev_lis[i] = 1;
		for (int j = N - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				rev_lis[i] = max(rev_lis[i], rev_lis[j] + 1);
			}
		}
	}

	// ���̰� �� �κ� ���� ������ �� ������ ���̿��� -1�� ���� �� ���� �� ���� ã��
	// -1�� ���� �ڽ��� ����Ű�� ���� �ߺ��Ǳ� ����
	int res = 0;
	for (int i = 0; i < N; i++) {
		res = max(res, (lis[i] + rev_lis[i]) - 1);
	}

	cout << res << '\n';

	return 0;
}