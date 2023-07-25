#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[1000002];
int res[1000002];
int main()
{           
    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ok = k;
    int en = 0;
    
    if(arr[0] % 2 != 0)
    {
        k--;
    }
    
    for(int st = 0; st < n; st++)
    {
        while(en < n - 1)
        {
            en++;
            if(arr[en] % 2 != 0)
            {
                if(k > 0)
                    k--;
                else
                {
                    en--;
                    break;
                }
            }
        }
        res[st] = en - st - (ok - k) + 1;

        if(arr[st] % 2 != 0)
        {
            k++;
        }
        
    }

    cout << *max_element(res, res+n);
}
