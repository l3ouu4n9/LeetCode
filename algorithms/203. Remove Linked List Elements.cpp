/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;
        while(head -> val == val){
            head = head -> next;
            if(head == NULL) return head;
        }
        
        ListNode* ptr = head;
        while(ptr -> next != NULL){
            while(ptr -> next -> val == val){
                ptr -> next = ptr -> next -> next;
                if(ptr -> next == NULL) return head;
            }
            ptr = ptr -> next;
        }
        return head;
    }
};
