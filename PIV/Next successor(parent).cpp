/*
Given parent pointer but no value.
if right is not NULL, find min of right subtree
else, iterately go to parent, find a parent that target is locate on left subtree, if nothing returned, return NULL

Time: worst case O(h), when balanced, O(logn)

Follow up: inorder print all tree, O(n), because each node will be visited at most twice
*/

struct Node{
	int val;
	Node *left, *right, *parent;
	Node(int x) : val(x), left(NULL), right(NULL), parent(NULL){}
};

class Solution{
public:
	Node* nextSuccessor(Node* p){
		if (p->right != NULL){
			p = p->right;
			while (p->left != NULL) p = p->left;
			return p;
		}
		else{
			while (p->parent != NULL){
				if (p == p->parent->right) return p->parent;
				else p = p->parent;
			}
			return NULL;
		}
	}
};

void main(){
	Node *n1 = new Node(5);
	Node *n2 = new Node(2);
	Node *n3 = new Node(9);
	Node *n4 = new Node(1);
	Node *n5 = new Node(4);
	Node *n6 = new Node(7);
	Node *n7 = new Node(3);
	Node *n8 = new Node(6);
	Node *n9 = new Node(8);
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n5->left = n7;
	n6->left = n8;
	n6->right = n9;
	n2->parent = n1;
	n3->parent = n1;
	n4->parent = n2;
	n5->parent = n2;
	n6->parent = n3;
	n7->parent = n5;
	n8->parent = n6;
	n9->parent = n6;

	Solution s;
	auto t = s.nextSuccessor(n9);
	cout << t->val << endl;
}