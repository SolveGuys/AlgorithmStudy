#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
    int m_val;
    Node* m_next;
    Node* m_prev;
    
    Node(int val, Node* next, Node* prev) :
        m_val(val),
        m_next(next),
        m_prev(prev)
    {
    }
    
    static void Advance(Node** node, int offset)
    {
        if (offset >= 0)
        {
            for (int i = 0; i < offset; ++i)
            {
                *node = (*node)->m_next;
            }
        }
        else
        {
            offset = -offset;
            
            for (int i = 0; i < offset; ++i)
            {
                *node = (*node)->m_prev;
            }
        }
    }
    
    static void Erase(Node* node)
    {
        if (node->m_next != nullptr)
        {
            node->m_next->m_prev = node->m_prev;
        }
        
        if (node->m_prev != nullptr)
        {
            node->m_prev->m_next = node->m_next;
        }
    }
    
    static void Insert(Node* node)
    {
        if (node->m_next != nullptr)
        {
            node->m_next->m_prev = node;
        }
        
        if (node->m_prev != nullptr)
        {
            node->m_prev->m_next = node;
        }
    }
};

string solution(int n, int k, vector<string> cmd)
{
    string answer(n, 'O');
    Node* node = new Node(0, nullptr, nullptr);
    Node* cursor = node;
    stack<Node*> stk;

    for (int i = 1; i < n; ++i)
    {
        node->m_next = new Node(i, nullptr, node);
        node = node->m_next;
    }
    
    // k행을 선택한다.
    Node::Advance(&cursor, k);
    
    for (const string& c : cmd)
    {
        switch (c[0])
        {
            case 'U':
            {
                int cnt = stoi(c.substr(2));
                
                Node::Advance(&cursor, -cnt);
            }
                break;
            case 'D':
            {
                int cnt = stoi(c.substr(2));
                
                Node::Advance(&cursor, cnt);
            }
                break;
            case 'C':
                stk.push(cursor);
                Node::Erase(cursor);
            
                if (cursor->m_next != nullptr)
                {
                    cursor = cursor->m_next;
                }
                else
                {
                    cursor = cursor->m_prev;   
                }
                break;
            case 'Z':
                Node::Insert(stk.top());
                stk.pop();
                break;
        }
    }
    
    while (!stk.empty())
    {
        answer[stk.top()->m_val] = 'X';
        stk.pop();
    }
    
    return answer;
}
