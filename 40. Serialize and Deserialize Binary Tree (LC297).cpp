/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//Pre-order Mothod
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        buildString(root, str);
        return str;
    }
    
    void buildString(TreeNode* root, string &str){
        if (root == NULL){
            str += "# ";
        }
        else{
            str += to_string(root->val) + " ";
            buildString(root->left, str);
            buildString(root->right, str);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return buildTree(data, i);
    }
    
    TreeNode* buildTree(string data, int &i){
        int start = i;
        while (data[i] != ' ') i++;
        string num = data.substr(start, i - start);
        i++;
        if (num == "#") return NULL;
        else{
            TreeNode* cur = new TreeNode(atoi(num.c_str()));
            cur->left = buildTree(data, i);
            cur->right = buildTree(data, i);
            return cur;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));