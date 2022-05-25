#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,d;
int t[123457],a[123457],h[123457];
ll answer;

bool check(ll mid)
{
	ll hp=mid;
	ll damage=d;
	for(int i=0;i<n;i++)
	{
		if(t[i]==1)
		{
			ll div=h[i]/damage+(h[i]%damage ? 1 : 0);
			hp-=(div-1)*a[i];

//			ll monster=h[i];
//			while(1)
//			{
//				monster-=damage;
//				if(monster<=0) break;
//				hp-=a[i];
//				if(hp<=0) return false;
//			}
		}
		else
		{
			hp+=h[i];
			damage+=a[i];
			if(hp>mid) hp=mid;
		}
		if(hp <= 0) return false;
	}
	return true;
} 


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	cin>>n>>d;
	
	for(int i=0;i<n;i++)
	{
		cin>>t[i]>>a[i]>>h[i];
	}
	ll lo,mid,hi;
	lo=1;
	hi=1e18;
	
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
