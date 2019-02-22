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
        
        TreeNode *pHeadNode = nullptr;
        Convert(pRootOfTree, pHeadNode);
        
        return pHeadNode;
    }
    
    void Convert(TreeNode* pNode, TreeNode *& pHeadNode)
    {
        if (pNode->right) {
            Convert(pNode->right, pHeadNode);
        }
        
        pNode->right = pHeadNode;
        if (pHeadNode) {
            pHeadNode->left = pNode;
        }
        pHeadNode = pNode;
        
        if (pNode->left) {
            Convert(pNode->left, pHeadNode);
        }
        
    }

};