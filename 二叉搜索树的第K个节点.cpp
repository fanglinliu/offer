/**
二叉搜索树的第K个节点
*/


/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (pRoot == nullptr) {
            return nullptr;
        }
        
        TreeNode *leftNode = KthNode(pRoot->left, k);
        if (leftNode != nullptr) {
            return leftNode;
        }
        
        count++;
        if (count == k) {
            return pRoot;
        }
        
        return KthNode(pRoot->right, k);
     }
    
private:
    int count = 0;
};