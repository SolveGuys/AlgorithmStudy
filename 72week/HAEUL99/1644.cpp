#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <set>
#include <cstring>
#include <string>
#include <stdio.h>
#include <limits.h>


using namespace std;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    if(n == 1)
    {   
        cout << '0';
        return 0;
    }
    vector<bool> v(n+1, 1); 


    for(int i = 2; i * i <= n; i++)
    {
        if(v[i] == 0 ) continue;
        for(int j = i+i; j <= n; j+= i)
        {
            v[j] = 0;
        }
    }

    vector<int> prime;
    for(int i = 2; i <= n; i++)
    {
        if(v[i])
        {
            prime.push_back(i);

        }
    }

    int en = 0;
    int arrsize = prime.size(); 
    int total = prime[0];
    int cnt = 0;
    for(int st = 0; st < arrsize; st++)
    {
        while(en < arrsize && total < n)
        {
            en++;
            if(en != arrsize) total += prime[en];
        }

        if(total == n)
        {
            cnt += 1;
        }
        if(en == arrsize) break;
        total -= prime[st];

    }


    cout << cnt;
    
    
}
