#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 100000

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    int a[MAX];

    cin >> n >> s;
    for(int i=0; i<n; i++)
        cin >> a[i];

    int st = 0;
    int en = 0;
    int sum = a[0]; // 합
    int res = 0x7fffffff; // 결과
    int len = 1; // 길이
    bool flag = false; // 가능 여부

    while(st<=en && st<n && en<n)
    {
        if(sum<s)
        {
            en += 1;
            sum += a[en];
            len++; // 길이 증가
        }
        else // sum >= s일 때
        {
            flag = true;
            res = min(res, len);
            sum -= a[st];
            st++;
            len--;
        }
    }

    if(!flag)
        cout << 0;
    else
        cout << res;
}
