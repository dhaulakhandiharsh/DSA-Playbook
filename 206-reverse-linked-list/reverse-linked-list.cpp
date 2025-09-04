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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* front = nullptr;

        while(temp != nullptr){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
};