#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

map<string,int> m;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for(int k=0;k<clothes.size();k++)
    {
        m[clothes[k][1]]++;
    }
    
    for(auto a:m){
        answer=answer*(a.second+1);
    }
    answer--;
    
    
    
    
    
    return answer;
}
