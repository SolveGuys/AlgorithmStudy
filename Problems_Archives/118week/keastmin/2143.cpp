#include <iostream>
#include <vector>
#include <algorithm>

int T, N, M;
std::vector<int> A;
std::vector<int> B;

std::vector<int> A_sum;
std::vector<int> B_sum;

int main() {
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	std::cin >> T >> N; A.resize(N);
	for (int i = 0; i < N; i++) std::cin >> A[i];
	std::cin >> M; B.resize(M);
	for (int i = 0; i < M; i++) std::cin >> B[i];

	for (int length = 1; length <= A.size(); length++) {
		for (int s = 0; s <= A.size() - length; s++) {
			int e = s + length - 1;
			int sum = 0;
			for (int iter = s; iter <= e; iter++) {
				sum += A[iter];
			}
			A_sum.push_back(sum);
		}
	}

	for (int length = 1; length <= B.size(); length++) {
		for (int s = 0; s <= B.size() - length; s++) {
			int e = s + length - 1;
			int sum = 0;
			for (int iter = s; iter <= e; iter++) {
				sum += B[iter];
			}
			B_sum.push_back(sum);
		}
	}

	sort(A_sum.begin(), A_sum.end());
	sort(B_sum.begin(), B_sum.end());

	int aS = 0;
	int bS = B_sum.size() - 1;
	int64_t res = 0;

	while (aS < A_sum.size() && bS >= 0) {
		int currSum = A_sum[aS] + B_sum[bS];
		if (currSum > T) {
			bS--;
		}
		else if (currSum < T) {
			aS++;
		}
		else {
			// 합이 맞아 떨어질 때, A_sum과 B_sum 벡터에서 같은 수들은 스킵해도 되므로
			// 여기서 같은 수들에 대해 넘기며 그 개수를 확인해줌
			// 이 과정을 통해 합이 달라지는 구간까지 aS, bS를 넘겨줄 수 있음

			int tmpA = A_sum[aS];
			int tmpB = B_sum[bS];
			int64_t cntA = 0;
			int64_t cntB = 0;

			while (aS < A_sum.size() && tmpA == A_sum[aS]) {
				aS++;
				cntA++;
			}
			while (bS >= 0 && tmpB == B_sum[bS]) {
				bS--;
				cntB++;
			}

			/****************************************************************
			만약 cntA가 3, cntB가 2라고 할 때, 만약 T가 6이고 이 T를 만족하기 위해
			A_sum[aS]가 4, B_sum[bS]기 2였다면 A_sum에서 4라는 누적합이 나올 수 있는
			부 배열이 3가지가 연속으로 있고, B_sum에서 2라는 누적합이 나올 수 있는
			부 배열이 2가지가 연속으로 있다는 말이므로 
			A_sum -> 4 4 4
			B_sum -> 2 2
			위와 같이 있다면 저 두 배열의 조합의 수는 3 * 2로 6가지이다.
			*****************************************************************/
			res += cntA * cntB;
		}
	}

	std::cout << res << '\n';
	
	return 0;
}
