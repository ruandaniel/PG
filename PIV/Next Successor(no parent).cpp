/*
Given nodes' value.
if node has right subtree, find min in right
else, BS to find this node, if go left, record cur node because it might be our target

Time: worst case O(h), when balanced, O(logn)

Follow up: inorder print all tree, O(nlogn), times to visit one node doesn't has const upper bound
*/

struct Node{
	int val;
	Node *left, *right;
	Node(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	Node* nextSuccessor(Node* root, Node* p){
		if (p->right != NULL){
			p = p->right;
			while (p->left != NULL) p = p->left;
			return p;
		}
		else{
			Node* target = NULL;
			while (root != NULL){
				if (p->val < root->val){
					target = root;
					root = root->left;
				}
				else if (p->val > root->val){
					root = root->right;
				}
				else break;
			}
			return target;
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

	Solution s;
	auto t = s.nextSuccessor(n1, n9);
	cout << t->val << endl;
}