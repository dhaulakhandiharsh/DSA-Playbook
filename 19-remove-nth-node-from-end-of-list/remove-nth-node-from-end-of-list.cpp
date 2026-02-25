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
        if (!head) return nullptr;
        ListNode* temp = new ListNode(0);
        temp->next = head;

        ListNode* fast = temp;
        ListNode* slow = temp;

        for(int i=0; i<n; i++){
            fast = fast->next;
        }
       
        while(fast->next){
            slow = slow->next;
            fast = fast->next;   
        }

        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;

        return temp->next;
    }
};