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
        Node* fast=head;
        Node* slow=head;
        while(fast!=nullptr &&fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        Node*mid=slow;
        Node* curr=mid->next;
        mid->next=nullptr;
        Node* prev=nullptr;
        while(curr!=nullptr){
            Node*forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        Node*first=head;
        Node*second=prev;
        while(second!=nullptr){
            Node* temp1=first->next;
            Node* temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
        
    }
};
