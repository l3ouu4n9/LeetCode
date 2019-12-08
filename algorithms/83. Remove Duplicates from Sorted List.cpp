/*

Given a sorted linked list, delete all duplicates such that each element appear only once.

E.g.

  Input: 1->1->2
  Output: 1->2
  
  Input: 1->1->2->3->3
  Output: 1->2->3

*/

**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* new_list = head;
        ListNode* ptr = head;
        if(head == NULL) return NULL;
        else{
            while(ptr -> next != NULL){
                ptr = ptr -> next;
                if(ptr -> val != new_list -> val){
                    cout << new_list -> val << endl;
                    new_list -> next = ptr;
                    new_list = ptr;
                }
            }
            new_list -> next = NULL;
        }
        return head;
    }
};
