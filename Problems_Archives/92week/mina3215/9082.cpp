#include<bits/stdc++.h>

using namespace std;

int T;
int n; // ���� ����
string number;
string bomb;
int check[100];

void checkBomb(int num) {
	

	// for�� �� ������
	
}

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		fill(check, check + 100, 0);
		cin >> n; // ������ ũ��
		cin >> number; // ���� ��Ʈ ����
		cin >> bomb; 

		if(bomb[0] == '*') check[0] = 1;
		if (number[0] == '2') {
			check[0] = 1; check[1] = 1;
		}
		if (bomb[n - 1] == '*') check[n - 1] = 1;
		if (number[n - 1] == '2') {
			check[n - 1] = 1;
			check[n - 2] = 1;
		}

		for (int i = 1; i < n-1; i++) {
			if (bomb[i] == '*') {
				check[i] = 1;
			}
			if (number[i] == '3') {
				check[i - 1] = 1; check[i] = 1; check[i + 1] = 1;
			}
		}
		checkBomb(0);
	}
}

// 1�� : ��Ʈ��ŷ 
// 2�� : �ȵǸ� DP�� �׸���