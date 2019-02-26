/**
两个链表的第一个公共节点

题目描述
输入两个链表，找出它们的第一个公共结点。

*/


/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int length1 = lengthOfList(pHead1);
        int length2 = lengthOfList(pHead2);
        if (length1 < length2) {
            swap(length1, length2);
            swap(pHead1, pHead2);
        }
        
        for (int i = 0; i < length1 - length2; i++) {
            pHead1 = pHead1->next;
        }
        
        while (pHead1 != pHead2) {
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        
        return pHead1;
    }
    
    int lengthOfList(ListNode* head) {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        
        return length;
    }
};