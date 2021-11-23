#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;

struct Node{
    Node(int _n, int _x, int _y) : num(_n), x(_x), y(_y) {}
    Node* left{};
    Node* right{};
    int num;
    int x;
    int y;
};
class Tree{
public:
    Tree(int n, int x, int y); 
    void AddNode(int n, int x, int y);
    void AddAnswerPostOrder(vector<vector<int>>& answer);
    void AddAnswerPreOrder(vector<vector<int>>& answer);
    ~Tree();
private:
    Node* root;
    void Recursive_addNode(Node* root, Node* newNode);
    void Recursive_PostOrder(Node* root, function<void(Node* node)> func);    
    void Recursive_PreOrder(Node* root, function<void(Node* node)> func);
};
Tree::~Tree()
{
    auto deleteNode = [](Node* node)
    {
        delete node;
    };
    Recursive_PostOrder(root, deleteNode);
}
void Tree::AddAnswerPostOrder(vector<vector<int>>& answer)
{
    auto AddAnswer = [&answer](Node* node)
    {
        answer[1].push_back(node->num);
    };
    Recursive_PostOrder(root, AddAnswer);
}
void Tree::Recursive_PostOrder(Node* root, function<void(Node* node)> func)
{
    if(root == nullptr) return;
    Recursive_PostOrder(root->left, func);
    Recursive_PostOrder(root->right, func);
    func(root);
}
void Tree::AddAnswerPreOrder(vector<vector<int>>& answer)
{
    auto AddAnswer = [&answer](Node* node)
    {
        answer[0].push_back(node->num);
    };
    Recursive_PreOrder(root, AddAnswer);
}
void Tree::Recursive_PreOrder(Node* root, function<void(Node* node)> func)
{
    if(root == nullptr) return;    
    func(root);
    Recursive_PreOrder(root->left, func);
    Recursive_PreOrder(root->right, func);
}
Tree::Tree(int n, int x, int y)
{
    root = new Node(n,x,y);
}

void Tree::AddNode(int n, int x, int y)
{
    Node* newNode = new Node(n,x,y);
    Recursive_addNode(root, newNode);
}
void Tree::Recursive_addNode(Node* root, Node* newNode)
{
    if(root->x > newNode->x)
    {
        if(root->left == nullptr)
            root->left = newNode;
        else
            Recursive_addNode(root->left, newNode);
    }
    else
    {
        if(root->right == nullptr)
            root->right = newNode;
        else
            Recursive_addNode(root->right, newNode);
    }
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    answer.resize(2);
    for(int i = 0; i < nodeinfo.size(); ++i)
    {
        nodeinfo[i].push_back(i + 1);
    }
    
    auto comp = [](const vector<int>& lhs, const vector<int>& rhs)
    {
        if(lhs[1] > rhs[1]) return true;
        else if(lhs[1] == rhs[1] && lhs[0] < rhs[0]) return true;
        else return false;
    };
    sort(nodeinfo.begin(), nodeinfo.end(), comp);
    
    Tree tree(nodeinfo[0][2], nodeinfo[0][0], nodeinfo[0][1]);
    for(int i = 1; i < nodeinfo.size(); ++i)
    {
        int num,x,y;
        num = nodeinfo[i][2];
        x = nodeinfo[i][0];
        y = nodeinfo[i][1];
        tree.AddNode(num, x, y);
    }
    
    tree.AddAnswerPreOrder(answer);
    tree.AddAnswerPostOrder(answer);
    return answer;
}