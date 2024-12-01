#include<map>
#include <vector>
#include <iostream>

using namespace std;

struct Node{
    map<string, Node*> branch;
    string name;

    Node(string name){
        this->name = name;
    }
};

void printNode(int level, Node* node){
    if(level == -1){
        for(auto n: node->branch)
            printNode(level + 1, n.second);
        return;
    }
    for(int i = 0; i< level; i++)
        cout << "--";
    cout << node->name << endl;
    for(auto n: node->branch)
        printNode(level + 1, n.second);
}

int main(){
    int n, k;
    Node *head = new Node("");
    Node *now;
    string str;
    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> k;
        now = head;
        for(int j = 0; j < k; j++){
            cin >> str;
            if(now->branch.find(str) == now->branch.end()){
                now->branch[str] = new Node(str);
            }
            now = now->branch[str];
        }
    }
    printNode(-1, head);

    return 0;
}
