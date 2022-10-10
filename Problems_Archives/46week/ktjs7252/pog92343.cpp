#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

vector<int> v[17];
bool visited[17];
int answer;
void solve(int x,int sheep,int wolf,vector<int> arr,vector<int>& info)
{
    if(sheep>wolf){
        answer=max(answer,sheep);
    }
    else{
        return;
    }
    for(int i=0;i<v[x].size();i++)
    {
        if(!visited[v[x][i]]){
            arr.push_back(v[x][i]);
        }
    }
    
    for(int i=0;i<arr.size();i++)
    {
        if(!visited[arr[i]]){
            visited[arr[i]]=true;
            
            if(info[arr[i]]==0){
                sheep++;
            }
            else{
                wolf++;
            }
            solve(arr[i],sheep,wolf,arr,info);
            
            visited[arr[i]]=false;
            if(info[arr[i]]==0){
                sheep--;
            }
            else{
                wolf--;
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    
    for(int i=0;i<edges.size();i++)
    {
        int a=edges[i][0];
        int b=edges[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    visited[0]=true;
    vector<int> arr;
    arr.push_back(0);
    solve(0,1,0,arr,info);
    
    
    return answer;
}
