#include <iostream>
#include <string>

using namespace std;

int n;
int arr[300'001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int k = 0;

    for (int i = 1; i <= n; ++i)
    {
        int num = 0;

        cin >> num;

        if (num == 1)
        {
            arr[++k] = i;
        }
    }

    string answer;
    int minCnt = 0;

    // 1. L로만 처리하는 경우
    minCnt = arr[k];
    answer.assign(minCnt, 'L');

    // 2. R로만 처리하는 경우
    if (n - arr[1] + 1 < minCnt)
    {
        minCnt = n - arr[1] + 1;
        answer.assign(minCnt, 'R');
    }

    // 3. L->R로만 처리하는 경우
    for (int i = 1; i <= k - 1; ++i)
    {
        int leftCnt = arr[i];
        int rightCnt = (n - arr[i + 1] + 1) + leftCnt;

        if (leftCnt + rightCnt < minCnt)
        {
            minCnt = leftCnt + rightCnt;
            answer.assign(leftCnt, 'L');
            answer += string(rightCnt, 'R');
        }
    }

    // 4. R->L로만 처리하는 경우
    for (int i = 1; i <= k - 1; ++i)
    {
        int rightCnt = (n - arr[i + 1] + 1);
        int leftCnt = arr[i] + rightCnt;

        if (leftCnt + rightCnt < minCnt)
        {
            minCnt = leftCnt + rightCnt;
            answer.assign(rightCnt, 'R');
            answer += string(leftCnt, 'L');
        }
    }

    cout << minCnt << '\n';

    for (char dir : answer)
    {
        cout << dir;
    }
}
