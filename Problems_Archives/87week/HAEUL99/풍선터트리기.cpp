#include <bits/stdc++.h>

using namespace std;
int l[1000002];
int r[1000002];
int solution(vector<int> a) {
    int answer = 0;
    int n = a.size();
    
    l[0] = a[0];
    int mn = l[0];
    for(int i = 0; i < n; i++)
    {
        if(mn > a[i]) mn = a[i];
        l[i] = mn;
    }
    
    r[n-1] = a[n-1];
    mn = r[n-1];
    for(int i = n-1; i >= 0; i--)
    {
        if(mn > a[i]) mn = a[i];
        r[i] = mn;
    }
    

    for(int i = 0; i < n; i++)
    {
        //cout << l[i] << ' ';
        if(a[i] <= l[i] || a[i] <= r[i]) answer++;
    }

    
    
    return answer;
}
