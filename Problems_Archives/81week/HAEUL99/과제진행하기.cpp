#include <bits/stdc++.h>


using namespace std;

int make_stT(string str)
{
    string tmp = "";
    int ans = 0;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == ':')
        {
            ans = stoi(tmp) * 60;
            tmp = "";
        }
        else
        {
            tmp += str[i];
        }
    }
    ans += stoi(tmp);
    return ans;
}
vector<tuple<int, int, string>> make_v(vector<vector<string>>& plans)
{
    vector<tuple<int, int, string>> ret;
    
    for(int i = 0; i < plans.size(); i++)
    {
        string name = plans[i][0];
        int st = make_stT(plans[i][1]);
        int t = stoi(plans[i][2]);
        
        ret.push_back(make_tuple(st, t, name));
  
    }
    return ret;
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    vector<tuple<int, int, string>> v; // 시작시간/ 걸리는시간 / 과목명
    v = make_v(plans);
    
    sort(v.begin(), v.end());
    stack<pair<int, string>> s;
    for(int i = 1; i < plans.size(); i++)
    {
        int curst = get<0>(v[i]); //750
        int curt = get<1>(v[i]); // 100
        string name = get<2>(v[i]); // computer
        
        if(curst - get<0>(v[i-1]) >= get<1>(v[i-1])) // 10 앞의과목 다했으면
        {
            answer.push_back(get<2>(v[i-1]));
            int rT = curst - get<0>(v[i-1]) - get<1>(v[i-1]);

            while(rT > 0 && !s.empty())
            {
                int stop = s.top().first;
                string strtop = s.top().second;
                
                if(stop - rT <= 0)
                {
                    rT = rT - stop;
                    answer.push_back(s.top().second);

                    s.pop();
                }
                else 
                {
                    s.pop();
                    s.push(make_pair(stop-rT, strtop));

                    rT = 0;
                }
            }
        }   
        else
        {
            int remaintime = get<1>(v[i-1]) - (curst - get<0>(v[i-1])); 
            s.push(make_pair(remaintime, get<2>(v[i-1]))); //앞의 과목 넣기
        }
    }
    
    answer.push_back(get<2>(v[plans.size()-1]));

    // while(!s.empty()) 
    // {
    //     //cout << s.top().second << endl;
    //     answer.push_back(s.top().second );
    //     s.pop();
    // }  
    int siz = s.size();
    while(siz >0)
    {
        siz--;
        answer.push_back(s.top().second );
        s.pop();
    }
    
    
    return answer;
}
