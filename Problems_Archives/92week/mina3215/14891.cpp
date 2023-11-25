#include<bits/stdc++.h>

using namespace std;

string gear[5];
int number[5] = {0,0,0,0,0}; // 12�� ������ ��ϵ��� ���� �迭
int T;

void turn(int n, int d) {
	int turns[5] = { 0,0,0,0,0 }; // ������ ���� ������ ���� �迭
	turns[n] = d; // �ϴ� n��° ��ϸ� d�������� ������.
	
	int right_gear = n; 
	int left_gear = n;
	
	// n��° ����� ���� ��ϵ��� ������ ���Ѵ�.
	while (right_gear < 4) {
		int connect = (number[right_gear] + 2) % 8; // ���� ���� �����ʿ� ���ϴ� ���
		int connect_r = (number[right_gear + 1] + 6) % 8;  // (number[n+1] -2 + 8)%8 ���� ������ ���� ��Ͽ� �����ִ� ���
		//�ٸ���
		if (gear[right_gear][connect] != gear[right_gear + 1][connect_r]) {
			turns[right_gear + 1] = turns[right_gear]*-1;
			right_gear++;
		}
		// ������ �� �̻��� ȸ���� ���� => �� ������ ��Ϲ����鵵 ���� �ʴ´�..
		else break;
	}
	
	//���� ���� ������� ���� ��ϱ��� �����Ѵ�. 
	while (left_gear > 1) {
		int connect = (number[left_gear] + 6) % 8;
		int connect_l = (number[left_gear - 1] + 2) % 8;
		if (gear[left_gear][connect] != gear[left_gear - 1][connect_l]) {
			turns[left_gear - 1] = turns[left_gear] * -1;
			left_gear--;
		}
		else break;
	}

	// ��ϵ��� ������.
	for (int i = 0;i < 5;i++) {
		number[i] = (number[i] + turns[i] + 8) % 8;
	}
}

int main() {
	//���Ǹ� ���� 0�� ���Ƿ� �־���
	gear[0]="00000000";
	int n, d;
	for (int i = 1; i <= 4; i++) cin >> gear[i];
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n >> d; // n ��° ��ϸ� d��������
		turn(n, d*-1);
	}
	int ans = 0;
	int score = 1;
	
	// 12�� ������ ��ϰ� 1�϶� score�� �߰��ϴµ� 2�� ������ �þ.
	for (int i = 1; i < 5; i++) {
		if (gear[i][number[i]] == '1') {
			ans += score;
		}
		score *= 2;
	}
	cout << ans;

	return 0;
}
