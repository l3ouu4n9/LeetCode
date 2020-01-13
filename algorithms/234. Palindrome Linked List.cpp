/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL) return true;
        
        ListNode* fast_ptr = head;
        ListNode* slow_ptr = head;
        
        while(fast_ptr -> next != NULL && fast_ptr -> next -> next != NULL){
            slow_ptr = slow_ptr -> next;
            fast_ptr = fast_ptr -> next -> next;
        }
        slow_ptr = slow_ptr -> next;
        
        ListNode* prev_ptr = NULL;
        ListNode* curr_ptr = slow_ptr;
        ListNode* next_ptr = slow_ptr -> next;
        while(next_ptr != NULL){
            curr_ptr -> next = prev_ptr;
            prev_ptr = curr_ptr;
            curr_ptr = next_ptr;
            next_ptr = next_ptr -> next;
        }
        curr_ptr -> next = prev_ptr;
        
        while(curr_ptr != NULL){
            if(curr_ptr -> val != head -> val) return false;
            else{
                curr_ptr = curr_ptr -> next;
                head = head -> next;
            }
        }
        return true;
    }
};
