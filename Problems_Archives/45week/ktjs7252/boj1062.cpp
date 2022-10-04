#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<string> s;
bool word[27];
int answer;

void solve(int tmp,int idx)
{
	if(tmp ==k-5 )
	{
		int counting=0;
		for(int i=0;i<s.size();i++)
		{
			int sign=0;
			for(int j=0;j<s[i].size();j++)
			{
				if(!word[s[i][j]-'a'])
				{
					sign=1;
				}
			}
			if(sign==0){
				counting++;
			}
		}
		answer=max(answer,counting);
		
		return;
	}
	
	for(int i=idx;i<26;i++)
	{
		if(!word[i])
		{
			word[i]=true;
			solve(tmp+1,i+1);
			word[i]=false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>k;
	if(k<5){
		cout<<0;
		return 0;
	}
	
	for(int i=0;i<n;i++)
	{
		string a;
		cin>>a;
		s.push_back(a);
	}
	
	word['a'-'a']=true;
	word['n'-'a']=true;
	word['t'-'a']=true;
	word['i'-'a']=true;
	word['c'-'a']=true;
	
	solve(0,0);
	
	cout<<answer;
	
	return 0;
}
