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
        if(!head) return nullptr;

        Node* current = head;

        unordered_map<Node*, Node*> oldToNew;

        while(current != nullptr){
            Node* new_node = new Node(current->val);
            oldToNew[current] = new_node;
            current = current->next;
        }

        current = head;

        while(current != nullptr){
            oldToNew[current]->next = oldToNew[current->next];
            oldToNew[current]->random = oldToNew[current->random];
            current = current->next;
        }

        return oldToNew[head];
    }
};
