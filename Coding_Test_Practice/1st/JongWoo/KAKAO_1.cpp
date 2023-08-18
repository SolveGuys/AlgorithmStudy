#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices)
{
    string answer = "";
    unordered_map<char, int> um;
    int idx = 0;
    
    for (const string& str : survey)
    {
        switch (choices[idx])
        {
            case 1:
                um[str[0]] += 3;
                break;
            case 2:
                um[str[0]] += 2;
                break;
            case 3:
                um[str[0]] += 1;
                break;
            case 5:
                um[str[1]] += 1;
                break;
            case 6:
                um[str[1]] += 2;
                break;
            case 7:
                um[str[1]] += 3;
                break;
        }
        
        idx++;
    }
    
    answer.push_back((um['R'] >= um['T']) ? 'R' : 'T');
    answer.push_back((um['C'] >= um['F']) ? 'C' : 'F');
    answer.push_back((um['J'] >= um['M']) ? 'J' : 'M');
    answer.push_back((um['A'] >= um['N']) ? 'A' : 'N');
    
    return answer;
}
