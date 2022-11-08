#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n);
    stack<int> connection;
    int answer = 0;
    //int n = computers.size();
    
    for(int k = 0; k < n;k++){
        if(visited[k])
            continue;
        else
            answer++;
        
        connection.push(k);
        while(!connection.empty()){
            int i = connection.top();   connection.pop();
            if(visited[i])continue;
            visited[i] = true;

            for(int j = 0; j < n; j++){
                if(computers[i][j] == 1 && visited[j] == false){
                    connection.push(j);
                }
            }
        }
    }
    
    return answer;
}