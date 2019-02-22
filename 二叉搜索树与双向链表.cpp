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
        
        TreeNode *headNode = nullptr, *tailNode = nullptr;
        Convert(pRootOfTree, &headNode, &tailNode);
        return headNode;
    }
    
    void Convert(TreeNode* pNode, TreeNode **headNode, TreeNode **tailNode)
    {
        if (pNode->left == nullptr) {
            *headNode = pNode;
        } else {
            TreeNode *leftHeadNode = nullptr, *leftTailNode = nullptr;
            Convert(pNode->left, &leftHeadNode, &leftTailNode);
            leftTailNode->right = pNode;
            pNode->left = leftTailNode;
            *headNode = leftHeadNode;
        }
        
        if (pNode->right == nullptr) {
            *tailNode = pNode;
        } else {
            TreeNode *rightHeadNode = nullptr, *rightTailNode = nullptr;
            Convert(pNode->right, &rightHeadNode, &rightTailNode);
            rightHeadNode->left = pNode;
            pNode->right = rightHeadNode;
            
            *tailNode = rightTailNode;
        }        
    }

};