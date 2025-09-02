/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //we will first replace the node with its next value
        node -> val = node -> next -> val;
        
        //we will skip the the replace value by making them same
        node -> next = node -> next -> next;
    }
};