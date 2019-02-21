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
        vector<vector<int> > paths;
        
        if (root == nullptr) {
            return paths;
        }
        
        vector<int> path;
        FindPath(root, expectedNumber, path, paths);
        
        stable_sort(paths.begin(), paths.end(), [](auto path1, auto path2){
            return path1.size() >= path2.size();
        });
        
        return paths;
    }
    
    void FindPath(TreeNode* root, int expectedNumber, vector<int> path, vector<vector<int> >& paths) {
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (accumulate(path.begin(), path.end(), 0) == expectedNumber) {
                paths.push_back(path);
            }
            
            return;
        }
        
        if (root->left) {
            FindPath(root->left, expectedNumber, path, paths);
        }
        
        if (root->right) {
            FindPath(root->right, expectedNumber, path, paths);
        }
    }
    
};