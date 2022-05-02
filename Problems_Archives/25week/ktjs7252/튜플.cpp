#include <algorithm>
#include <string>
#include <vector>
#include <map>


using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<int,int> counting;
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            if(s[i+1]==',')
            {
                string tmp;
                tmp+=s[i];
                counting[stoi(tmp)]++;
            }
            else
            {
                int j=i+1;
                string tmp="";
                tmp+=s[i]; 
                tmp+=s[j]; 
                while(1)
                {
                    if(s[j+1]==',')
                    {
                        break;
                    }
                    j++;
                    tmp+=s[j];
                }
                counting[stoi(tmp)]++;
                i=j+1;
            }
        }
    }
    // 내가 원하는건 숫자, 몇개
    vector<pair<int,int>> arr;
    
    for(auto i :counting)
    {
        arr.push_back({i.second,i.first});
    }
    
    sort(arr.begin(),arr.end(),greater<pair<int,int>>());
    
    for(int i=0;i<arr.size();i++)
    {
        answer.push_back(arr[i].second);
    }
    

    
    
    return answer;
}
