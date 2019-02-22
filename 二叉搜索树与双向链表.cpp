/**

二叉搜索树与双向链表
题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == nullptr) {
            return nullptr;
        }
        
        TreeNode *tailNode = nullptr;
        Convert(pRootOfTree, tailNode);
        
        TreeNode *headNode = tailNode;
        while (headNode->left) {
            headNode = headNode->left;
        }
        
        return headNode;
    }
    
    void Convert(TreeNode* pNode, TreeNode *& tailNode)
    {
        if (pNode->left) {
            Convert(pNode->left, tailNode);
        }
        
        if (tailNode) {
            tailNode->right = pNode;
        }
        pNode->left = tailNode;
        tailNode = pNode;
        
        if (pNode->right) {
            Convert(pNode->right, tailNode);
        }
    }

};