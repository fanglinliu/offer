/**复制复杂链表
题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        map<RandomListNode*, int> addr2Index;
        addr2Index[nullptr] = -1;
        int index = 0;
        for (RandomListNode *pNode = pHead; 
             pNode != nullptr;
             pNode = pNode->next, index++) {
            addr2Index[pNode] = index;
        }
        
        map<int, int>index2Index;
        index = 0;
        for (RandomListNode *pNode = pHead; 
             pNode != nullptr;
             pNode = pNode->next, index++) {
            index2Index[index] = addr2Index[pNode->random];
        }

        RandomListNode *pNewHead = nullptr;
        RandomListNode *pNewTail = nullptr;
        index = 0;
        for (RandomListNode *pNode = pHead; 
             pNode != nullptr;
             pNode = pNode->next, index++) {
            RandomListNode *pNewNode = new RandomListNode(pNode->label);
            if (pNewTail == nullptr) {
                pNewHead = pNewNode;
                pNewTail = pNewNode;
            } else {
                pNewTail->next = pNewNode;
                pNewTail = pNewNode;
            }
        }
        
        map<int, RandomListNode*> index2Addr;
        index2Addr[-1] = nullptr;
        index = 0;
        for (RandomListNode *pNode = pNewHead; 
             pNode != nullptr;
             pNode = pNode->next, index++) {
            index2Addr[index] = pNode;
        }
        
        index = 0;
        for (RandomListNode *pNode = pNewHead; 
             pNode != nullptr;
             pNode = pNode->next, index++) {
            pNode->random = index2Addr[index2Index[index]];
        }
        
        return pNewHead;
    }
        
};