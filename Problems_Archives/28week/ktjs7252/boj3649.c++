#include <bits/stdc++.h>

using namespace std;

int x,n;
vector<int> v;
int a;
int here;

int main()
{
	while(1)
	{
		cin>>x>>n;
		if(cin.eof()) break;
		v.clear();
		
		for(int i=0;i<n;i++)
		{
			cin>>a;
			v.push_back(a);
		}
		
		sort(v.begin(),v.end());
		
		here=x*10000000;
		int left=0;
		int right=v.size()-1;
		int sign=0;
		
		while(left<right)
		{
			if(v[left]+v[right]==here)
			{
				printf("yes %d %d\n",v[left],v[right]);
				sign=1;
				break;
			}
			else if(v[left]+v[right]>here)
			{
				right--;
			}
			else
			{
				left++;
			}
		}
		if(sign==0)
		{
			cout<<"danger\n"; 
		}
		
	}
	
	
	
	return 0;
 } 
 
  
