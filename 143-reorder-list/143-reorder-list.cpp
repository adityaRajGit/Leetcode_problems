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
    void reorderList(ListNode* head) {
        if ((!head) || (!head->next) || (!head->next->next)) return; 
        stack<ListNode*> s;
        ListNode* p=head;
        int c=0;
        while(p!=NULL)
        {
            s.push(p);
            c++;
            p=p->next;
        }
        ListNode* ptr=head;
        for(int i=0;i<c/2;i++)
        {
            ListNode* temp=s.top();
            s.pop();
            temp->next=ptr->next;
            ptr->next=temp;
            ptr=ptr->next->next;
        }
        ptr->next=NULL;
    }
};