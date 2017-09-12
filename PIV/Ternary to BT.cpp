struct TreeNode{
	char label;
	TreeNode *left, *right;
	TreeNode(char a): label(a){}
};

//iterate version
class Solution{
public:
	TreeNode* convert(string s){
		if (s.empty()) return NULL;
		stack<TreeNode*> st;
		TreeNode* root = new TreeNode(s[0]);
		st.push(root);
		for (int i = 1; i < s.size(); i += 2){
			TreeNode* cur = new TreeNode(s[i+1]);
			char c = s[i];
			if (c == '?'){
				st.top()->left = cur;
			}
			else if (c == ':'){
				st.pop(); //go to parent first
				while (st.top()->right != NULL) st.pop();
				st.top()->right = cur;
			}	
			st.push(cur);
		}
		return root;
	}
};

//recursive version
class Solution{
public:
	TreeNode* convert(string s){
		int i = 0;
		TreeNode* root = buildTree(s, i);
		return root;		
	}
	
	TreeNode* buildTree(string s, int &i){
		TreeNode* root = new TreeNode(s[i]);
		i += 2; //move the index
		if (i < s.size() && s[i-1] == '?'){ //this is a root of subtree
			root->left = buildTree(s, i);
			root->right = buildTree(s, i);
		}
		//else this is a leaf
		return root;
	}
};