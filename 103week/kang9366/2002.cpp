#include <iostream>
#include <deque>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    string str;
    deque<string> dq1;
    queue<string> dq2;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> str;
        dq1.push_back(str);
    }

    for(int i = 0; i < N; i++) {
        cin >> str;
        dq2.push(str);
    }

    int answer = 0;

    while(!dq1.empty() && !dq2.empty()) {
        if(dq1.front() != dq2.front()) {
            answer++;
            dq1.erase(remove(dq1.begin(), dq1.end(), dq2.front()));
            dq2.pop();
        } else {
            dq1.erase(dq1.begin());
            dq2.pop();
        }
    }
    cout << answer; 
}
