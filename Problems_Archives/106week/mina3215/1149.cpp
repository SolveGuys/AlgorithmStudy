#include<iostream>
#include<algorithm>

using namespace std;

int RGB[1001][3]; // RGB �Է�
int DP[1001][3]; // DP

int N;

int main() {
	cin >> N;
	//�Է� �κ�
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> RGB[i][j];
		}
	}
	fill(&DP[0][0], &DP[0][0] + 1000 * 3, 0);
	
	// RGB �迭��ŭ ������ �迭�� ������ ĭ���� �����ϱ� ���� �ּҺ���� ��� ����
	
	// 49 50 10 : 0
	// 23 45 67 : 1
	
	// 49 50 10  " dp 0 
	// (49+min(45,67)) (50+min(23,67)) (10+min(23,45))
	// -> �� �ٿ��� ���� �� �ִ� �ּҺ���� 3��. => �̰� �߿��� ���� ���� �ϳ�
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			DP[i][j] = min(DP[i - 1][(j + 1) % 3], DP[i - 1][(j + 2) % 3]);
			DP[i][j] += RGB[i][j];
		}
	}

	int ans = min(DP[N][0], DP[N][1]);
	ans = min(ans, DP[N][2]);

	cout << ans;
}