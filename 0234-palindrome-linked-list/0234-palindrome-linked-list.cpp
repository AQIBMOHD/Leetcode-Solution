/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    
        if(head == NULL ||head->next == NULL){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        //find middle of linkedlist
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            
        }
        //reverse the right half
        slow->next=reverselist(slow->next);
        
        //move slow to right half
        slow=slow->next;
        
        //now check left half and right half are equal or not
        while(slow!=NULL){
            
            if(head->val!=slow->val)
            return false;
            head=head->next;
            slow=slow->next;
            
            }
            return true;
        
    }
    ListNode* reverselist (ListNode* head){
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
            
        }
        return prev;
        
    }

};