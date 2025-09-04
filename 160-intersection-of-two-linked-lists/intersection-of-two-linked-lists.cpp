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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;

        ListNode* A = headA;
        ListNode* B = headB;

        while(A != B){
            //A = (A) ? A->next : headB;


            if(A!=nullptr){
                A = A->next;
            }else{
                A = headB;
            }
            if(B!=nullptr){
                B = B->next;
            }else{
                B = headA;
            }

            






            //B = (B) ? B->next : headA;
        }
        return A;
    }
};