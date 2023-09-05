#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> um = 
{
    { "-",        0 },
    
    { "cpp",      1 },
    { "java",     2 },
    { "python",   3 },
    
    { "backend",  1 },
    { "frontend", 2 },
    
    { "junior",   1 },
    { "senior",   2 },
    
    { "chicken",  1 },
    { "pizza",    2 }
};

// [개발 언어][지원 직군][지원 경력구분][선호하는 소울푸드]
vector<int> scores[4][3][3][3];

vector<int> solution(vector<string> info, vector<string> query)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> answer;

    for (const string& in : info)
    {
        stringstream ss(in);
        string str[4] = {};
        int score = 0;
        
        ss >> str[0] >> str[1] >> str[2] >> str[3] >> score;
        
        int arr[] = { um[str[0]], um[str[1]], um[str[2]], um[str[3]] };
        
        for (int i = 0; i < (1 << 4); ++i)
        {
            int indices[4] = {};
            
            for (int j = 0; j < 4; ++j)
            {
                if (i & (1 << j))
                {
                    indices[j] = arr[j];
                }
            }
            
            scores[indices[0]][indices[1]][indices[2]][indices[3]].push_back(score);
        }
    }
    
    for (int a = 0; a < 4; ++a)
    {
        for (int b = 0; b < 3; ++b)
        {
            for (int c = 0; c < 3; ++c)
            {
                for (int d = 0; d < 3; ++d)
                {
                    sort(scores[a][b][c][d].begin(), scores[a][b][c][d].end());
                }
            }
        }
    }
    
    for (const string& q : query)
    {
        stringstream ss(q);
        string str[4] = {};
        string tmp;
        int score = 0;
        
        ss.str(q);
        ss >> str[0] >> tmp >> str[1] >> tmp >> str[2] >> tmp >> str[3] >> score;

        const auto& v = scores[um[str[0]]][um[str[1]]][um[str[2]]][um[str[3]]];
        
        answer.push_back(v.end() - lower_bound(v.begin(), v.end(), score));
    }
    
    return answer;
}
