#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[100001];
int mid,lo,hi;
int sum;
int answer;

bool check(int mid)
{
	int num=0;
	int tmp=0;
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]>mid) return false;
	} 
	
	for(int i=0;i<n;i++)
	{
		if(tmp+arr[i]>mid)
		{
			tmp=0;
			num++;
		}
		tmp+=arr[i];
	}
	
	 num++;
	
	
	
	return num<=m;
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	
	lo=0;
	hi=sum;
	
	while(lo<=hi)
	{
		mid=(lo+hi)/2;
		if(check(mid))
		{
			answer=mid;
			hi=mid-1;
		}
		else
		{
			lo=mid+1;
		}
	}
	
	cout<<answer;
	
	return 0;
}
