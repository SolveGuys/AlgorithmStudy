#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1000001];
int answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		arr[x]=arr[x-1]+1;
		answer=max(answer,arr[x]);
		
	}
	
	cout<<n-answer;
	
	
	return 0;
}
