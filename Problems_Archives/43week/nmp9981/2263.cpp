#include <iostream>
using namespace std;

int n;
const int maxi = 100001;
int inOrder[maxi];//중위순회
int postOrder[maxi];//후위순회
int index[maxi];//중위기준 루트 인덱스

//입력
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> inOrder[i];
		index[inOrder[i]] = i;//루트 노드
	}
	for (int i = 1; i <= n; i++) cin >> postOrder[i];
}
//전위 순회
void PreOrder(int inStart,int inEnd,int postStart,int postEnd) {
	//분할 불가
	if (inStart > inEnd || postStart > postEnd) return;

	int root = postOrder[postEnd];//전위순회의 루트는 후위순회의 가장 마지막값
	int size = index[root] - inStart;
	cout << root << " ";
	PreOrder(inStart,index[root]-1,postStart,postStart+size-1);//왼쪽
	PreOrder(index[root]+1,inEnd,postStart+size,postEnd-1);//오른쪽
}
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	PreOrder(1,n,1,n);//전위 순회
    return 0;
}
