#include <bits/stdc++.h>

using namespace std;

int t,n;
int a,b;


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	cin>>t;
	
	for(int k=0;k<t;k++)
	{
		cin>>n;
		vector<pair<int,int>> v;
		int answer=0;
		
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			v.push_back({a,b});
		}

		sort(v.begin(),v.end());
		

		int tmp=v[0].second;
		
		for(int i=0;i<n;i++)
		{
			if(v[i].second<=tmp)
			{
				answer++;
				tmp=v[i].second;
			}
		}

		cout<<answer<<"\n";
	}
	
	
	
	
	return 0;
 } 
