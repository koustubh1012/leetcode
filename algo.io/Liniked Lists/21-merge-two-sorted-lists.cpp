#include <iostream>
#include <vector>

using namespace std;

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            // Handle edge case
            if(list1 == nullptr && list2 == nullptr) return list1;
    
    
            // Initilise head of merged linkedlist
            ListNode head(0);
            ListNode* current = &head;
    
            // Iterate through elements
            while(list1 != nullptr && list2 != nullptr){    
                // Compare next elements
                if (list1->val < list2->val){
                    current->next = list1;
                    list1 = list1->next;
                }
                else{
                    current->next = list2;
                    list2 = list2->next;
                }
                current = current->next;
            }
            current->next = (list1 != nullptr) ? list1 : list2;
            return head.next;
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
    Solution sol;
    std::vector<int> values1 = {1, 2, 4};
    std::vector<int> values2 = {1, 3, 4};

    ListNode* list1 = createList(values1);
    ListNode* list2 = createList(values2);

    ListNode* mergedList = sol.mergeTwoLists(list1, list2);

    std::cout << "Merged List: ";
    printList(mergedList);

    // Clean up memory
    delete list1;
    delete list2;
    delete mergedList;

    return 0;
}
