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

    // 1 2 3 4
    // 1 2 3 4 5
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;

        ListNode* prev = nullptr;
        while(true){
            ListNode* actualNext = head->next;
            head->next = prev;
            prev = head;
            if(actualNext == nullptr) break;
            head = actualNext;

        }
        return head;
    }
};
