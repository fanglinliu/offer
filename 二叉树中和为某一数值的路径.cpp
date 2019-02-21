/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectedNumber) {
        vector<vector<int>> result;
        int sum = 0;
        vector<int> path;
        FindPath(root, expectedNumber, path, sum, result);
        sort(result.begin(), result.end(), [](auto& path1, auto& path2) {
            return path1.size() > path2.size();
        });
        return result;
    }
    
    void FindPath(TreeNode* root,int expectedNumber, vector<int>& path, int& sum, vector<vector<int>>& result) {
        if (root == nullptr) {
            return;
        }
        
        sum += root->val;
        path.push_back(root->val);
        
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == expectedNumber && path.size() > 0) {
                result.push_back(path);
            }
        } else {
            FindPath(root->left, expectedNumber, path, sum, result);
            FindPath(root->right, expectedNumber, path, sum, result);
        }
        
        sum -= root->val;
        path.pop_back();

    }
};