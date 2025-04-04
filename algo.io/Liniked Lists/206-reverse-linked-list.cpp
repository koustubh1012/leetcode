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
        ListNode* reverseList(ListNode* head) {
            if(head == nullptr){
                return head;
            }
            ListNode* current = head;
            ListNode* prev = nullptr;
            while (current != nullptr){
                auto temp = current->next;
                current->next = prev;
                prev = current;
                current = temp;
            }
            return prev;
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
    std::vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);
    
    std::cout << "Original list: ";
    printList(head);
    
    ListNode* reversedHead = solution.reverseList(head);
    
    std::cout << "Reversed list: ";
    printList(reversedHead);
    
    return 0;
}

