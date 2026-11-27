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
        using Node=ListNode;
        Node*fast=head;
        Node*slow=head;
        if(head==nullptr)return 0;
        if(head->next==nullptr&&n==1){
            delete head;
            return nullptr;
        }
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast == nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        while(fast->next!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        Node*temp=slow->next;
        slow->next=slow->next->next;
        delete temp;

        return head;

    }
};
