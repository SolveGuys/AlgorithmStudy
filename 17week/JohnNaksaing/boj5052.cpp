#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string>& phone_book)  {
    bool answer = true;
    if(phone_book.size() == 1) return true;
    sort(phone_book.begin(),phone_book.end());
    for(int i = 0; i < phone_book.size()-1; i++) {
        std::string small = phone_book[i];
        std::string big = phone_book[i+1].substr(0,small.size());
        if(0 == small.compare(big)){
            return false;
        }
    }
    return answer;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<string> phone_book(n);
        for(int i = 0; i < n; i++)
        {
            cin >> phone_book[i];            
        }
        if(solution(phone_book))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}