/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;
        // 1) create interleaved copied nodes
        while (curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // 2) assign random pointers for copies
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // 3) detach copied list from original
        Node* pseudoHead = new Node(0);
        Node* copy = pseudoHead;
        curr = head;
        while (curr) {
            copy->next = curr->next;
            curr->next = curr->next->next;
            copy = copy->next;
            curr = curr->next;
        }

        Node* result = pseudoHead->next;
        delete pseudoHead;
        return result;
    }
};