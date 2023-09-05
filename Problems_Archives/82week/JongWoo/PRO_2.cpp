#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int answer = 0;
    vector<char> per = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
    unordered_map<char, int> um;
    
    do
    {
        for (int i = 0; i < per.size(); ++i)
        {
            um[per[i]] = i;
        }
        
        bool isValid = true;
        
        for (int i = 0; i < n; ++i)
        {
            int between = abs(um[data[i][0]] - um[data[i][2]]) - 1;
            
            if (((data[i][3] == '=') && (between != data[i][4] - '0')) ||
                ((data[i][3] == '<') && (between >= data[i][4] - '0')) ||
                ((data[i][3] == '>') && (between <= data[i][4] - '0')))
            {
                isValid = false;
                break;
            }
        }
        
        if (isValid)
        {
            ++answer;
        }
    } while (next_permutation(per.begin(), per.end()));
    
    return answer;
}
