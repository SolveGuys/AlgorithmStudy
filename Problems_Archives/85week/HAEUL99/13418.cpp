#include <bits/stdc++.h>


using namespace std;

int v, e;
tuple<int, int, int> edge[500002];
vector<int> p(10005,-1);
int find(int x)
{
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v)
{
    u = find(u); v = find(v);
    if(u==v) return 0;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    int first = 0;
    for(int i = 0; i < e+1; i++)
    {
        int a, b, cost, input;
        cin >> a >> b >> cost;
        if(cost == 0) input = 1;
        if(cost == 1) input = 0;
        if(i == 0)
        {
            first = input;
        }
        else edge[i] = {input, a, b};
    }
 
    sort(edge+1, edge+e+1);
    int cnt = 0;
    int ans = 0;

    for(int i = 1; i < e+1; i++)
    {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        ans+=cost;
        cnt++;
        if(cnt == v-1) break;
    }


    int mn = (ans+first);

    
    sort(edge+1, edge+e+1, greater<tuple<int, int, int>>());
    fill(p.begin(),p.end(),-1);
    // for(int i = 0; i < e+1; i++) cout << get<0>(edge[i]) << ' ';
    // cout << endl;
    cnt = 0; 
    ans = 0;
    
    for(int i = 1; i < e+1; i++)
    {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        ans+=cost;
        cnt++;
        if(cnt == v-1) break;
    }

    //cout << ans;

    int mx = (ans+first);
    //cout << mx << ' ' << mn << endl;
    cout << mx * mx - mn * mn;

    
}
