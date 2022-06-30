#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[400];
int n;
vector<int> Weak;
vector<int> Dist;
//vector<int> arr;
int answer =  9999999;
int sign;

void solve(int idx,int counting,int person,int x) // 시작하는 인덱스, 몇개를 수리했는지, dist인덱스,친구 몇명을 사용했는지
{
    if(counting>=Weak.size())
    {
        sign=1;
        answer=min(answer,x);
        return;
    }
    if(x==Dist.size())
    {
        return;
    }
    
    
    if(arr[idx]!=1)
    {
        while(1)   
        {
            idx++;
            if(arr[idx]==1) break;
        }
    }
    for(int i=idx;i<=idx+Dist[person];i++)
    {
        if(arr[i]==1)
        {
            counting++;
        }
    }
    solve(idx+Dist[person]+1,counting,Dist[person+1],x+1);
    
}


int solution(int n, vector<int> weak, vector<int> dist) {
    
    sort(dist.begin(), dist.end(), greater<>());
    Weak=weak;
    Dist=dist;
    
    for(int i=0;i<weak.size();i++)
    {
        arr[weak[i]]=1;
        arr[weak[i]+n]=1;
    }
    
    for(int i=0;i<weak.size();i++)
    {
        solve(weak[i],0,0,0); // 시작하는 인덱스, 몇개를 수리했는지, dist인덱스,친구 몇명을 사용했는지
    }
    if(sign==0)
    {
        answer=-1;
    }
    
    
    return answer;
}

// 1 5 6 10 , 13 17 18 22
// 
// 1 3 4 9 10 , 13 15 16 21 22
