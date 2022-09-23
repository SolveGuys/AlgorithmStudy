#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

string arr;
int visited[27];
string tmp;
vector<string> k;
int sign;

void solve(vector<string> &orders,int start,int end,int idx)
{
    if(start==end)
    {
        int counting=0;
        for(int i=0;i<orders.size();i++)
        {
            int x=0;
            for(int j=0;j<tmp.size();j++)
            {
                if(orders[i].find(tmp[j])!=string::npos)
                {
                    x++;
                }
            }
            if(x==tmp.size()){
                counting++;
            }
        }
        if(counting<=1) return;
        if(counting>sign)
        {
            k.clear();
            k.push_back(tmp);
            sign=counting;
        }
        if(counting==sign)
        {
            k.push_back(tmp);
        }
        
        return;
    }
    for(int i=idx;i<arr.size();i++)
    {
        if(visited[arr[i]-'A']==0)
        {
            visited[arr[i]-'A']=1;
            tmp+=arr[i];
            solve(orders,start+1,end,i+1);
            visited[arr[i]-'A']=0;
            tmp.pop_back();
        }
    }
}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i=0;i<orders.size();i++)
    {
        for(int j=0;j<orders[i].size();j++)
        {
            if(arr.find(orders[i][j])==string::npos)
            {
                arr+=orders[i][j];
            }
        }
    }
    
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<course.size();i++)
    {
        memset(visited,0,sizeof(visited));
        tmp.clear();
        k.clear();
        sign=0;
        solve(orders,0,course[i],0);
        for(int i=0;i<k.size();i++)
        {
            answer.push_back(k[i]);
        }
    }
    answer.erase(unique(answer.begin(),answer.end()),answer.end());
    sort(answer.begin(),answer.end());
    
    return answer;
}

//
#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

map<string,int> m; //무작위 배열, 몇개인지
string arr;
int num[12]; //몇개가 최대인지

void solve(vector<string> &orders,int idx,string tmp)
{
    if(idx==arr.size())
    {
        int counting=0;
        for(int i=0;i<orders.size();i++)
        {
            int x=0;
            for(int j=0;j<tmp.size();j++)
            {
                if(orders[i].find(tmp[j])!=string::npos)
                {
                    x++;
                }
            }
            if(x==tmp.size())
            {
                counting++;
            }
            
        }
        
        m[tmp]=counting;
        num[tmp.size()]=max(num[tmp.size()],counting);
        
        return;
    }
    
    solve(orders,idx+1,tmp+arr[idx]);
    solve(orders,idx+1,tmp);
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i=0;i<orders.size();i++)
    {
        for(int j=0;j<orders[i].size();j++)
        {
            if(arr.find(orders[i][j])==string::npos)
            {
                arr+=orders[i][j];
            }
        }
    }
    sort(arr.begin(),arr.end());
    
    solve(orders,0,"");
    
    for(int i=0;i<course.size();i++)
    {
        for(auto x:m)
        {
            //cout<<x.first<<" "<<x.second<<"\n";
            if(num[course[i]]==x.second && course[i]==x.first.size() && x.second>=2)
            {
                //cout<<x.first<<" "<<x.second<<" "<<num[course[i]]<<" "<<course[i]<<"\n";
                answer.push_back(x.first);
            }
            
        }
    }
    sort(answer.begin(),answer.end());
    
    return answer;
}
//

