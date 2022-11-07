#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int answer = 1e18;
bool visited[55];

void dfs(string begin, string target, vector<string> &words,int tmp)
{
    if(begin==target)
    {
        answer=min(answer,tmp);
        return;
    }
    for(int i=0;i<words.size();i++)
    {
        int sign=0;
        for(int j=0;j<begin.size();j++)
        {
            if(begin[j]!=words[i][j]){
                sign++;
            }
        }
        if(sign==1 && visited[i]==0)
        {
            visited[i]=1;
            dfs(words[i],target,words,tmp+1);
            visited[i]=0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int sign=0;
    for(int i=0;i<words.size();i++)
    {
        if(target==words[i]){
            sign=1;
            break;
        }
    }
    if(sign==0){
        return 0;
    }
    
    dfs(begin,target,words,0);
    
    return answer;
}
