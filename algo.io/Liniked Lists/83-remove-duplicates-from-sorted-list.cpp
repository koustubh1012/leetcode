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

#include <iostream>
#include <vector>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

using namespace std;
 
class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            auto current = head;
            if(head == nullptr){
                return head;
            }
            while(head->next != nullptr){
                auto next_node = head->next;
                if(head->val == next_node->val){
                    head->next = next_node->next;
                }
                else{
                    head = head->next;
                }
            }
            return current;
        }
    };

ListNode* createList(std::vector<int> values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int value : values) {
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    Solution solution;

    // Create a sorted linked list with duplicates
    std::vector<int> values = {1, 1, 2, 3, 3};
    ListNode* head = createList(values);

    std::cout << "Original list: ";
    printList(head);

    // Remove duplicates
    ListNode* newHead = solution.deleteDuplicates(head);

    std::cout << "List after removing duplicates: ";
    printList(newHead);

    return 0;
}
