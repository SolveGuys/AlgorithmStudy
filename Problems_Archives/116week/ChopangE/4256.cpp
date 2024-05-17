#include<iostream>
#include<vector>

using namespace std;

struct node {

	int key = 0;
	struct node *left = NULL;
	struct node *right = NULL;

	node(int _key, node *_left, node *_right) : key(_key), left(_left), right(_right) {}
	node() :key(1), left(NULL), right(NULL) {}
};

//���� Ž���Ϸ��� ������ȸ node index
int idx = 0;		

node *makeTree(vector<int> &preorder, vector<int> &inorder, int start, int end) {

	int key = preorder[idx++];
	node *cur = new node(key, NULL, NULL);		//��� ����
	int index;
	for ( index = start; index <= end; index++ ) {		//key�� �ش��ϴ� ������ȸ index �˻�
		if ( inorder[index] == key )break;
	}
	if ( index - 1 >= start ) {				//index-1�� start���� ũ�ų� ������ left node�� ����. left subtree ����.
		cur->left = makeTree(preorder, inorder, start, index - 1);
	}
	if ( index + 1 <= end ) {				//index +1�� edn���� �۰ų� ������ right node�� ����. right subtree ����.
		cur->right = makeTree(preorder, inorder, index + 1, end);
	}
	return cur;
}

void postOrder(node *head) {				
	if ( head->left != NULL ) {
		postOrder(head->left);
	}
	if ( head->right != NULL ) {
		postOrder(head->right);
	}
	printf("%d ", head->key);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for ( int i = 0; i < T; i++ ) {
		idx = 0;
		int n;
		cin >> n;
		vector<int> preorder(n);
		vector<int> inorder(n);

		for ( int j = 0; j < n; j++ ) {
			cin >> preorder[j];
		}
		for ( int j = 0; j < n; j++ ) {
			cin >> inorder[j];
		}

		node *head = makeTree(preorder, inorder, 0, n - 1);
		postOrder(head);
		printf("\n");
	}
	return 0;
}