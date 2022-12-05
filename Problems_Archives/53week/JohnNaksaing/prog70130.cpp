#include <string>
#include <vector>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
//	통과 (112.54ms, 35.5MB)
int solution(std::vector<int> a) {
    std::unordered_map<int,int> map;
    
    for(auto i : a)
        map[i]++;
    std::vector<std::pair<int,int>> vec(map.begin(),map.end());
    using s = std::pair<int,int>;
    std::sort(vec.begin(),vec.end(),[](const s& l,const s& r)->bool
              {return l.second > r.second;}
             );
    int answer = -1;
    for(const s p: vec)
    {
        //std::cout << p.first << ' ';
        int here = p.first;
        int count = p.second;
        
        if(answer > count)
            continue;
        
        int length = 0;
        bool bHere = false;
        bool bOther = false;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] == here)
            {
                bHere = true;
            }
            else
            {
                bOther = true;
            }
            
            if(bHere && bOther)
            {
                length++;
                bHere = false;
                bOther = false;
            }
        }
        answer = std::max(answer,length);
    }
    
    return answer * 2;
}