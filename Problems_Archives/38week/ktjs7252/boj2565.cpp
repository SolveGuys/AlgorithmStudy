#include <bits/stdc++.h>
using namespace std;

int n, len, num;
pair<int, int> a[101];
int lis[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>n;
	for (int i = 0; i < n; i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        auto it = lower_bound(lis, lis + len, a[i].second);
        if(!(*it))len++;
        *it = a[i].second;
    }
    cout<<n-len;

	return 0;
}


