/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//https://leetcode.com/problems/intersection-of-two-linked-lists/description/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // we walk the lists in parallel hoping to find a common node (using curA and curB).
    // if we can't find a common node, we may have exhausted one of the lists (curA or curB is NULL).
    // then start traversing from the beginning of the list we just exhausted (set either curA to headB or vice-versa)
    // we do this for both lists
    // we either find the common node (curA == curB) or, we will reach NULL
    ListNode *curA = headA;
    ListNode *curB = headB;
    while (curA && curB)
    {
        //see if the common node is current node
        if (curA == curB) {
            return curA;
        }
        //advance the current nodes
        curA = curA->next;
        curB = curB->next;
        //see if common node is reached
        if (curA == curB) {
            return curA;
        } else if (curA == NULL) {
            //start traversing from the beginning of listB
            curA = headB;
        } else if (curB == NULL) {
            //start traversing from the beginning of listA
            curB = headA;
        } else {
            //do nothing. we continue the traversal
        }
    }
    return NULL;
    }
};
