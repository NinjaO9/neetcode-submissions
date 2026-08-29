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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;
        while (temp != nullptr)
        {
            temp = temp->next;
            size++;
        }

        ListNode* prev = nullptr;
        ListNode* cur = head;
        for (int i = 0; i < size - n; i++)
        {
            prev = cur;
            cur = cur->next;
        }

        if (cur) 
        {
            if (prev) prev->next = cur->next;
            else head = cur->next;
        }
        else prev->next = nullptr;
        delete(cur);
        return head;
    }
};
