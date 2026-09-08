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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* lr = new ListNode();
        ListNode* head = lr;
        int digit;
        int carryout = 0;
        ListNode* temp_next;
        while(l1 != nullptr || l2 != nullptr) {
            if(l1 != nullptr && l2 == nullptr) {
                digit = l1->val + carryout;
            } else if(l1 == nullptr && l2 != nullptr) {
                digit = l2->val + carryout;
            } else {
                digit = l1->val + l2->val + carryout;
            }
            if(digit >= 10) {
                digit = digit % 10;
                carryout = 1;
            } else if (carryout == 1) {
                carryout = 0;
            }
            lr->val = digit;
            if(l1 != nullptr && l1->next != nullptr || l2 != nullptr && l2->next != nullptr) {
                temp_next = new ListNode();
                lr->next = temp_next;
                lr = lr->next;
            }
            if(l1 != nullptr) {
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                l2 = l2->next;
            }
        }
        if(carryout == 1) {
            temp_next = new ListNode(1);
            lr->next = temp_next;
        }
        return head;
    }
};