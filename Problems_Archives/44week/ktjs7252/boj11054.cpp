#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1001];
int big[1001];
int small[1001];
int answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
//	memset(big,1,sizeof(big));
//	memset(small,1,sizeof(small));
	fill(big,big+1001,1);
	fill(small,small+1001,1);
	
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j])
			{
				big[i]=max(big[i],big[j]+1);
			}
		}
	}
	
	for(int i=n-1;i>=0;i--)
	{
		for(int j=n-1;j>i;j--)
		{
			if(arr[i]>arr[j])
			{
				small[i]=max(small[i],small[j]+1);
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		//cout<<big[i]<<" "<<small[i]<<"\n";
		answer=max(answer,big[i]+small[i]-1);
	}
	
	cout<<answer;
	
	
	
	return 0;
}
