/**复制复杂链表
题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

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
        
        vector<int> path;
        FindPath(root, expectedNumber, path, paths);
        
        stable_sort(paths.begin(), paths.end(), [](auto path1, auto path2){
            return path1.size() >= path2.size();
        });
        
        return paths;
    }
    
    void FindPath(TreeNode* root, int expectedNumber, vector<int>& path, vector<vector<int> >& paths) {
        if (root == nullptr) {
            return;
        }
        
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (accumulate(path.begin(), path.end(), 0) == expectedNumber) {
                paths.push_back(path);
            }
        } else {
            FindPath(root->left, expectedNumber, path, paths);
            FindPath(root->right, expectedNumber, path, paths);
        }
        
        path.pop_back();
    }
    
};