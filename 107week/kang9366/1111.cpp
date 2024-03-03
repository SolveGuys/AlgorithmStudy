#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, num[50];

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	if (N == 1){
		cout << "A\n";
		return 0;
	}
	if (N == 2){
		if (num[0] == num[1])
			cout << num[1];
		else
			cout << "A\n";
		
		return 0;
	}
	else{
		int a = 0;
		if (num[1] - num[0] != 0)
			a = (num[2] - num[1]) / (num[1] - num[0]);

		int b = num[1] - num[0] * a;
		
		for (int i = 1; i < N; i++){
			if (num[i] != num[i - 1] * a + b){
				cout << "B\n";
				return 0;
			}
		}
		
		cout << num[N - 1] * a + b;
	}

	return 0;
}
