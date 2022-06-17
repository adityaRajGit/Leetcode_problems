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
    ListNode* swapPairs(ListNode* head) 
    {
        if(!head) return NULL;
        ListNode temp(0);
        temp.next=head;
        ListNode *b=&temp,*f=head;
        while(f && f->next)
        {
            b->next=f->next;
            b=b->next;
            f->next=b->next;
            b->next=f;
            b=f;
            f=f->next;
        }
        
        return temp.next;
    }
};