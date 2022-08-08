#include <bits/stdc++.h>

using namespace std;

int arr[10000001];
int tmp[1000001];
int n,len;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	for(int i=0;i<n;i++)
	{
		auto it=lower_bound(tmp,tmp+len,arr[i]);
		if(!(*it)) len++;
		*it=arr[i];
	}
	
	cout<<len;	
	
	
	
	return 0;
}
