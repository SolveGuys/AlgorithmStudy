#include <bits/stdc++.h>

using namespace std;

int n,len;
int arr[40001];
int tmp[40001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie();
	
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
