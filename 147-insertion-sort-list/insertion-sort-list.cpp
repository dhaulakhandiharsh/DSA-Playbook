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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0); // dummy head for sorted part
        dummy->next = head;

        ListNode* lastSorted = head; // last node in sorted portion
        ListNode* curr = head->next; // current node to insert

        while (curr) {
            if (curr->val >= lastSorted->val) {
                
                lastSorted = curr;
            } else {
                
                ListNode* prev = dummy;
                while (prev->next->val < curr->val) {
                    prev = prev->next;
                }

                
                lastSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = lastSorted->next;
        }

        return dummy->next;
    }
};