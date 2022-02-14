#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;
using Table = unordered_map<string, string>;

void ProcessRecord(const string& command, const string& id, const string& name, Table& idTable, vector<vector<string>>& log)
{
    if(command[0] == 'E'){ //입장
        idTable[id] = name; 
        log.push_back({id, "님이 들어왔습니다."});
    }
    else if(command[0] == 'C') // 닉네임 변경
        idTable[id] = name; 
    else // 퇴장
        log.push_back({id, "님이 나갔습니다."});
}
vector<string> solution(vector<string> record) {
    vector<string> answer;
    Table idTable;
    vector<vector<string>> log;

    for(const auto& row : record)
    {
        stringstream ss(row);
        string command, id, name;

        ss >> command;
        ss >> id;
        if(command[0] != 'L')
            ss >> name; 

        ProcessRecord(command, id, name, idTable, log);
    }

    for(const auto& row : log)
    {
        answer.emplace_back(idTable[row[0]] + row[1]);
    }
    return answer;
}