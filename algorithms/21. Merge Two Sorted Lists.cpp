/*
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.

E.g.
  Input: 1->2->4, 1->3->4
  Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* pos;
        ListNode* start;
        if(l1 == NULL || l2 == NULL){
            if(l1 == NULL)return l2;
            else return l1;
        }else{
            if(l1 -> val > l2 -> val){
                start = l2;
                pos = l2;
                if(pos -> next == NULL){
                    pos -> next = l1;
                    return start;
                }
                else l2 = l2 -> next;
            }else{
                start = l1;
                pos = l1;
                if(pos -> next == NULL){
                    pos -> next = l2;
                    return start;
                }
                else l1 = l1 -> next;
            }
            while(true){
                if(l1 -> val > l2 -> val){
                    pos -> next = l2;
                    pos = l2;
                    if(pos -> next == NULL)break;
                    else l2 = l2 -> next;
                }else{
                    pos -> next = l1;
                    pos = l1;
                    if(pos -> next == NULL)break;
                    else l1 = l1 -> next;
                }
            }
            if(pos == l1)pos -> next = l2;
            else pos -> next = l1;
            
            return start;
        }
    }
};
