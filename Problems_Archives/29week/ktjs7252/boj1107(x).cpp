#include <bits/stdc++.h>

using namespace std;

int n;
int m;
char num[11];
int answer;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		cin>>num[i];
	}
	if(n==100) {
		cout<<"0";
		return 0;
	}
	
	answer=abs(100-n);
	
	string answer1;
	string answer2;
	int idx=0;
	
	
	while(1)
	{
		int sign1=0;
		int sign2=0;
		int small=n-idx;
		int big=n+idx;
		
		answer1=std::to_string(small);
		answer2=std::to_string(big);
		
		for(int i=0;i<m;i++)
		{
			if(answer1.find(num[i])!=string::npos)
			{
				sign1=1;
				break;
			}
		}
		
		if(sign1==0)
		{
			int k=abs(n-stoi(answer1))+answer1.size();
			answer=min(k,answer);
			cout<<answer;
		//	cout<<min(answer,abs(n-stoi(answer1))+answer1.size());
			return 0; 
		}
		
		for(int i=0;i<m;i++)
		{
			if(answer2.find(num[i])!=string::npos)
			{
				sign2=1;
				break;
			}
		}
		
		if(sign2==0)
		{
			int k=abs(n-stoi(answer2))+answer2.size();
			answer=min(k,answer);
			cout<<answer;
		//	cout<<min(answer,abs(n-stoi(answer2))+answer2.size());
			return 0; 
		}
		idx++;
	}
	

	
	return 0;
}

//	for(int i=0;i<answer1.size();i++) //작은놈 
//		{
//			for(int j=0;j<10;j++)
//			{
//				if(num[answer1[i]-'0']==1)
//				{
//					sign1=1;
//					break;
//				}
//			}
//			if(sign1==1) break;
//		}
