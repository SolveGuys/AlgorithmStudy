#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    
    map<string,vector<string>> closet;
    
    for(const vector<string>& a : clothes)
    {
        closet[a[1]].push_back(a[0]);
    }
    int answer = 1;
    for(const auto& a : closet)
    {
        //cout << a.second.size() <<'\n';
        answer *= (a.second.size()+1);
    }
    return answer - 1;
}