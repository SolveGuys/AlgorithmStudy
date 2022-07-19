#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

// vector<int> lan[50001]; //cpp 1, java 2, python 3
// vector<int> field[50001]; //backend 1 front 2
// vector<int> career[50001]; //junior 1, senior 1
// vector<int> food[50001]; // chicken 1 pizza 2
// vector<string> score[50001];

vector<vector<string>> tmp1;
vector<vector<string>> tmp2;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    
    for(int i=0;i<info.size();i++)
    {
        int start=0;
        int end=info[i].find(" ");
        vector<string> k;
        
        while(end!=string::npos)
        {
            string kk=info[i].substr(start,end-start);
            k.push_back(kk);
            start=end+1;
            end=info[i].find(" ",start);
        }
        k.push_back(info[i].substr(start,end-start));
        tmp1.push_back(k);
    }
    
       for(int i=0;i<query.size();i++)
    {
        int start=0;
        int end=query[i].find(" ");
        vector<string> k;
        
        while(end!=string::npos)
        {
            string kk=query[i].substr(start,end-start);
            k.push_back(kk);
            start=end+1;
            end=query[i].find(" ",start);
            start=end+1;
            end=query[i].find(" ",start);
        }
        k.push_back(query[i].substr(start,end-start));
        tmp2.push_back(k);
    }
    
    //cout<<tmp1.size()<<" "<<query.size();
    
    
    return answer;
}










