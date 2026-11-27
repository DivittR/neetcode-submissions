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
        using Node=ListNode;
        Node* slow=head;
        Node* fast=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node* middle=slow;
        Node*curr=middle->next;
        middle->next=nullptr;
        Node*prev=nullptr;
        while(curr!=nullptr){
            Node*forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        Node*first=head;
        Node*second=prev;
        while(second!=nullptr){
            Node*temp1=first->next;
            Node*temp2=second->next;
            first->next=second;
            second->next=temp1;

            first=temp1;
            second=temp2;
        }
        
    }
};
