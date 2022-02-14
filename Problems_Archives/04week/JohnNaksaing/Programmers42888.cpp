#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string,char>> in_outs;
    unordered_map<string, string> dict {};
    
    for(string query : record)
    {
        auto pos = query.find(" ");
        string e_l_c = query.substr(0,pos);
        string uid_name = query.substr(pos+1);
        auto pos1 = uid_name.find(" ");
        string uid = uid_name.substr(0,pos1);
        string name = uid_name.substr(pos1+1);
        switch(e_l_c[0])
        {
            case 'E':
                dict[uid] = name;
                in_outs.push_back(make_pair(uid,'E'));
                break;
            case 'L':
                in_outs.push_back(make_pair(uid,'L'));
                break;
            case 'C':
                dict[uid] = name;
                break;
            default:break;      
        }
    }
    
    for(pair<string,char> q : in_outs)
    {
        if(q.second == 'C') continue;
        string ans = dict[q.first] + "님이 ";
        if(q.second == 'E') ans += "들어왔습니다";
        else if(q.second == 'L') ans += "나갔습니다";
        
        answer.push_back(ans + ".");
    }
    
    return answer;
}