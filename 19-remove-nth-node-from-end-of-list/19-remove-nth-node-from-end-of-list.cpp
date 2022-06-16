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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     ListNode *h1=head, *h2=head;
    while(n-->0) h2=h2->next;
    if(h2==NULL) return head->next;  // The head need to be removed, do it.
    h2=h2->next;
    
    while(h2!=NULL){
        h1=h1->next;
        h2=h2->next;
    }
    h1->next=h1->next->next;   // the one after the h1 need to be removed
    return head;
        
    }
};