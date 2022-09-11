#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

map<string,int> counting;
map<string,set<string>> arr;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    for(int i=0;i<report.size();i++)
    {
        int pos=report[i].find(" ");
        string a=report[i].substr(0,pos);
        string b=report[i].substr(pos+1);
        
        if(arr[a].find(b)==arr[a].end())
        {
            counting[b]++;
            arr[a].insert(b);
        }
    }
    
    for(int i=0;i<id_list.size();i++)
    {
        int tmp=0;
        
        
        for(auto str:arr[id_list[i]])
        {
            if(counting[str]>=k)
            {
                tmp++;
            }
        }
         
        
        answer.push_back(tmp);
    }
    
    
    
    
    
    return answer;
}
