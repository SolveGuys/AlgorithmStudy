#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

// �׸��� | ����
// ���� �ð� : 2��

/* 1. ����
*  WHY? �׸��� or ���� Ž��
*  �ܾ�� <= 10, ���ĺ� <= 9
*  �־��� ���ĺ��� ������ ǥ���Ѵ� ������, 
*  9! => 7�ʸ�? 2�� ���� �� ��? => next_permutation O(N*N!) => 7�鸸
*  
*  ������ �ѵ�, stoi, to_string => �̷��� �����ϸ� �ð��� �ʰ���. 
*  �ٸ� ���� ���������� �� �𸣰���
*/

/*
* 2. �׸��� (��Ī...)
* ABCDE, EEE
* A : 10000
* B : 1000
* C : 100
* D : 10
* E : 112
* 
* �����ؾ� �� �� : 
* 1. ���� ���ڴ�� ��ȣ�� �ο��Ѵ�. 
* 2. ���� �ڸ��� �ִ� �� ��, �Ʒ� �ڸ� ���ڰ� ���� ��찡 �� ū ����.
*/



int N;
int _max = 0;
vector<string> words;
int a[26];

void input() {
	cin >> N;
	fill(a, a + 26, 0);
	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		words.push_back(word);
	}
}


int main() {
	// input : ���ڿ��� words�� ��´�
	input();

	// �ܾ ���ư��鼭 �ڸ����� �´� ���ڸ� �迭�� ����ش�
	for(int i=0; i<words.size(); i++){
		int v = 1;
		for (int j = words[i].size() - 1; j >= 0; j--) {
			a[words[i][j] - 'A'] += v;
			v *= 10;
		}
	}

	// ���ڿ� ������� ���ڸ��� �������� 9 -> 1���� ����. 
	// sort.
	sort(a, a + 26, greater<int>());

	int answer = 0;
	int cnt = 9;
	for (auto i : a) {
		answer += (cnt--) * i;
	}

	cout << answer;

	return 0;
}