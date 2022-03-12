#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
bool IsMinimality(const vector<int>& candidate, const set<vector<int>>& candidateKeys, vector<int>& temp, int idx)
{

    if(candidateKeys.find(temp) != candidateKeys.end())
    {
        return false;
    }

    int size = candidate.size();
    for(int i = idx; i < size; ++i)
    {
        temp.push_back(candidate[i]);
        if(IsMinimality(candidate, candidateKeys, temp, i + 1) == false)
            return false;       
        temp.pop_back();
    }
    return true;

}
bool IsValid(const vector<vector<string>>& relation, const vector<int>& candidate, const set<vector<int>>& candidateKeys)
{
    // 유일성 검증
    set<string> keys;
    for(const auto& row : relation )
    {
        string str;
        for(int col : candidate)
        {
            str += row[col];
        }
        auto result = keys.insert(str);

        // 중복된 키가 존재할 경우 유효하지 않은 후보키이다.
        if(result.second == false)
            return false;
    }
    // 최소성 검증
    vector<int> temp;
    if(IsMinimality(candidate, candidateKeys, temp, 0) == false)
    {
        return false;
    }
    // 유일성과 최소성을 만족한 경우
    return true;
}

void BT(vector<vector<string>>& relation, vector<int>& candidate, set<vector<int>>& candidateKeys, int idx, int targetDep)
{  
    if(targetDep == candidate.size())  
    {
        // 후보키 발견
        if(IsValid(relation, candidate, candidateKeys))
        {
            candidateKeys.insert(candidate);
            return;
        }
    }

    const int colSize = relation[0].size();
    for(int i = idx; i < colSize; ++i)
    {
        candidate.push_back(i);
        // 탐색하려는 후보키가 완성된 후보키에 없다면 탐색 진행
        if(candidateKeys.find(candidate) == candidateKeys.end())
            BT(relation, candidate, candidateKeys, i + 1, targetDep);
        candidate.pop_back();
    }

    return;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<int> candidate;
    set<vector<int>> candidateKeys;
    const int colSize = relation[0].size();
    for(int i = 1; i <= colSize; ++i)
    {
       BT(relation, candidate, candidateKeys, 0, i);
    }
    answer = candidateKeys.size();
    return answer;
}