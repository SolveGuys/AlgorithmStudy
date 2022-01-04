#pragma once
#include <string>
#include <vector>
#include <stack>
#include <set>

#include <iostream>

// 프로그래머스에서는 전처리기로 처리해야 올바르게 인식합니다
//constexpr bool __USING_STL__ = true;

#define __USING_STL__ 1

using table_ds = std::set<int>;
using iterator = std::set<int>::iterator;

using std::prev;
using std::next;

#if __USING_STL__
std::string solution(int n, int k, std::vector<std::string> cmd) {
    std::cout << "from __USING_STL__";
    std::string answer(n,'X');
    {
        table_ds table;

        for (int i = 0; i < n; i++)
        {
            table.insert(i);
        }

        iterator cursor = table.find(k);
        std::stack<int> stack_history;
        
        for (std::string query : cmd)
        {
            char control = query[0];

            switch (control)
            {
            case 'U':
            case 'D':
            {
                int X = std::stoi(query.substr(2));

                control == 'U' ? cursor = prev(cursor, X) : cursor = next(cursor, X);

                //std::cout << *cursor << ',';
                break;
            }
            case 'C':
                stack_history.push(*cursor);
                cursor = table.erase(cursor);
                if(cursor == table.end()) cursor = prev(cursor);
                break;

            case 'Z':
            {
                int revert = stack_history.top();
                stack_history.pop();
                table.insert(revert);
                break;
            }
            default:
                return "oops";
                break;
            }
        }

        for (int i : table) /*std::cout << i << ' ',*/ answer[i] = 'O';


    }
    return answer;
}

//아래 구현 끝나면 else 제거할 수 있게 인터페이스 처리할 것
#else

class node
{

};
class double_ll
{
public:
	node find(int k){ return node{};}
    void insert(int val){}
    
    node begin() {return node{};}
    node end() {return node{};}
};

node prev(node& iter, const int& offset){ return iter; }
node next(node& iter, const int& offset){ return iter; }


using table_ds = double_ll;

table_iterator prev(table_iterator& iter, const int& offset);
table_iterator next(table_iterator& iter, const int& offset);

std::string solution(int n, int k, std::vector<std::string> cmd) {
    std::cout << "from __USING_DOUBLE_LL__";
    std::string answer(n,'X');

    //TODO : List를 이용하여 구현

	return answer;
}
#endif