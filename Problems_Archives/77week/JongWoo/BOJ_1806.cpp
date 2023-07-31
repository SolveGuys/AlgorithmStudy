#include <iostream>

using namespace std;

int n, s;
int arr[100'000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int answer = 0x7fffffff;
    int en = 0;
    int tot = 0;

    for (int st = 0; st < n; ++st)
    {
        while ((en < n) && (tot < s))
        {
            tot += arr[en++];
        }

        // 이 부분이 없으면, st가 n - 1일 때 en - st는 1이 되어 항상 answer에 1이 들어가는 문제가 발생한다.
        if (tot >= s)
        {
            answer = min(answer, en - st);
        }

        tot -= arr[st];
    }

    if (answer == 0x7fffffff)
    {
        answer = 0;
    }

    cout << answer << '\n';
}
