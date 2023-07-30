#include <bits/stdc++.h>

using namespace std;
int arr[100001];
int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;


    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }


    int en = 0;
    int _min = INT_MAX;
    int tot = arr[0];
    
    for(int st = 0; st < n; st++)
    {
        while(en < n && tot < m)
        {
            en++;
            if(en != n) tot += arr[en];
            
        
        }
        if(en == n) break;
        _min = min(_min, en - st + 1);

        tot -= arr[st];
    }
    if(_min == INT_MAX) _min = 0;
    cout << _min; 

    
    
}
