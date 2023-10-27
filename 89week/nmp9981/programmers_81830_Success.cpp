#include <string>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

//연결리스트 노드
struct Node{
    int n;
    Node* prev;
    Node* next;
    Node(int n,Node* prev,Node* next) : n(n), prev(prev),next(next){}//생성자
};

string solution(int n, int k, vector<string> cmd) {
    string ans;
    for(int i=0;i<n;i++) ans+='O';
    stack<Node*> deleteNode;//삭제한 노드
    
    Node* node = new Node(0,NULL,NULL);
    Node* cur = node;//현재 가리키는 행(0)
    
    //테이블 제작
    for(int i=1;i<n;i++){
        node->next = new Node(i,node,NULL);
        node = node->next;
    }
    //k번째 행 가리키기
    for(int i=0;i<k;i++){
        cur = cur->next;
    }
    
    //명령 실행
    for(string c:cmd){
        if(c=="C"){//삭제
            deleteNode.push(cur);
            if(cur->prev!=NULL){//이전 커서 존재
                cur->prev->next = cur->next;
            }
            if(cur->next!=NULL){//다음 커서 존재
                cur->next->prev = cur->prev;
            }
            if(cur->next == NULL) cur = cur->prev;
            else cur = cur->next;
        }else if(c=="Z"){
            Node* n = deleteNode.top();
            deleteNode.pop();
            
            if(n->prev!=NULL) n->prev->next = n;
            if(n->next!=NULL) n->next->prev = n;
        }else{//커서 이동
            int amount = stoi(c.substr(2));
            while(amount--){
                if(c[0]=='U') cur = cur->prev;
                else cur = cur->next;
            }
        }
    }
    while(!deleteNode.empty()){
        ans[deleteNode.top()->n] = 'X';
        deleteNode.pop();
    }
    return ans;
}
