#include <string>
#include <vector>
#include <set>
#include <stack>
using namespace std;

stack<int> st;
set<int> a;
string solution(int n, int k, vector<string> cmd) {
    string ans;
    for(int i=0;i<n;i++) {
        a.insert(i);
        ans+='X';
    }
    auto it = a.begin();
    while(k--) it++; 
    for(auto c : cmd){
        char q = c[0];
        int num;
        if(c.size()>1) num = stoi(c.substr(2));
 
        if(q=='U') while(num--) it--;
        else if(q=='D') while(num--) it++;
        else if(q=='Z') {
            a.insert(st.top()); st.pop();
        }
        else {
            st.push(*it);
            it = a.erase(it);
            if(it==a.end()) it--;
        }
    }
    for(auto v : a) ans[v]='O';
    return ans;
}
