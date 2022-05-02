#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> solution(std::string s) {
    std::vector<int> answer;
    
    std::string temp;
    bool b[100001] = {false,};
    bool bTuple = false;
    std::vector<int> vec_temp;
    std::vector<std::vector<int>> vecs;
    
    for(int i = 1; i < s.size()-1; i++)
    {
        char c = s[i];
        
        if(c == '{') 
        {
            bTuple = true;
            continue;   
        }
        else if(c == ',')
        {
            if(!bTuple)
                continue;
            else
            {
                vec_temp.push_back(std::stoi(temp));
                temp = "";
            }
        }
        else if(c == '}')
        {
            bTuple = false;
            vec_temp.push_back(std::stoi(temp));       
            vecs.push_back(vec_temp);
            
            vec_temp = std::vector<int>();
            temp = "";
        }
        else
        {
            temp += c;
        }
    }
    
    std::sort(vecs.begin(),vecs.end(), [](const auto& v1,const auto& v2) { return v1.size() < v2.size(); });
    for(const auto& vec : vecs)
    {
        for(int i = 0; i < vec.size(); i++)
        {   
            int temp = vec[i];
            if(!b[temp])
            {
                b[temp] = true;
                answer.push_back(temp);
            }
        }
    }
    
    return answer;
}

/*

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class number
{
public:
    int val;
    int cnt;
};
int counts[100001];

std::vector<int> solution(std::string s) {
    std::vector<int> answer;
    
    std::string temp;
    bool bTuple = false;

    for(int i = 1; i < s.size()-1; i++)
    {
        char c = s[i];
        
        if(c - '0' >= 0 && c - '0' <= 9)
        {
            temp += c;
        }
        
        if(c == '{') 
        {
            bTuple = true;
            continue;   
        }
        else if(c == ',')
        {
            if(!bTuple)
                continue;
            else
            {
                counts[std::stoi(temp)]++;
                temp = "";
            }
        }
        else if(c == '}')
        {
            bTuple = false;
            counts[std::stoi(temp)]++;
            temp = "";
        }

    }
    
    std::vector<number> vec_nums;
    
    for(int i = 0; i < 100001; i++)
    {
        if(counts[i])
            vec_nums.push_back({i,counts[i]});
    }
    std::sort(vec_nums.begin(), vec_nums.end(), [](const auto& n1, const auto& n2){return n1.cnt > n2.cnt;});
    for(const auto& num : vec_nums)
    {
        answer.push_back(num.val);
    }
    
    return answer;
}

*/