#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

pair<int,int> tree[10001];//트리
map<int,pair<int,int>> m;//키 : 번호, 값 : 위치
vector<int> pre;//전위순회
vector<int> post;//후위순회

//정렬을 위한 구조체
struct edge {
	int idx,x,y;
};

//y축 기준으로 내림차순 정렬
bool cmp(edge a,edge b){
	if(a.y == b.y){
		//y축이 같다면 x축을 기준으로 오름차순 정렬
		return a.x < b.x;
	}
	return a.y > b.y;
}

//트리 제작
void insert(int root, edge e){
	pair<int,int> nowpos = m[root];
	//왼쪽 자식인 경우
	if(nowpos.first > e.x){
		if(tree[root].first == root){//왼쪽 자식의 끝
            //왼쪽 자식에 붙이기
			tree[root].first = e.idx;
			return;
		}
		else{//재귀
			insert(tree[root].first,e);
		}
	}else{//오른쪽 자식인 경우
		if(tree[root].second == root){
			tree[root].second = e.idx;
			return;
		}else{
			insert(tree[root].second,e);
		}
	}
	return;
}

//전위순회
void front(int root){
	pre.push_back(root);//경로추가
    //리프가 아니라면 왼쪽 자식탐색
	if(tree[root].first!=root){
		front(tree[root].first);
	}
    //리프가 아니라면 오른쪽 자식탐색
	if(tree[root].second!=root){
		front(tree[root].second);
	}
}

//후위순회
void end(int root){
    //리프노드가 아니라면 왼쪽 탐색
	if(tree[root].first!=root){
		end(tree[root].first);
	}
    //리프노드가 아니라면 오른쪽 탐색
	if(tree[root].second!=root){
		end(tree[root].second);
	}
	post.push_back(root);//경로탐색
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
   vector<vector<int>> answer;
   vector<edge> node;//정렬용
   
   //트리 초기화
   for(int i=1;i<=nodeinfo.size();i++){
   	tree[i].first = i;//왼쪽 자식
   	tree[i].second = i;//오른쪽 자식
   }
   //map을 이용해 정렬
   for(int i=0;i<nodeinfo.size();i++){
   	node.push_back({i+1,nodeinfo[i][0],nodeinfo[i][1]});//번호, 위치넣기
   	//key : 번호, value : 위치
   	m[i+1] = {nodeinfo[i][0],nodeinfo[i][1]};
   }
   //y축 기준으로 정렬
   sort(node.begin(),node.end(),cmp);
   
   int root = node[0].idx;//루트 인덱스 번호
   
   //트리생성
   for(int i=1;i<node.size();i++){
   	edge now = node[i];//현재 노드
   	insert(root,now);//자식으로 붙이기
   }
   
   //전위순회
   front(root);
   //후위순회
   end(root);
   
   answer.push_back(pre);
   answer.push_back(post);
   return answer;
}
