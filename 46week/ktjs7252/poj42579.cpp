#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,int> arr;
vector<pair<string,int>> tmp;
vector<pair<string,pair<int,int>>> v;

bool des(pair<string,int> a,pair<string,int> b){
    return a.second>b.second;
}

bool desc(pair<string,pair<int,int>> a,pair<string,pair<int,int>> b)
{
    return a.second.first>b.second.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for(int i=0;i<genres.size();i++)
    {
        arr[genres[i]]+=plays[i];
        v.push_back({genres[i],{plays[i],i}});
    }
    
    sort(v.begin(),v.end(),desc);
    
    for(auto a:arr)
    {
        tmp.push_back({a.first,a.second});
    }
    sort(tmp.begin(),tmp.end(),des);
    
    for(int i=0;i<tmp.size();i++)
    {
        string s=tmp[i].first;
        int counting=0;
        
        for(int j=0;j<v.size();j++)
        {
            if(counting==2){
                break;
            }
            if(s==v[j].first){
                answer.push_back(v[j].second.second);
                counting++;
            }
        }
    }
    
    
    
    return answer;
}
