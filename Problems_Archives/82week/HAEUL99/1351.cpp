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
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <sstream>
//#include <bits/stdc++.h>
using namespace std;
long long n, p, q;

unordered_map<long long, long long> _m;

long long func(long long cur)
{
    if(cur == 0)
    {
        return 1;
    }

    if(_m.find(cur) == _m.end())
    {
        long long p1 = func(cur/p);
        long long q1 = func(cur/q);
        _m[cur] = p1 + q1;
        return p1 + q1;

    }
    else
    {
        return _m[cur];
    }
    

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> p >> q;

    long long val = func(n);
    
    cout << val;
}
