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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* prev = head;
        while(prev->next != slow){
            prev = prev->next;
        }

        prev->next = slow->next;
        delete slow;

        return head;


    }
};