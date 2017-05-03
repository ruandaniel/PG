struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(NULL), right(NULL){}
};

//BFS, O(n), use HashMap
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

//use two arrays
class Solution{
public:
	vector<int> topView(TreeNode* root){
		if (root == NULL) return{};
		int l = 0, r = 0;
		vector<int> right(1, root->val), left(1, root->val);
		queue<pair<TreeNode*, int>> q;
		q.push({ root, 0 });
		while (!q.empty()){
			auto t = q.front();
			q.pop();
			if (t.first == NULL) continue;
			int index = t.second;
			TreeNode* node = t.first;
			if (index > 0 && index > r){
				right.push_back(node->val);
				r++;
			}
			if (index < 0 && index < l){
				left.push_back(node->val);
				l--;
			}
			q.push({ node->left, index - 1 });
			q.push({ node->right, index + 1 });
		}
		vector<int> res;
		for (int i = left.size() - 1; i >= 0; i--)
			res.push_back(left[i]);
		for (int j = 1; j < right.size(); j++)
			res.push_back(right[j]);
		return res;
	}
};