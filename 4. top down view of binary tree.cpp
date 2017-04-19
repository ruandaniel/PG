struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(NULL), right(NULL){}
};

class Solution{
public:
	vector<int> topView(TreeNode* root){
		if (root == NULL) return{};
		int l = 0, r = 0;
		unordered_map<int, int> m;
		queue<pair<TreeNode*, int>> q;
		q.push({ root, 0 });
		while (!q.empty()){
			auto t = q.front();
			q.pop();
			int index = t.second;
			if (index > r) r = index;
			else if (index < l) l = index;
			if (!m.count(index)){
				m[index] = t.first->val;
			}
			if (t.first->left != NULL) q.push({ t.first->left, index - 1 });
			if (t.first->right != NULL) q.push({t.first->right, index + 1});
		}
		vector<int> res;
		for (int i = l; i <= r; i++)
			res.push_back(m[i]);
		return res;
	}
};

//BFS, O(n)
