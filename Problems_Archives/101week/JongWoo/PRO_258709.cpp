// 1번부터 이 문제까지 1시간 54분 걸림

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int n, int depth, int cur, const vector<vector<int>>& dice, vector<int>& selected, vector<int>& tot);

vector<int> solution(vector<vector<int>> dice)
{
    vector<int> answer;
    int n = static_cast<int>(dice.size());
    int half = n / 2;
    vector<int> combi(n);
    int maxWinCnt = 0;
    
    answer.resize(half);
    
    for (int i = 0; i < half; ++i)
    {
        combi[i] = 1;
    }
    
    do
    {
        vector<int> selectedA, selectedB;
        vector<int> totA, totB;
        
        for (int i = 0; i < n; ++i)
        {
            if (combi[i] == 1)
            {
                selectedA.push_back(i);
            }
            else
            {
                selectedB.push_back(i);
            }
        }
        
        DFS(half, 0, 0, dice, selectedA, totA);
        DFS(half, 0, 0, dice, selectedB, totB);
    
        int m = static_cast<int>(totA.size());
        int winCnt = 0;
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (totA[i] > totB[j])
                {
                    ++winCnt;
                }
            }
        }
    
        if (winCnt > maxWinCnt)
        {
            maxWinCnt = winCnt;
            
            for (int i = 0; i < half; ++i)
            {
                answer[i] = selectedA[i] + 1;
            }
        }
    } while (prev_permutation(combi.begin(), combi.end()));
    
    return answer;
}

void DFS(int n, int depth, int cur, const vector<vector<int>>& dice, vector<int>& selected, vector<int>& tot)
{
    if (depth == n)
    {
        tot.push_back(cur);
        return;
    }
    
    for (int i = 0; i < 6; ++i)
    {
        DFS(n, depth + 1, cur + dice[selected[depth]][i], dice, selected, tot);
    }
}
