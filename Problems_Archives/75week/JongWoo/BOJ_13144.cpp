#include <iostream>

using namespace std;

int n;
int arr[100'000];
bool isSelected[100'001]; // 1 ~ 100,000

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    long long answer = 0;
    int en = 0;

    for (int st = 0; st < n; ++st)
    {
				// 부분 수열에 중복이 없을 때까지 en을 증가시킨다.
        while ((en < n) && (!isSelected[arr[en]]))
        {
            isSelected[arr[en]] = true;
            ++en;
        }

        answer += en - st;
				
				// 부분 수열에서 제거되는 arr[st]는 false로 바꾼다.
        isSelected[arr[st]] = false;
    }

    cout << answer << '\n';
}