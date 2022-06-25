/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *ptr = head, *tmp_next, *runner;
        while (ptr) {
            if (ptr->child) {
                tmp_next = ptr->next;
                ptr->next = ptr->child;
                ptr->next->prev = ptr;
                ptr->child = NULL;
                runner = ptr->next;
                while (runner->next) runner = runner->next;
                runner->next = tmp_next;
                if (runner->next) runner->next->prev = runner;
            }
            ptr = ptr->next;
        }
        return head;
    }
    
};