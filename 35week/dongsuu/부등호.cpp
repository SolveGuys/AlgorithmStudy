#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N;
bool check[10]; // 0 ~ 9������ �� �� ����� ���� true, �ƴϸ� false. 
vector <int> num;         // ���� ���� ������ ���� ���� �迭
vector <int> max_vector;  // �ִ밪
vector <int> min_vector;  // �ּҰ�
string ch;
long long max_value = 0;
long long min_value = 9999999999;

void set(int index, int loc);
bool promising(vector<int> num, int count);

int main() {
	char c;
	cin >> N;

	// check[] false�� �ʱ�ȭ
	for (int i = 0; i < 10; i++) {
		check[i] = false;
	}

	// �ε�ȣ ���� �Է� ��, string�� ��Ƶд�. 
	for (int i = 0; i < N; i++) {
		cin >> c;
		ch.push_back(c);
	}

	// start 
	set(0, 0);

	// max, min ���
	for(int i=0; i<max_vector.size(); i++)
		cout << max_vector.at(i);
	cout << endl;
	for(int j=0; j<max_vector.size(); j++)
		cout << min_vector.at(j);
}

void set(int index, int count) {
	// ���� ������ ���ڰ� promising�ϸ� ����.
	// ��, promising�ϸ� ���ڸ� ������ ���̴�. 
	if (promising(num,count)) {
		if (num.size() == ch.size() + 1) { // �ε�ȣ ��+1 ���� ���ڰ� �־����� �� ���� ��. (����)
			
			// max�� min�� ���. ù° �ڸ��� 0�� ����ؾ��ؼ� vector �̿�.
			long long value = 0;
			for (int i = 1; i <= num.size(); i++) {
				value = value + num.at(num.size() - i) * pow(10, i - 1);
			}
			if (value > max_value) {
				max_value = value;
				max_vector = num;
			}
			if (value < min_value) {
				min_value = value;
				min_vector = num;
			}
		}

		else {
			// ������ ���� true�� ǥ���صΰ�, num�� �ְ�, Ž���ϴٰ� �ȵǸ� false�� �ٲ�� num���� ������.
			// ��������� ����
			for (int i = 0; i < 10; i++) {
				if (check[i] == true)
					continue;
				num.push_back(i);
				check[i] = true;
				set(i+1,count+1);
				check[i] = false;
				num.pop_back();
			}
		}
	}
}

// promising�Լ�. 
// ���� ������ ���� promising���� �Ǻ�. 
// promising�ϸ� true, �ƴϸ� false�� return
bool promising(vector<int> num, int count) {
	if (num.size() == 0 || num.size() == 1) // ó�� ���࿡�� �ϳ������� �ƹ� ���ڰ� �͵� �����Ѵ�.
		return true;

		if (ch.at(count-2) == '<') { 
			if (num.at(count-2) < num.at(count-1)) {
				return true; // �ε�ȣ ����
			}
			else
				return false; // �ε�ȣ ����x
		}
		else if (ch.at(count-2) == '>') {
			if (num.at(count-2) > num.at(count-1)) { 
				return true; // �ε�ȣ ����
			}
			else
				return false; // �ε�ȣ ���� x
		}
}
