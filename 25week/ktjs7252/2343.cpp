#include <bits/stdc++.h>

using namespace std;

int n,c;
int arr[1000001];
int mid,hi,lo,answer;

int check(int mid)
{
	int tmp=0;
	int num=0;
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]>mid) return false;
	}
	
	for(int i=0;i<n;i++)
	{
		if(tmp+arr[i]>mid)
		{
			num++;
			tmp=0;
		}
		tmp+=arr[i];
	}
	num++;
	
	
	return num<=c;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>c;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		hi+=arr[i];
	}
	lo=1;
	
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
	
	printf("%d",answer);
	
	
	return 0;
}
